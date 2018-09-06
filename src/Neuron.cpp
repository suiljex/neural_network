#include "Neuron.hpp"

Neuron::Neuron()
{

}

int Neuron::Process()
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

int Neuron::AddConnection(NConnection i_connection)
{
  connections.push_back(i_connection);
  return 0;
}

double Neuron::GetResult()
{
  return result;
}

int Neuron::ForceSetResult(double i_result)
{
  result = i_result;
  return 0;
}

double Neuron::ProcFunc(double i_input_X)
{
  return i_input_X;
}
