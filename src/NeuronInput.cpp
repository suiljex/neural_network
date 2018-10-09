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

int NeuronInput::Train(double i_d)
{
  //    d_in_sum += i_d;
  //    d = Process() * (1 - Process()) * d_in_sum;
  return 0;
}

int NeuronInput::UpdateWeights()
{
  double delta_w;

  for (auto it = connections_out.begin(); it != connections_out.end(); ++it)
  {
    delta_w = alpha * ((*it)->delta_weight) + (1 - alpha) * velocity * (*it)->ptr_dst->GetD() * result;
    (*it)->weight += delta_w;
    (*it)->delta_weight = delta_w;
  }
  return 0;
}

double NeuronInput::ProcFunc(double /*i_input_X*/)
{
  return 0;
}

double NeuronInput::DerivativeFunc(double i_input_X)
{
  return 0;
}
