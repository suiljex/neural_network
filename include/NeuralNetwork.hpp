#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <vector>
//#include <cstdlib>
//#include <float.h>
#include <memory>

#include "ComputingUnit.hpp"
#include "StorageUnit.hpp"

class NeuralNetwork
{
public:

  NeuralNetwork();

  int ProcessData();

  int TrainNetwork();

  int AddData
  (
      std::vector<double>& i_data
  );

  int AddData
  (
      std::vector<double>& i_data
    , double i_expected_result
  );

  int InitNeuralNetworkRandType1
  (
      std::vector<std::shared_ptr<NeuronBase>> i_input_neurons
    , std::vector<int> i_network_config
  );

  int GetInputNeuronsAmount();

  std::vector<double> GetResults();

  std::vector<double> GetErrors();

  double GetErrorM();

  std::vector<double> GetExpResults();

  std::vector<DB> GetInputData();

  std::vector<double> GetInputDataByIndex
  (
      int i_index
  );

protected:

  ComputingUnit computing_unit;
  StorageUnit storage_unit;
};




#endif // NEURALNETWORK_HPP
