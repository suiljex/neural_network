#include "Normalizer.hpp"

Normalizer::Normalizer()
{

}

Normalizer::Normalizer(MinMax i_limits)
{
  limits = i_limits;
}

int Normalizer::SetLimits(MinMax i_limits)
{
  limits = i_limits;
  return 0;
}

int Normalizer::SetLimits(double i_min, double i_max)
{
  limits = MinMax(i_min, i_max);
  return 0;
}

int Normalizer::SetLimitMin(double i_min)
{
  limits.minimum = i_min;
  return 0;
}

int Normalizer::SetLimitMax(double i_max)
{
  limits.maximum = i_max;
  return 0;
}

MinMax Normalizer::GetLimits()
{
  return limits;
}

int Normalizer::CalculateLimits(std::vector<double> &i_data)
{
  double temp_data_min = DBL_MAX;
  double temp_data_max = -DBL_MAX;

  for (auto it = i_data.begin(); it != i_data.end(); ++it)
  {
    if ((*it) < temp_data_min)
    {
      temp_data_min = (*it);
    }
    if ((*it) > temp_data_max)
    {
      temp_data_max = (*it);
    }
  }

  limits = (MinMax(temp_data_min, temp_data_max));

  return 0;
}

int Normalizer::NormalizeDataDown(std::vector<double> &d_data)
{
  double temp_val;

  if (limits.maximum != DBL_MIN && limits.minimum != DBL_MAX)
  {
    for (auto it = d_data.begin(); it != d_data.end(); ++it)
    {
      temp_val = (*it - limits.minimum) / (limits.maximum - limits.minimum);
      *it = temp_val;
    }
  }
  return 0;
}

int Normalizer::NormalizeDataUp(std::vector<double> &d_data)
{
  double temp_val;

  if (limits.maximum != DBL_MIN && limits.minimum != DBL_MAX)
  {
    for (auto it = d_data.begin(); it != d_data.end(); ++it)
    {
      temp_val = (*it) * (limits.maximum - limits.minimum) + limits.minimum;
      *it = temp_val;
    }
  }
  return 0;
}

double Normalizer::NormalizeSingleDataDown(double i_data)
{
  return (i_data - limits.minimum) / (limits.maximum - limits.minimum);
}

double Normalizer::NormalizeSingleDataUp(double i_data)
{
  return i_data * (limits.maximum - limits.minimum) + limits.minimum;
}
