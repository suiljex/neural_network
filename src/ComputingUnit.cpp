#include "ComputingUnit.hpp"

ComputingUnit::ComputingUnit()
{

}

double ComputingUnit::Process()
{
  double result = 0;

  int i = 0;
  int j = 0;

  int max_i = levels.size();
  int max_j;

  for (i = 0; i < max_i; ++i)
  {
    max_j = levels[i].size();
    for (j = 0; j < max_j; ++j)
    {
      levels[i][j]->Process();
    }
  }

  result = levels[i - 1][j - 1]->GetResult();

  return result;
}

int ComputingUnit::InitNeuralNetworkRandType1(std::vector<std::shared_ptr<NeuronBase>> i_input_neurons, std::vector<int> i_network_config)
{
  std::vector<std::shared_ptr<NeuronBase>> pointers;
  int temp_i;
  //int temp_j;

  input_neurons = i_input_neurons;

  std::vector<std::shared_ptr<NeuronBase>>::iterator ik = i_input_neurons.begin();
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
      std::shared_ptr<NeuronBase> new_neuron(new NeuronHidden);

      std::vector<std::shared_ptr<NeuronBase>>::iterator ij = pointers.begin();
      for (; ij != pointers.end(); ++ij)
      {
        NConnection new_connection;
        new_connection.source_pointer = *ij;
        new_connection.weight = RandGenWeight();

        new_neuron->AddConnection(new_connection);
      }

      levels[temp_i].push_back(new_neuron);
    }

    pointers.clear();

    std::vector<std::shared_ptr<NeuronBase>>::iterator il = levels[temp_i].begin();
    for (; il != levels[temp_i].end(); ++il)
    {
      pointers.push_back(*il);
    }
  }

  LevelAdd();
  temp_i = levels.size() - 1;

  std::shared_ptr<NeuronBase> output_neuron(new NeuronOutput);

  std::vector<std::shared_ptr<NeuronBase>>::iterator im = pointers.begin();
  for (; im != pointers.end(); ++im)
  {
    NConnection new_connection;
    new_connection.source_pointer = *im;
    new_connection.weight = RandGenWeight();

    output_neuron->AddConnection(new_connection);
  }

  levels[temp_i].push_back(output_neuron);

  return 0;
}

int ComputingUnit::AddDataToInput(std::vector<double>& i_data)
{
  if (input_neurons.size() == i_data.size())
  {
    for (unsigned int i = 0; i < input_neurons.size(); ++i)
    {
      input_neurons[i]->SetResult(i_data[i]);
    }
  }
  return 0;
}

unsigned int ComputingUnit::GetInputNeuronsAmount()
{
  return input_neurons.size();
}

int ComputingUnit::LevelAdd()
{
  std::vector<std::shared_ptr<NeuronBase>> new_level;
  levels.push_back(new_level);

  return 0;
}

int ComputingUnit::LevelDel()
{
  levels.pop_back();
  return 0;
}

double ComputingUnit::RandGenWeight()
{
  double temp_min = 5;
  double temp_max = -5;
  double part_first;
  double result;

  part_first = (double) rand() / (RAND_MAX);
  result = temp_min + part_first * (temp_max - temp_min);
  return result;
}

