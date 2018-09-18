#ifndef STORAGEUNIT_HPP
#define STORAGEUNIT_HPP

#include <math.h>
#include "Normalizer.hpp"

typedef struct DataBoundle
{
  DataBoundle();

  int NormalizeDown();
  int NormalizeUp();
  int CalculateLimits()
  {
    normalizer.CalculateLimits(data);
    return 0;
  }

  Normalizer normalizer;
  std::vector<double> data;

} DB;

class StorageUnit
{
public:

  StorageUnit();

  int InitInputLevels
  (
      int i_levels
  );

  std::vector<double> GetInputDataByIndex
  (
      int i_index
  );

  int AddData
  (
      std::vector<double>& i_data
    , double i_expected_result
  );

  int AddResult
  (
      double i_result
  );

  std::vector<double> GetResults();

  std::vector<double> GetErrors();

  std::vector<double> GetExpResults();

  std::vector<DB> GetInputData();

  int CalculateLimits();

protected:

  std::vector<DB> input_data;
  DB results;

  std::vector<double> expected_results;
  std::vector<double> errors;
};


#endif // STORAGEUNIT_HPP
