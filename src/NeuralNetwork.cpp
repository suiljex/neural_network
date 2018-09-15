#include "NeuralNetwork.hpp"

#include <math.h>

int NeuralNetwork::ProcessData()
{
  int temp_i;
  int temp_j;
  int temp_i_max = input_data.size();
  int temp_j_max = input_data[0].size();


  double result = 0;

  for (temp_j = 0; temp_j < temp_j_max; ++temp_j)
  {
    std::vector<double> temp_input_data;
    for (temp_i = 0; temp_i < temp_i_max; ++temp_i)
    {
      temp_input_data.push_back(input_data[temp_i][temp_j]);
    }

    default_normalizer.NormalizeDataDown(temp_input_data);
    computing_unit.AddDataToInput(temp_input_data);

    result = computing_unit.Process();
    results.push_back(result);
  }

  if (results.size() == expected_results.size())
  {
    for (unsigned int i = 0; i < results.size(); ++i)
    {
      result = abs(results[i] - expected_results[i]);
      errors.push_back(result);
    }
  }

  return 0;
}


int NeuralNetwork::AddData(std::vector<double>& i_data)
{
  if (input_data.size() == i_data.size())
  {
    for (unsigned int i = 0; i < input_data.size(); ++i)
    {
      input_data[i].push_back(i_data[i]);
    }
  }
  return 0;
}

int NeuralNetwork::AddData(std::vector<double>& i_data, double i_expected_result)
{
  AddData(i_data);
  expected_results.push_back(i_expected_result);

  return 0;
}

