#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork()
{

}

double NeuralNetwork::Process()
{
  double result;

  int i = 0;
  int j = 0;

  int max_i = levels.size();
  int max_j;

  for (i = 0; i < max_i; ++i)
  {
    max_j = levels[i].size();
    for (j = 0; j < max_j; ++j)
    {
      levels[i][j].Process();
    }
  }

  result = levels[i - 1][j - 1].GetResult();

  return result;
}

int NeuralNetwork::InitNeuralNetworkRandType1(std::vector<Neuron *> i_input_neurons, std::vector<int> i_network_config)
{
  std::vector<Neuron*> pointers;
  int temp_i;
  //int temp_j;

  std::vector<Neuron*>::iterator ik = i_input_neurons.begin();
  for (; ik != i_input_neurons.end(); ++ik)
  {
    pointers.push_back(*ik);
  }

  std::vector<int>::iterator it = i_network_config.begin();
  for (; it != i_network_config.end(); ++it)
  {
    LevelAdd();
    temp_i = levels.size() - 1;
    for (int i = 0; i < *it; ++i)
    {
      Neuron new_neuron;

      std::vector<Neuron*>::iterator ij = pointers.begin();
      for (; ij != pointers.end(); ++ij)
      {
        NConnection new_connection;
        new_connection.source_pointer = *ij;
        new_connection.weight = 0.5; //rand()/RAND_MAX;

        new_neuron.AddConnection(new_connection);
      }

      levels[temp_i].push_back(new_neuron);
    }

    pointers.clear();

    std::vector<Neuron>::iterator il = levels[temp_i].begin();
    for (; il != levels[temp_i].end(); ++il)
    {
      pointers.push_back(&*il);
    }
  }

  LevelAdd();
  temp_i = levels.size() - 1;

  Neuron output_neuron;

  std::vector<Neuron*>::iterator im = pointers.begin();
  for (; im != pointers.end(); ++im)
  {
    NConnection new_connection;
    new_connection.source_pointer = *im;
    new_connection.weight = 0.5;

    output_neuron.AddConnection(new_connection);
  }

  levels[temp_i].push_back(output_neuron);

  return 0;
}

int NeuralNetwork::LevelAdd()
{
  std::vector<Neuron> new_level;
  levels.push_back(new_level);

  return 0;
}

int NeuralNetwork::LevelDel()
{
  levels.pop_back();
  return 0;
}
