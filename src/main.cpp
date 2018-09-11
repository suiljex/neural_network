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

  double result = 0;
  std::vector<double> data;

  vector<int> config;
  config.push_back(2);
  config.push_back(4);
  config.push_back(3);
  config.push_back(1);

  n_net.InitNeuralNetworkRandType1(input_neurons, config);
  data.clear();
  data.push_back(106);
  data.push_back(123);
  n_net.AddData(data);
  data.clear();
  data.push_back(23);
  data.push_back(2);
  n_net.AddData(data);
  data.clear();
  data.push_back(45);
  data.push_back(75);
  n_net.AddData(data);
  data.clear();
  data.push_back(2);
  data.push_back(176);
  n_net.AddData(data);

  n_net.CalculateNormRatio();
  result = n_net.ProcessData();

  return 0;
}
