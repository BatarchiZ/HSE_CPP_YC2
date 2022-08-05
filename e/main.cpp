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

int main()
{
    std::cout << "\t";
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << "\t";
    }
    std::cout << "A" << "\t" << "B" << "\t" << "C" << "\t" << "D" << "\t" << "E" << "\t" << "F" << "\t" << std::endl;
    for (int k = 2; k < 8; k++)
    {
        std::cout << k << '\t';
        for (int i = 0; i < 16; i++)
        {
            {
                std::cout << char((16 + i) + (16 * (k - 1))) << '\t';
            }
        }
        std::cout << std::endl;
    }
    return 0;
}