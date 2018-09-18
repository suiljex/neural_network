#ifndef NORMALIZER_HPP
#define NORMALIZER_HPP

#include <float.h>
#include <vector>

typedef struct MinimumMaximux
{
  MinimumMaximux()
  {
    minimum = DBL_MAX;
    maximum = -DBL_MAX;
  }
  MinimumMaximux(double i_min, double i_max)
  {
    minimum = i_min;
    maximum = i_max;
  }
  double minimum;
  double maximum;
} MinMax;

class Normalizer
{
public:

  Normalizer();

  Normalizer
  (
      MinMax i_limits
  );

  int SetLimits
  (
      MinMax i_limits
  );

  int SetLimits
  (
      double i_min
    , double i_max
  );

  int SetLimitMin
  (
      double i_min
  );

  int SetLimitMax
  (
      double i_max
  );

  MinMax GetLimits();

  int CalculateLimits
  (
      std::vector<double>& i_data
  );

  int NormalizeDataDown
  (
      std::vector<double>& d_data
  );

  int NormalizeDataUp
  (
      std::vector<double>& d_data
  );

  double NormalizeSingleDataDown
  (
      double i_data
  );

  double NormalizeSingleDataUp
  (
      double i_data
  );

protected:

  MinMax limits;
};

#endif // NORMALIZER_HPP
