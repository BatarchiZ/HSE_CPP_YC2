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
#include <fstream>
#include <vector>
#include <sstream>

std::string task2(std::istream &);

std::string reduce3(std::istream &);

std::string truncate4(std::istream &);

//Function within task2
std::string addLetterInt(char);

//Booleans to test for letters, name == letters which are tested
bool bpft(char);

bool cgjkqsz(char);

bool dt(char);

bool mn(char);

int main()
{
//    const std::string INP_FILE = "../../code/d/input.txt";

//Read File
    const std::string INP_FILE_NAME = "input.txt";
    std::ifstream input_file123;
    input_file123.open(INP_FILE_NAME);

    //Get First Letter
    std::string word;
    std::getline(input_file123, word);
    char letter_1 = word[0];
    input_file123.clear();
    input_file123.seekg(0);

    //First pre-process
    std::stringstream ss;
    ss << task2(input_file123);

    //Second pre-process
    std::stringstream ss2;
    ss2 << reduce3(ss);

    //Third pre-process
    std::string str;
    str = truncate4(ss2);

    //Output
    std::cout << letter_1 << str;
    return 0;
}

std::string task2(std::istream &ss)
{
    std::string str;
    std::string emptystr;
    getline(ss, str);
    for (int i = 1; i < str.size(); i++)
    {
        emptystr += addLetterInt(str[i]);
    }
    return emptystr;
}

std::string reduce3(std::istream &ss)
{
    std::string(str);
    std::getline(ss, str);
    std::string newstr;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == str[i - 1])
        {
            continue;
        }
        newstr += str[i];

    }
    return newstr;
}

std::string truncate4(std::istream &ss)
{
    std::string str;
    std::getline(ss, str);
    if (str.size() < 3)
    {
        while (str.size() != 3)
        {
            str += "0";
        }
    } else
    {
        std::string tempstr;
        for (int i = 0; i < 3; i++)
        {
            tempstr += str[i];
        }
        str = tempstr;
    }
    return str;
}

//Function within task2
std::string addLetterInt(char i)
{
    std::string emptystr;
    if (bpft(i))
    {
        emptystr += "1";
    }
    if (cgjkqsz(i))
    {
        emptystr += "2";
    }
    if (dt(i))
    {
        emptystr += "3";
    }
    if (i == 'l')
    {
        emptystr += "4";
    }
    if (mn(i))
    {
        emptystr += "5";
    }
    if (i == 'r')
    {
        emptystr += "6";
    }
    return emptystr;
}

//Booleans to test for letters, name == letters which are tested
bool bpft(char i)
{
    return ((i == 'b') or (i == 'p') or (i == 'f') or
            (i == 'v'));
}

bool cgjkqsz(char i)
{
    return ((i == 'c') or (i == 'g') or (i == 'j') or
            (i == 'k') or (i == 'q') or (i == 's') or
            (i == 'z'));
}

bool dt(char i)
{
    return ((i == 'd') or (i == 't'));
}

bool mn(char i)
{
    return ((i == 'm') or (i == 'n'));
}


