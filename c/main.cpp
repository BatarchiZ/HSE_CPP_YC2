////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Contest X Problem Y
/// \author     Student's Name
/// \version    0.1.0
/// \date       25.01.2021
///
/// Copy the task description here.
///
////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

int countLetter(std::istream &);

int countWord(std::istream &);

int countLine(std::istream &);


int main()
{
//    const std::string INP_FILE_NAME = "../../code/c/input.txt";

//Read File
    const std::string INP_FILE_NAME = "input.txt";
    std::ifstream input_file;
    input_file.open(INP_FILE_NAME);

    //Output
    std::cout << "Input file contains:" << std::endl;
    std::cout << countLetter(input_file) << " letters" << std::endl;
    input_file.clear();
    input_file.seekg(0);
    std::cout << countWord(input_file) << " words" << std::endl;
    input_file.clear();
    input_file.seekg(0);
    std::cout << countLine(input_file) << " lines";
    return 0;
}

int countLetter(std::istream &is)
{
    std::string str;
    int number_letter = 0;
    while (std::getline(is, str, '\n'))
    {
        for (char i: str)
        {
            if (std::isalpha(i))
            {
                number_letter += 1;
            }
        }
    }
    return number_letter;
}

int countWord(std::istream &is)
{
    std::string str;
    int number_word = 0;
    std::string word;
    std::stringstream ss;
    while (std::getline(is, str, '\n'))
    {
        if (isalpha(str[0]))
        {
            number_word += 1;
        }
        for (int i = 0; i < str.length(); i++)
        {

            if (!isalpha(str[i]))
            {
                if (isalpha(str[i + 1]))
                {
                    number_word += 1;
                }
            }
        }
    }
    return number_word;
}

int countLine(std::istream &is)
{
    std::string str;
    int number_lines = 0;
    while (getline(is, str))
    {
        number_lines += 1;
    }
    return number_lines;
}

