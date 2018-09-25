#include "NeuronHidden.hpp"
#include <math.h>

NeuronHidden::NeuronHidden()
{

}

int NeuronHidden::Process()
{
  double input_X = 0;

  std::vector<NConnection>::iterator it = connections_parent.begin();
  for (; it != connections_parent.end(); ++it)
  {
    if (it->source_pointer != nullptr)
    {
      input_X += it->source_pointer->GetResult() * it->weight;
    }
  }
  result = ProcFunc(input_X);
  //d_in_sum = 0;
  return 0;
}

int NeuronHidden::AddConnection(NConnection i_connection)
{
  connections_parent.push_back(i_connection);
  NConnection back_connection;
  //back_connection.source_pointer.reset(this);
  back_connection.source_pointer = this;
  i_connection.source_pointer->AddConnectionBack(back_connection);
  return 0;
}

int NeuronHidden::AddConnectionBack(NConnection i_connection)
{
  connections_child.push_back(i_connection);
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

int NeuronHidden::Train(double)
{
  double d_in_sum = 0;

  for (auto it = connections_child.begin(); it != connections_child.end(); ++it)
  {
    d_in_sum += it->source_pointer->GetD();
  }

  d = result * (1 - result) * d_in_sum;
  UpdateWeights();
  return 0;
}

int NeuronHidden::UpdateWeights()
{
  double delta_w;

  for (auto it = connections_parent.begin(); it != connections_parent.end(); ++it)
  {
    delta_w = alpha * (it->delta_weight) + (1 - alpha) * velocity * d * (it->source_pointer->GetResult());
    it->weight -= delta_w;
    it->delta_weight = delta_w;
  }
  return 0;
}

double NeuronHidden::ProcFunc(double i_input_X)
{
  return (1. / (1. + exp(-1. * alpha * i_input_X)));
}
