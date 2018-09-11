#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <vector>
#include <cstdlib>
#include <float.h>
#include <memory>
#include "NeuronBase.hpp"
#include "NeuronInput.hpp"
#include "NeuronOutput.hpp"
#include "NeuronHidden.hpp"

typedef struct MinimumMaximux
{
  MinimumMaximux()
  {
    minimum = 0;
    maximum = 0;
  }
  MinimumMaximux(double i_min, double i_max)
  {
    minimum = i_min;
    maximum = i_max;
  }
  double minimum;
  double maximum;
} MinMax;

class NeuralNetwork
{
public:
  NeuralNetwork();
  double Process();
  int ProcessData();
  int InitNeuralNetworkRandType1(std::vector<std::shared_ptr<NeuronBase>> i_input_neurons, std::vector<int> i_network_config);
  int AddData(std::vector<double>& i_data);
  int CalculateNormRatio();

  //int SetInputData()

protected:
  int LevelAdd();
  int LevelDel();
  double RandGenWeight();
  double Normalize(double i_data, MinMax& i_min_max);

  std::vector<std::vector<std::shared_ptr<NeuronBase>>> levels;
  std::vector<std::shared_ptr<NeuronBase>> input_neurons;
  std::vector<std::vector<double>> input_data;
  std::vector<double> results;
  std::vector<MinMax> min_max;

};

#endif // NEURALNETWORK_HPP
