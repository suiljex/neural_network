#include <iostream>
#include "NeuralNetwork.hpp"
#include "DataParser.hpp"

using namespace std;

int main(int /*argc*/, char **/*argv*/)
{
  NeuralNetwork n_net;
  DataParser d_parser;

  std::string input_file("input_data");
  d_parser.SetFilenameInput(input_file);

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
  d_parser.InputFileParse(n_net);
  result = n_net.ProcessData();

  return 0;
}
