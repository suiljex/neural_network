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

  int Process()
  {
    double input_X = 0;

    std::vector<NConnection>::iterator it = connections.begin();
    for (; it != connections.end(); ++it)
    {
      if (it->source_pointer != nullptr)
      {
        input_X += it->source_pointer->GetResult() * it->weight;
      }
    }
    result = ProcFunc(input_X);
    return 0;
  }

  int AddConnection(NConnection i_connection)
  {
    connections.push_back(i_connection);
    return 0;
  }

  double GetResult()
  {
    return result;
  }

  int ForceSetResult(double i_result)
  {
    result = i_result;
    return 0;
  }

private:

  double ProcFunc(double i_input_X)
  {
    return i_input_X;
  }

  int id;
  double result;
  std::vector<NConnection> connections;
};

#endif // NEURON_HPP
