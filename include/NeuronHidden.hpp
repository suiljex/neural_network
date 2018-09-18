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
      NConnection i_connection
  );

  double GetResult();

  int SetResult
  (
      double i_result
  );

private:

  double ProcFunc
  (
      double i_input_X
  );

  int id;
  double result;
  std::vector<NConnection> connections;
};

#endif // NEURONHIDDEN_HPP
