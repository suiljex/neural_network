#include "NeuronHidden.hpp"
#include <math.h>

NeuronHidden::NeuronHidden()
{

}

int NeuronHidden::Process()
{
  input_X = CalculateSum();
  result = ProcFunc(input_X);
  //d_in_sum = 0;
  return 0;
}

int NeuronHidden::AddConnection(NConnection* i_connection)
{
  i_connection->ptr_dst = this;
  connections_in.push_back(i_connection);
  i_connection->ptr_src->AddConnectionBack(i_connection);
  return 0;
}

int NeuronHidden::AddConnectionBack(NConnection* i_connection)
{
  connections_out.push_back(i_connection);
  return 0;
}

double NeuronHidden::GetResult()
{
  return result;
}

double NeuronHidden::GetD()
{
  return d;
}

int NeuronHidden::SetResult(double /*i_result*/)
{
  return 0;
}

int NeuronHidden::CalculateGradient(double)
{
  double d_in_sum = 0;

  for (auto it = connections_out.begin(); it != connections_out.end(); ++it)
  {
    d_in_sum += (*it)->ptr_dst->GetD() * (*it)->weight;
  }
  d = d_in_sum * (1 - result) * result;

  return 0;
}

int NeuronHidden::UpdateWeights()
{
  double delta_w;

  for (auto it = connections_in.begin(); it != connections_in.end(); ++it)
  {
    delta_w = velocity * d * (*it)->ptr_src->GetResult();

    (*it)->weight += delta_w;
    (*it)->delta_weight = delta_w;
  }
  return 0;
}

double NeuronHidden::CalculateSum()
{
  double input_X = 0;

  for (auto it = connections_in.begin(); it != connections_in.end(); ++it)
  {
    if ((*it)->ptr_src != nullptr)
    {
      input_X += (*it)->ptr_src->GetResult() * (*it)->weight;
    }
  }
  return input_X;
}

double NeuronHidden::ProcFunc(double i_input_X)
{
  return (1. / (1. + exp(-1. * alpha * i_input_X)));
}

double NeuronHidden::ProcFuncDerivative(double i_input_X)
{
  return ProcFunc(i_input_X) * (1 - ProcFunc(i_input_X));
}
