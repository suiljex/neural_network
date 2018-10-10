#include "NeuronOutput.hpp"
#include <math.h>

NeuronOutput::NeuronOutput()
{

}

int NeuronOutput::Process()
{
  input_X = CalculateSum();
  result = ProcFunc(input_X);
  //d_in_sum = 0;
  return 0;
}

double NeuronOutput::ProcFunc(double i_input_X)
{
  return (1. / (1. + exp(-1. * alpha * i_input_X)));
  //return i_input_X;
}

double NeuronOutput::ProcFuncDerivative(double i_input_X)
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

int NeuronOutput::CalculateGradient(double i_d)
{
  d = (i_d - result) * ProcFuncDerivative(input_X);
  //d = result * (1 - result) * (i_d - result);
  //d = ProcFuncDerivative(result) * (i_d - result);
  //UpdateWeights();
  return 0;
}

int NeuronOutput::UpdateWeights()
{
  double delta_w;

  for (auto it = connections_in.begin(); it != connections_in.end(); ++it)
  {
    //delta_w = alpha * ((*it)->delta_weight) + (1 - alpha) * velocity * (*it)->ptr_dst->GetD() * result;

    delta_w = velocity * d * ProcFuncDerivative(input_X) * ((*it)->ptr_src->GetResult());
    (*it)->weight += delta_w;
    (*it)->delta_weight = delta_w;
  }
  return 0;
}

double NeuronOutput::CalculateSum()
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
