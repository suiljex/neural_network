#ifndef NEURONBASE_HPP
#define NEURONBASE_HPP

#include <vector>
#include <memory>

class NeuronBase;

typedef struct NeuronConnection
{
  NeuronConnection()
  {
    source_id = 0;
    weight = 0;
    source_pointer = nullptr;
  }

  int source_id;
  std::shared_ptr<NeuronBase> source_pointer;
  double weight;

}NConnection;

class NeuronBase
{
public:
  NeuronBase(){}

  virtual int Process() = 0;
  virtual int AddConnection(NConnection i_connection) = 0;
  virtual double GetResult() = 0;
  virtual int SetResult(double i_result) = 0;

private:

  virtual double ProcFunc(double i_input_X) = 0;

  int id;
  double result;
  std::vector<NConnection> connections;
};

#endif // NEURONBASE_HPP
