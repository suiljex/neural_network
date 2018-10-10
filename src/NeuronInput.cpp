#include "NeuronInput.hpp"

NeuronInput::NeuronInput()
{

}

int NeuronInput::Process()
{
  return 0;
}

int NeuronInput::AddConnection(NConnection* /*i_connection*/)
{
  return 0;
}

int NeuronInput::AddConnectionBack(NConnection* i_connection)
{
  connections_out.push_back(i_connection);
  return 0;
}

double NeuronInput::GetResult()
{
  return result;
}

double NeuronInput::GetD()
{
  return d;
}

int NeuronInput::SetResult(double i_result)
{
  result = i_result;
  return 0;
}

int NeuronInput::CalculateGradient(double i_d)
{
  //    d_in_sum += i_d;
  //    d = Process() * (1 - Process()) * d_in_sum;
  return 0;
}

int NeuronInput::UpdateWeights()
{
  double gradient;
  double delta_w;

  for (auto it = connections_out.begin(); it != connections_out.end(); ++it)
  {
    gradient = result * (*it)->ptr_dst->GetD();
    delta_w = velocity * gradient + alpha * ((*it)->delta_weight);

    (*it)->weight += delta_w;
    (*it)->delta_weight = delta_w;
  }
  return 0;
}

double NeuronInput::CalculateSum()
{
  return 0;
}

double NeuronInput::ProcFunc(double /*i_input_X*/)
{
  return 0;
}

double NeuronInput::ProcFuncDerivative(double i_input_X)
{
  return 0;
}
