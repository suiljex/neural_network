#include "NeuralNetwork.hpp"

#include <math.h>

NeuralNetwork::NeuralNetwork()
{

}

int NeuralNetwork::ProcessData()
{
  double result = 0;
  int index = 0;
  std::vector<double> temp_input_data;

  temp_input_data = storage_unit.GetInputDataByIndex(index);
  while (temp_input_data.size() == computing_unit.GetInputNeuronsAmount())
  {
    computing_unit.AddDataToInput(temp_input_data);
    result = computing_unit.Process();
    storage_unit.AddResult(result);

    temp_input_data = storage_unit.GetInputDataByIndex(++index);
  }

  return 0;
}

int NeuralNetwork::AddData(std::vector<double>& i_data, double i_expected_result)
{
  storage_unit.AddData(i_data, i_expected_result);
  return 0;
}

int NeuralNetwork::InitNeuralNetworkRandType1(std::vector<std::shared_ptr<NeuronBase> > i_input_neurons, std::vector<int> i_network_config)
{
  storage_unit.InitInputLevels(i_input_neurons.size());
  computing_unit.InitNeuralNetworkRandType1(i_input_neurons, i_network_config);
  return 0;
}

int NeuralNetwork::GetInputNeuronsAmount()
{
  return computing_unit.GetInputNeuronsAmount();
}

std::vector<double> NeuralNetwork::GetResults()
{
  return storage_unit.GetResults();
}

std::vector<double> NeuralNetwork::GetErrors()
{
  return storage_unit.GetErrors();
}

