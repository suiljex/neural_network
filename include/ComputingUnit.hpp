#ifndef COMPUTINGUNIT_HPP
#define COMPUTINGUNIT_HPP

#include <vector>
#include <memory>
#include "NeuronBase.hpp"
#include "NeuronInput.hpp"
#include "NeuronOutput.hpp"
#include "NeuronHidden.hpp"

class ComputingUnit
{
public:
  ComputingUnit();
  double Process();
  int InitNeuralNetworkRandType1(std::vector<std::shared_ptr<NeuronBase>> i_input_neurons, std::vector<int> i_network_config);
  int AddDataToInput(std::vector<double>& i_data);
  int GetInputNeuronsAmount()
  {
    return input_neurons.size();
  }

protected:
  int LevelAdd();
  int LevelDel();
  double RandGenWeight();

  std::vector<std::vector<std::shared_ptr<NeuronBase>>> levels;
  std::vector<std::shared_ptr<NeuronBase>> input_neurons;
};

#endif // COMPUTINGUNIT_HPP
