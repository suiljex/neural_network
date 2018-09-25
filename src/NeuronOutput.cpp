#include "NeuronOutput.hpp"
#include <math.h>

NeuronOutput::NeuronOutput()
{

}

int NeuronOutput::Process()
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
  return 0;
}

double NeuronOutput::ProcFunc(double i_input_X)
{
  return (1. / (1. + exp(-1. * alpha * i_input_X)));
  //return i_input_X;
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
  d = result * (1 - result) * (i_d - result);
  //d = 1 * (i_d - result);
  UpdateWeights();
  return 0;
}

int NeuronOutput::UpdateWeights()
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

int NeuronOutput::AddConnection(NConnection i_connection)
{
  connections_parent.push_back(i_connection);
  NConnection back_connection;
  //back_connection.source_pointer.reset(this);
  back_connection.source_pointer = this;
  i_connection.source_pointer->AddConnectionBack(back_connection);
  return 0;
}

int NeuronOutput::AddConnectionBack(NConnection i_connection)
{
  connections_child.push_back(i_connection);
  return 0;
}
