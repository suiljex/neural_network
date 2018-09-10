#include "NeuronInput.hpp"

NeuronInput::NeuronInput()
{

}

int NeuronInput::Process()
{
  return 0;
}

int NeuronInput::AddConnection(NConnection /*i_connection*/)
{
  return 0;
}

double NeuronInput::GetResult()
{
  return result;
}

int NeuronInput::SetResult(double i_result)
{
  result = i_result;
  return 0;
}

double NeuronInput::ProcFunc(double /*i_input_X*/)
{
  return 0;
}
