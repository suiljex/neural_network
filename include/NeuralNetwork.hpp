#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <vector>
#include <cstdlib>
#include <memory>
#include "NeuronBase.hpp"
#include "NeuronInput.hpp"
#include "NeuronOutput.hpp"
#include "NeuronHidden.hpp"


class NeuralNetwork
{
public:
  NeuralNetwork();
  double Process();
  int InitNeuralNetworkRandType1(std::vector<std::shared_ptr<NeuronBase>> i_input_neurons, std::vector<int> i_network_config);

protected:
  int LevelAdd();
  int LevelDel();
  double RandGenWeight();

  std::vector<std::vector<std::shared_ptr<NeuronBase>>> levels;
};

#endif // NEURALNETWORK_HPP
