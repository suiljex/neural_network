#include "NeuronOutput.hpp"

NeuronOutput::NeuronOutput()
{

}

int NeuronOutput::Process()
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

double NeuronOutput::ProcFunc(double i_input_X)
{
  return i_input_X;
}

double NeuronOutput::GetResult()
{
  return result;
}

int NeuronOutput::SetResult(double /*i_result*/)
{
  return 0;
}

int NeuronOutput::AddConnection(NConnection i_connection)
{
  connections.push_back(i_connection);
  return 0;
}
