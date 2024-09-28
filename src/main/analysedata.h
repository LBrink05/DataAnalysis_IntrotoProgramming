#ifndef ANALYSEDATA_H
#define ANALYSEDATA_H
//to compile: g++ -o main -no-pie ../src/main/main.cpp -lboost_serialization
//RECOMMENDED: compile with cmake using 'cmake --build build && ./build/DataAnalysis' in the DATAANALYSISINTROTOPROGRAMMING directory (no subdirectory)
//standard libs
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
//for timekeeping and pausing
#include <chrono>
#include <thread>
//for serialization
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/binary_object.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/vector.hpp>

#include "particle_classes.h"
#include "serialization.h"
#include "readandcalc.h"

double stdDeviation(std::vector<double> Sample, float mean){
  float sum = 0;
    for (int number = 0; number < Sample.size(); number++) {
      sum += std::pow((Sample[number] - mean), 2);
    }
  return (double)(std::sqrt(sum / Sample.size()));
}

//Function to calculate certain averages etc from particle events
Analysed_Data Analyse_Data(raw_Data raw_Data, Analysed_Data Analysed_Data){

  //Gathering overall count of Omega particles in 5 million collisions
  Analysed_Data.Omegaminus_count = 0;
  Analysed_Data.Omegaplus_count = 0;
  Analysed_Data.Omega_event_equal_amount_count = 0;

  //used to calculate amount per event
  uint32_t Omega_minus_per_event_count = 0;
  uint32_t Omega_plus_per_event_count = 0;

  //sample vars
  int sample = 0;
  int past_sample_events = 0;
  int past_Omega_minus_count = 0;
  double Sample_Omega_minus_mean = 0;
  std::vector<double> Sample_Omega_minus_mean_vector;
  int past_Omega_plus_count = 0;
  double Sample_Omega_plus_mean = 0;
  std::vector<double> Sample_Omega_plus_mean_vector;


    for (int event= 0; event < raw_Data.Particle_event_vector.size(); event++){
      for (int particle = 0; particle < raw_Data.Particle_event_vector[event].Particles.size(); particle++){
        if (abs(raw_Data.Particle_event_vector[event].Particles[particle].PGC) == 3334){

          //comparing particles on pseudorapidity and transverseP of Omega-minus by counting
          //raw_Data.Particle_total_count++; add this if all particles enabled to get particle count
          if (raw_Data.Particle_event_vector[event].Particles[particle].PGC == 3334){
            Analysed_Data.Omegaminus_count++;
            Omega_minus_per_event_count++;
          }
          else if (raw_Data.Particle_event_vector[event].Particles[particle].PGC == -3334){
            Analysed_Data.Omegaplus_count++;
            Omega_plus_per_event_count++;
          }
        }
      }

      //check for equal Omega plus and Omega minus count events
      if ((Omega_minus_per_event_count == Omega_plus_per_event_count) and ((Omega_minus_per_event_count != 0) or (Omega_plus_per_event_count != 0))){
        Analysed_Data.Omega_event_equal_amount_count++;
      }

      //calculting mean of each sample for Matter and Antimatter
      if (event < (raw_Data.Samplesizes[sample] + past_sample_events)){
        Sample_Omega_minus_mean +=  (Analysed_Data.Omegaminus_count - past_Omega_minus_count) / (double)raw_Data.Samplesizes[sample];
        Sample_Omega_plus_mean +=  (Analysed_Data.Omegaplus_count - past_Omega_plus_count) / (double)raw_Data.Samplesizes[sample];
      }
      if ((event == (raw_Data.Samplesizes[sample] + past_sample_events)) or event == raw_Data.Particle_event_vector.size()-1){
        Sample_Omega_minus_mean_vector.push_back(Sample_Omega_minus_mean);
        Sample_Omega_plus_mean_vector.push_back(Sample_Omega_plus_mean);
        past_Omega_minus_count = Analysed_Data.Omegaminus_count;
        past_Omega_plus_count = Analysed_Data.Omegaplus_count;
        past_sample_events += raw_Data.Samplesizes[sample];
        sample++;
      }

      //reset variables per event
      Omega_minus_per_event_count = 0;
      Omega_plus_per_event_count = 0;
    }

  //calculations of mean and mean uncertainty of Omega minus
  
  Analysed_Data.Results.Omega_minus_mean = std::accumulate(Sample_Omega_minus_mean_vector.begin(), Sample_Omega_minus_mean_vector.end(), 0.0) / Sample_Omega_minus_mean_vector.size();
  Analysed_Data.Results.Omega_minus_mean_uncertainty = stdDeviation(Sample_Omega_minus_mean_vector, Analysed_Data.Results.Omega_minus_mean);
  
  Analysed_Data.Results.Omega_plus_mean = std::accumulate(Sample_Omega_plus_mean_vector.begin(), Sample_Omega_plus_mean_vector.end(), 0.0) / Sample_Omega_plus_mean_vector.size();
  Analysed_Data.Results.Omega_plus_mean_uncertainty = stdDeviation(Sample_Omega_plus_mean_vector, Analysed_Data.Results.Omega_plus_mean);
  
  //calculations done with information already gathered from raw_data
  Analysed_Data.Omega_Particle_total_count = Analysed_Data.Omegaminus_count + Analysed_Data.Omegaplus_count;
  //difference of matter to antimatter
  Analysed_Data.Omega_Particle_total_difference = Analysed_Data.Omegaminus_count - Analysed_Data.Omegaplus_count;


  return Analysed_Data;
}

//Function to display data
void Display_Data(Analysed_Data Analysed_Data, raw_Data raw_Data){
  
  std::cout << "\n";
  std::cout << "Total particle event count: " << raw_Data.Particle_event_vector.size() << "\n";
  std::cout << "Total amount of Omega-minus: " <<  Analysed_Data.Omegaminus_count << " and of Omega-plus: " << Analysed_Data.Omegaplus_count << "\n";
  std::cout << "Total amount of Omega-particles: " << Analysed_Data.Omega_Particle_total_count << "\n";
  std::cout << "Difference of total amount of Omega-particles: " << std::fixed << Analysed_Data.Omega_Particle_total_difference << "\n";
  std::cout << "Total amount of events with equal Omega-minus and Omega-plus (Not 0,0): " << std::fixed << Analysed_Data.Omega_event_equal_amount_count << "\n";
  std::cout << "Mean of Omega minus: " << std::fixed << Analysed_Data.Results.Omega_minus_mean << " +- " << Analysed_Data.Results.Omega_minus_mean_uncertainty << " (+-" << Analysed_Data.Results.Omega_minus_mean / Analysed_Data.Results.Omega_minus_mean_uncertainty << " Sigma)" << "\n";
  std::cout << "Mean of Omega plus: " << std::fixed << Analysed_Data.Results.Omega_plus_mean << " +- " << Analysed_Data.Results.Omega_plus_mean_uncertainty << " (+-" << Analysed_Data.Results.Omega_plus_mean / Analysed_Data.Results.Omega_plus_mean_uncertainty << " Sigma)"<< "\n";
  //std::cout << "Arithmetic mean of mean of Omega-particles per events per sample: " << std::fixed << Analysed_Data.sample_event_particle_mean << "\n";
  //std::cout << "Uncertainty: " << sqrt(Analysed_Data.Omegaminus_count) / (double)raw_Data.Particle_total_count<< "\n";
  std::cout << "\n";
}

#endif
