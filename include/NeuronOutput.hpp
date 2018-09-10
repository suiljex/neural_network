#ifndef NEURONOUTPUT_HPP
#define NEURONOUTPUT_HPP

#include "NeuronBase.hpp"

class NeuronOutput: public NeuronBase
{
public:
  NeuronOutput();

  int Process();
  int AddConnection(NConnection i_connection);
  double GetResult();
  int SetResult(double i_result);

private:

  double ProcFunc(double i_input_X);

  int id;
  double result;
  std::vector<NConnection> connections;
};

#endif // NEURONOUTPUT_HPP
