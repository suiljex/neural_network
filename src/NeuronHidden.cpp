#include "NeuronHidden.hpp"
#include <math.h>

const double alpha = 0.5;

NeuronHidden::NeuronHidden()
{

}

int NeuronHidden::Process()
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

int NeuronHidden::AddConnection(NConnection i_connection)
{
  connections.push_back(i_connection);
  return 0;
}

double NeuronHidden::GetResult()
{
  return result;
}

int NeuronHidden::SetResult(double /*i_result*/)
{
  return 0;
}

double NeuronHidden::ProcFunc(double i_input_X)
{
  return (1. / (1. + exp(-1. * alpha * i_input_X)));
}
