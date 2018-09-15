#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <vector>
#include <cstdlib>
#include <float.h>
#include <memory>
#include "NeuronBase.hpp"
#include "NeuronInput.hpp"
#include "NeuronOutput.hpp"
#include "NeuronHidden.hpp"
#include "Normalizer.hpp"

typedef struct DataBundle
{
public:
  DataBundle();

  std::vector<double> data;
  Normalizer normalizer;

} DBundle;

struct DataStorage
{
public:
  DataStorage();

  std::vector<std::vector<DBundle>> input_data;
  std::vector<DBundle> results;
  std::vector<double> expected_results;
};

class NeuralNetwork
{
public:
  NeuralNetwork();
  double Process();
  int ProcessData();
  int InitNeuralNetworkRandType1(std::vector<std::shared_ptr<NeuronBase>> i_input_neurons, std::vector<int> i_network_config);
  int AddData(std::vector<double>& i_data);
  int AddData(std::vector<double>& i_data, double i_expected_result);
  int GetInputNeuronsAmount()
  {
    return input_neurons.size();
  }

  std::vector<double> GetResults()
  {
    return results;
  }
  std::vector<double> GetErrors()
  {
    return errors;
  }

protected:
  int LevelAdd();
  int LevelDel();
  double RandGenWeight();

  std::vector<std::vector<std::shared_ptr<NeuronBase>>> levels;
  std::vector<std::shared_ptr<NeuronBase>> input_neurons;

  std::vector<std::vector<double>> input_data;
  std::vector<Normalizer> input_data_normalizers;

  std::vector<double> expected_results;
  std::vector<double> results;
  Normalizer results_normalizer;

  std::vector<double> errors;
};

#endif // NEURALNETWORK_HPP
