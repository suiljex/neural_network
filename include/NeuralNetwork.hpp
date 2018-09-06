#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <vector>
#include <cstdlib>
#include "Neuron.hpp"


class NeuralNetwork
{
public:
  NeuralNetwork();
  double Process();
  int InitNeuralNetworkRandType1(std::vector<Neuron*> i_input_neurons, std::vector<int> i_network_config);

protected:
  int LevelAdd();
  int LevelDel();

  std::vector<std::vector<Neuron>> levels;
};

#endif // NEURALNETWORK_HPP
