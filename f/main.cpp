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
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<int> addOne(std::istream &);

int main()
{
//    const std::string INP_FILE_NAME = "../../code/f/input.txt";

//Read File
    const std::string INP_FILE_NAME = "input.txt";
    std::ifstream input_file123;
    input_file123.open(INP_FILE_NAME);

    //Run Function
    std::vector<int> v = addOne(input_file123);

    //Output
    for (int i: v)
    {
        std::cout << i;
    }

    return 0;
}

std::vector<int> addOne(std::istream &is)
{
    std::string str;
    std::getline(is, str);
    std::vector<int> v;

    //Add to Vector
    for (char i: str)
    {
        v.push_back(i - '0');//Dirty Hax... What else can I use??
    }
    //Move Backwards in Vector
    for (int i = v.size() - 1; i >= 0; i--)
    {
        v[i] += 1;
        //If moves in significant figures
        if (v[i] == 10)
        {
            v[i] = 0;
            //If we get to v.front and it's zero
            if (i == 0)
            {
                v.insert(v.begin(), 1);
            }
            continue;
        }
        break;
    }
    return v;
}