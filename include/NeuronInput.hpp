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

#endif // NEURONINPUT_HPP
