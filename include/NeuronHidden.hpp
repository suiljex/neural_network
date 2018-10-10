#ifndef NEURONHIDDEN_HPP
#define NEURONHIDDEN_HPP

#include "NeuronBase.hpp"

class NeuronHidden: public NeuronBase
{
public:

  NeuronHidden();

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

  double CalculateSum()
  {
    double input_X = 0;

    for (auto it = connections_in.begin(); it != connections_in.end(); ++it)
    {
      if ((*it)->ptr_src != nullptr)
      {
        input_X += (*it)->ptr_src->GetResult() * (*it)->weight;
      }
    }
    return input_X;
  }

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

#endif // NEURONHIDDEN_HPP
