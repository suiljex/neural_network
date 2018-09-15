#ifndef DATAPARSER_HPP
#define DATAPARSER_HPP

#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "NeuralNetwork.hpp"

class DataParser
{
public:
  DataParser();

  std::vector<std::vector<double>> GetInputData();
  std::vector<double> GetExpectedResults();

  int SetFilenameInput(std::string& i_filename);
  int SetFilenameOutput(std::string& i_filename);
  std::string GetFilenameInput();
  std::string GetFilenameOutput();
  int InputFileParse(NeuralNetwork& d_neural_network);

protected:
  int PutInputDataIntoNetwork(NeuralNetwork& d_neural_network);
  int GetNextParameter(std::string& d_line, std::string& o_parameter);
  void SkipWhiteSpaces(std::string& o_string);
  bool IsNumber(const char* i_str);
  int AddLevel();

  std::string filename_input_data;
  std::string filename_output_data;

  std::ofstream file_output_data;

  std::vector<std::vector<double>> input_data;
  std::vector<double> expected_results;
};

#endif // DATAPARSER_HPP
