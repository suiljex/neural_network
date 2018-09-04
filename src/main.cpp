#include <iostream>
#include <NeuralNetwork.hpp>

using namespace std;

int main(int /*argc*/, char **/*argv*/)
{
  NeuralNetwork n_net;
  vector<Neuron*> input_neurons;
  Neuron input_1;
  Neuron input_2;
  input_neurons.push_back(&input_1);
  input_neurons.push_back(&input_2);

  double result;

  vector<int> config;
  config.push_back(2);
  config.push_back(4);
  config.push_back(3);
  //config.push_back(1);

  n_net.InitNeuralNetworkRandType1(input_neurons, config);
  input_1.ForceSetResult(100);
  input_2.ForceSetResult(100);
  result = n_net.Process();

  return 0;
}
