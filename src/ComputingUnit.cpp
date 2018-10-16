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

double ComputingUnit::Train(double i_exp_res)
{
  double result = 0;

  result = Process();

  int i = 0;
  int j = 0;

  int max_i = levels.size();
  int max_j;

  for (i = max_i - 1; i >= 0; --i)
  {
    max_j = levels[i].size();
    for (j = max_j - 1; j >= 0; --j)
    {
      levels[i][j]->CalculateGradient(i_exp_res);
    }
  }

  max_i = levels.size();

  for (i = 0; i < max_i; ++i)
  {
    max_j = levels[i].size();
    for (j = 0; j < max_j; ++j)
    {
      levels[i][j]->UpdateWeights();
    }
  }

  return result;
}

int ComputingUnit::InitNeuralNetworkRandType1(std::vector<NeuronBase*> i_input_neurons, std::vector<int> i_network_config)
{
  std::vector<NeuronBase*> pointers;
  int temp_i;
  //int temp_j;

  input_neurons = i_input_neurons;

  std::vector<NeuronBase*>::iterator ik = i_input_neurons.begin();
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

      for (auto ij = pointers.begin(); ij != pointers.end(); ++ij)
      {
        std::shared_ptr<NConnection> new_connection(new NConnection);

        new_connection->ptr_src = *ij;
        new_connection->weight = RandGenWeight();

        new_neuron->AddConnection(new_connection.get());
        connections.push_back(new_connection);
      }

      levels[temp_i].push_back(new_neuron);
    }

    pointers.clear();

    for (auto il = levels[temp_i].begin(); il != levels[temp_i].end(); ++il)
    {
      pointers.push_back(il->get());
    }
  }

  LevelAdd();
  temp_i = levels.size() - 1;

  std::shared_ptr<NeuronBase> output_neuron(new NeuronOutput);

  for (auto im = pointers.begin(); im != pointers.end(); ++im)
  {
    std::shared_ptr<NConnection> new_connection(new NConnection);

    new_connection->ptr_src = *im;
    new_connection->weight = RandGenWeight();

    output_neuron->AddConnection(new_connection.get());
    connections.push_back(new_connection);
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

