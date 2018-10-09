#include "NeuronOutput.hpp"
#include <math.h>

NeuronOutput::NeuronOutput()
{

}

int NeuronOutput::Process()
{
  double input_X = 0;

  for (auto it = connections_in.begin(); it != connections_in.end(); ++it)
  {
    if ((*it)->ptr_src != nullptr)
    {
      input_X += (*it)->ptr_src->GetResult() * (*it)->weight;
    }
  }
  result = ProcFunc(input_X);
  return 0;
}

double NeuronOutput::ProcFunc(double i_input_X)
{
  return (1. / (1. + exp(-1. * alpha * i_input_X)));
  //return i_input_X;
}

double NeuronOutput::DerivativeFunc(double i_input_X)
{
  return ProcFunc(i_input_X) * (1 - ProcFunc(i_input_X));
}

double NeuronOutput::GetResult()
{
  return result;
}

double NeuronOutput::GetD()
{
  return d;
}

int NeuronOutput::SetResult(double /*i_result*/)
{
  return 0;
}

int NeuronOutput::Train(double i_d)
{
  //d = result * (1 - result) * (i_d - result);
  d = DerivativeFunc(result) * (i_d - result);
  UpdateWeights();
  return 0;
}

int NeuronOutput::UpdateWeights()
{
  return 0;
}

int NeuronOutput::AddConnection(NConnection* i_connection)
{
  i_connection->ptr_dst = this;
  connections_in.push_back(i_connection);
  i_connection->ptr_src->AddConnectionBack(i_connection);
  return 0;
}

int NeuronOutput::AddConnectionBack(NConnection* i_connection)
{
  connections_out.push_back(i_connection);
  return 0;
}
