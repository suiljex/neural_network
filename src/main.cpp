#include <iostream>
#include <NeuralNetwork.hpp>

using namespace std;

int main(int /*argc*/, char **/*argv*/)
{
  NeuralNetwork n_net;
  vector<std::shared_ptr<NeuronBase>> input_neurons;
  std::shared_ptr<NeuronBase> input_1(new NeuronInput);
  std::shared_ptr<NeuronBase> input_2(new NeuronInput);
  input_neurons.push_back(input_1);
  input_neurons.push_back(input_2);

  double result;

  vector<int> config;
  config.push_back(3);
  //config.push_back(4);
  //config.push_back(3);
  //config.push_back(1);

  n_net.InitNeuralNetworkRandType1(input_neurons, config);
  input_1->SetResult(100);
  input_2->SetResult(100);
  result = n_net.Process();

  return 0;
}
