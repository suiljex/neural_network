#ifndef NEURONINPUT_HPP
#define NEURONINPUT_HPP

#include "NeuronBase.hpp"

class NeuronInput: public NeuronBase
{
public:

  NeuronInput();

  int Process();

  int AddConnection
  (
      NConnection* i_connection
  );

  int AddConnectionBack
  (
      NConnection* i_connection
  );

  double GetResult();

  double GetD();

  int SetResult
  (
      double i_result
  );

  int CalculateGradient
  (
      double i_d
  );

  int UpdateWeights();

protected:

  double CalculateSum();

  double ProcFunc
  (
      double i_input_X
  );
  double ProcFuncDerivative
  (
      double i_input_X
  );

  //int id;
  //double result;
  //std::vector<NConnection> connections;
};

#endif // NEURONINPUT_HPP
