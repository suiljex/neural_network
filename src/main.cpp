#include <iostream>
#include "NeuralNetwork.hpp"
#include "DataParser.hpp"

using namespace std;

int main(int /*argc*/, char **/*argv*/)
{
  NeuralNetwork n_net;
  DataParser d_parser;

  std::string input_file("test_data.txt");
  d_parser.SetFilenameInput(input_file);

  vector<std::shared_ptr<NeuronBase>> input_neurons;
  std::shared_ptr<NeuronBase> input_1(new NeuronInput);
  std::shared_ptr<NeuronBase> input_2(new NeuronInput);
  input_neurons.push_back(input_1);
  input_neurons.push_back(input_2);

  std::vector<double> data;
  std::vector<double> errors;
  std::vector<DB> in_data;
  std::vector<double> exp_res;
  double error_m = 0;

  vector<int> config;
  config.push_back(3);
  config.push_back(2);
  //config.push_back(3);
  //config.push_back(2);

  n_net.InitNeuralNetworkRandType1(input_neurons, config);
  d_parser.InputFileParse(n_net);

  int max_steps = 100;
  for (int step = 0; step < max_steps; ++step)
  {
    n_net.TrainNetwork();
    data = n_net.GetResults();
    errors = n_net.GetErrors();
    error_m = n_net.GetErrorM();
    exp_res = n_net.GetExpResults();
    in_data = n_net.GetInputData();

#define LESS_OUTPUT
#ifndef LESS_OUTPUT
    std::vector<double> temp_in;
    for (unsigned int i = 0; i < data.size(); ++i)
    {
      temp_in = n_net.GetInputDataByIndex(i);
      cout << step << "@ ";
      for (unsigned int j = 0; j < temp_in.size(); ++j)
      {
        cout << temp_in[j];
        if (j + 1 != temp_in.size())
        {
          cout << "|";
        }
        else
        {
          cout << ":";
        }
      }
      cout << exp_res[i] << " (" << data[i] << ")" << " [" << errors[i] << "]" << endl;
    }
#endif
    cout << step << "@ {" << error_m << "}"  << endl;
  }
  return 0;
}
