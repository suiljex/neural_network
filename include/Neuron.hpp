#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

class Neuron;

typedef struct NeuronConnection
{
  NeuronConnection()
  {
    source_id = 0;
    weight = 0;
    source_pointer = nullptr;
  }

  int source_id;
  Neuron* source_pointer;
  double weight;

}NConnection;

class Neuron
{
public:
  Neuron();

  int Process();
  int AddConnection(NConnection i_connection);
  double GetResult();
  int ForceSetResult(double i_result);

private:

  double ProcFunc(double i_input_X);

  int id;
  double result;
  std::vector<NConnection> connections;
};

#endif // NEURON_HPP
