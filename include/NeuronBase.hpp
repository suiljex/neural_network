#ifndef NEURONBASE_HPP
#define NEURONBASE_HPP

#include <vector>
#include <memory>

const double alpha = 0.5;
const double velocity = 0.5;

class NeuronBase;

typedef struct NeuronConnection
{
  NeuronConnection()
  {
    source_id = 0;
    weight = 0;
    delta_weight = 0;
    ptr_src = nullptr;
    ptr_dst = nullptr;
  }

  int source_id;
  NeuronBase* ptr_src;
  NeuronBase* ptr_dst;
  double weight;
  double delta_weight;

}NConnection;

class NeuronBase
{
public:
  NeuronBase(){}

  virtual int Process() = 0;
  virtual int AddConnection(NConnection* i_connection) = 0;
  virtual int AddConnectionBack(NConnection* i_connection) = 0;
  virtual double GetResult() = 0;
  virtual double GetD() = 0;
  virtual int SetResult(double i_result) = 0;
  virtual int CalculateGradient(double i_expect) = 0;
  virtual int UpdateWeights() = 0;

protected:

  virtual double CalculateSum() = 0;
  virtual double ProcFunc(double i_input_X) = 0;
  virtual double ProcFuncDerivative(double i_input_X) = 0;

  int id;
  double result;
  double d;
  double input_X;
  std::vector<NConnection*> connections_in;
  std::vector<NConnection*> connections_out;
};

#endif // NEURONBASE_HPP
