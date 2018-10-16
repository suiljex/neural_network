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

int NeuronInput::CalculateGradient(double /*i_d*/)
{
  return 0;
}

int NeuronInput::UpdateWeights()
{
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

double NeuronInput::ProcFuncDerivative(double /*i_input_X*/)
{
  return 0;
}
