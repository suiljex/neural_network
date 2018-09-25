#ifndef NEURONBASE_HPP
#define NEURONBASE_HPP

#include <vector>
#include <memory>

const double alpha = 0.5;
const double velocity = 1;

class NeuronBase;

typedef struct NeuronConnection
{
  NeuronConnection()
  {
    source_id = 0;
    weight = 0;
    delta_weight = 0;
    source_pointer = nullptr;
  }

  int source_id;
  std::shared_ptr<NeuronBase> source_pointer;
  double weight;
  double delta_weight;

}NConnection;

class NeuronBase
{
public:
  NeuronBase(){}

  virtual int Process() = 0;
  virtual int AddConnection(NConnection i_connection) = 0;
  virtual int AddConnectionBack(NConnection i_connection) = 0;
  virtual double GetResult() = 0;
  virtual double GetD() = 0;
  virtual int SetResult(double i_result) = 0;
  virtual int Train(double i_expect) = 0;
  virtual int UpdateWeights() = 0;

protected:

  virtual double ProcFunc(double i_input_X) = 0;

  int id;
  double result;
  //double d_in_sum;
  double d;
  std::vector<NConnection> connections_parent;
  std::vector<NConnection> connections_child;
};

#endif // NEURONBASE_HPP
