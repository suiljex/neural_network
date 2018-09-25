#include "StorageUnit.hpp"

StorageUnit::StorageUnit()
{
  results.normalizer.SetLimits(0, 200);
}

int StorageUnit::InitInputLevels(int i_levels)
{
  input_data.clear();
  for (int i = 0; i < i_levels; ++i)
  {
    DB new_level;
    input_data.push_back(new_level);
  }
  return 0;
}

std::vector<double> StorageUnit::GetInputDataByIndex(int i_index)
{
  int temp_i;
  int temp_i_max = input_data.size();
  int temp_j_max = input_data[0].data.size();

  std::vector<double> temp_input_data;

  if (i_index < temp_j_max)
  {
    for (temp_i = 0; temp_i < temp_i_max; ++temp_i)
    {
      temp_input_data.push_back(input_data[temp_i].normalizer.NormalizeSingleDataDown(input_data[temp_i].data[i_index]));
    }
  }

  return temp_input_data;
}

double StorageUnit::GetExpectedResultByIndex(int i_index)
{
  double temp_expected_result = 0;
  if (i_index < expected_results.size())
  {
    temp_expected_result = expected_results[i_index];
  }

  return temp_expected_result;
}

int StorageUnit::AddData(std::vector<double> &i_data, double i_expected_result)
{
  expected_results.push_back(i_expected_result);
  if (input_data.size() == i_data.size())
  {
    for (unsigned int i = 0; i < input_data.size(); ++i)
    {
      input_data[i].data.push_back(i_data[i]);
    }
  }
  return 0;
}

int StorageUnit::AddResult(double i_result)
{
  results.data.push_back(i_result);
  return 0;
}

int StorageUnit::ResetResults()
{
  results.data.clear();
  errors.clear();
  return 0;
}

std::vector<double> StorageUnit::GetResults()
{
  DB ret = results;
  ret.NormalizeUp();
  return ret.data;
}

std::vector<double> StorageUnit::GetErrors()
{
  errors.clear();
  double result;
  DB temp_results = results;
  temp_results.NormalizeUp();
  if (temp_results.data.size() == expected_results.size())
  {
    for (unsigned int i = 0; i < temp_results.data.size(); ++i)
    {
      result = abs(temp_results.data[i] - expected_results[i]);
      errors.push_back(result);
    }
  }
  return errors;
}

std::vector<double> StorageUnit::GetExpResults()
{
  return expected_results;
}

std::vector<DB> StorageUnit::GetInputData()
{
  return input_data;
}

int StorageUnit::CalculateLimits()
{
  for (auto it = input_data.begin(); it != input_data.end(); ++it)
  {
    it->CalculateLimits();
  }
  return 0;
}

DataBoundle::DataBoundle()
{

}

int DataBoundle::NormalizeDown()
{
  return normalizer.NormalizeDataDown(data);
}

int DataBoundle::NormalizeUp()
{
  return normalizer.NormalizeDataUp(data);
}
