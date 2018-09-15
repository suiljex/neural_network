#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <vector>
#include <cstdlib>
#include <float.h>
#include <memory>

#include "Normalizer.hpp"
#include "ComputingUnit.hpp"

class NeuralNetwork
{
public:
  NeuralNetwork()
  {
    default_normalizer.SetLimits(-20, 20);
  }

  int ProcessData();
  int AddData(std::vector<double>& i_data);
  int AddData(std::vector<double>& i_data, double i_expected_result);
  int InitNeuralNetworkRandType1(std::vector<std::shared_ptr<NeuronBase>> i_input_neurons, std::vector<int> i_network_config)
  {
    input_data.clear();
    for (unsigned int i = 0; i < i_input_neurons.size(); ++i)
    {
      std::vector<double> temp_data_for_input_neuron;
      input_data.push_back(temp_data_for_input_neuron);
    }

    return computing_unit.InitNeuralNetworkRandType1(i_input_neurons, i_network_config);
  }
  int GetInputNeuronsAmount()
  {
    return computing_unit.GetInputNeuronsAmount();
  }
  std::vector<double> GetResults()
  {
    std::vector<double> temp_results;
    temp_results = results;
    default_normalizer.NormalizeDataUp(temp_results);
    return temp_results;
  }
  std::vector<double> GetErrors()
  {
    std::vector<double> temp_result;
    temp_result = errors;
    default_normalizer.NormalizeDataUp(temp_result);
    return temp_result;
  }

protected:

  ComputingUnit computing_unit;
  Normalizer default_normalizer;

  std::vector<std::vector<double>> input_data;

  std::vector<double> expected_results;
  std::vector<double> results;

  std::vector<double> errors;
};


#endif // NEURALNETWORK_HPP
