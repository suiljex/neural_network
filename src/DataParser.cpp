#include "DataParser.hpp"

DataParser::DataParser()
{

}

int DataParser::PutInputDataIntoNetwork(NeuralNetwork &d_neural_network)
{
  if (input_data.size() == expected_results.size())
  {
    for (unsigned int i = 0; i < input_data.size(); ++i)
    {
      d_neural_network.AddData(input_data[i], expected_results[i]);
    }
  }

  return 0;
}

std::vector<std::vector<double> > DataParser::GetInputData()
{
  return input_data;
}

std::vector<double> DataParser::GetExpectedResults()
{
  return expected_results;
}

int DataParser::SetFilenameInput(std::string &i_filename)
{
  filename_input_data = i_filename;
  return 0;
}

int DataParser::SetFilenameOutput(std::string &i_filename)
{
  filename_output_data = i_filename;
  return 0;
}

std::string DataParser::GetFilenameInput()
{
  return filename_input_data;
}

std::string DataParser::GetFilenameOutput()
{
  return filename_output_data;
}

int DataParser::InputFileParse(NeuralNetwork& d_neural_network)
{
  //File format:
  //  var1|var2:res

  std::ifstream file_input_data;
  std::string temp_line_input;
  std::string temp_line_param;
  double temp_value;
  int vars_amount = d_neural_network.GetInputNeuronsAmount();

  file_input_data.open(filename_input_data);
  if (file_input_data.is_open() == true)
  {
    while (file_input_data.eof() == false)
    {
      AddLevel();
      getline(file_input_data, temp_line_input, '\n');
      for (int i = 0; i < vars_amount; ++i)
      {
        GetNextParameter(temp_line_input, temp_line_param);
        if (IsNumber(temp_line_param.c_str()) == true)
        {
          char* dummy_str;
          temp_value = strtod(temp_line_param.c_str(), &dummy_str);
          input_data.back().push_back(temp_value);
        }
        else
        {
          return 4;
        }
      }

      GetNextParameter(temp_line_input, temp_line_param);
      if (IsNumber(temp_line_param.c_str()) == true)
      {
        char* dummy_str;
        temp_value = strtod(temp_line_param.c_str(), &dummy_str);
        expected_results.push_back(temp_value);
      }
      else
      {
        return 4;
      }
    }
  }
  else
  {
    return 1;
  }

  PutInputDataIntoNetwork(d_neural_network);
  return 0;
}

int DataParser::GetNextParameter(std::string &d_line, std::string &o_parameter)
{
  int param_size;

  SkipWhiteSpaces(d_line);

  if (d_line.empty() == true)
  {
    return 3;
  }

  param_size = d_line.find_first_of("|:");
  if (param_size == -1)
  {
    param_size = d_line.size();
  }

  o_parameter.assign(d_line, 0, param_size);

  d_line.erase(0, param_size);
  param_size = d_line.find_first_of("|:");
  if (param_size != -1)
  {
    d_line.erase(0, 1);
  }

  return 0;
}

void DataParser::SkipWhiteSpaces(std::string &o_string)
{
  while (o_string.empty() == false && (o_string[0] == ' ' || o_string[0] == '\t'))
  {
    o_string.erase(0,1);
  }
}

bool DataParser::IsNumber(const char *i_str)
{
  char* temp;

  strtod(i_str, &temp);
  if (temp == i_str)
  {
    return false;
  }
  return true;
}

int DataParser::AddLevel()
{
  std::vector<double> new_level;
  input_data.push_back(new_level);

  return 0;
}
