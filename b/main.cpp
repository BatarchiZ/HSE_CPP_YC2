//////////////////////////////////////////////////////////////////////////////////
///// \file
///// \brief      Main module for Contest 2 Problem Palindrom
///// \author     Student's Name
///// \version    0.1.0
///// \date       25.01.2021
/////
///// A string consisting of lowercase Latin letters and spaces is given. Check whether it is a palindrome without spaces (eg, "no lemon no melon").
/////
//////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

std::string compareStrings(std::istream &);

std::string removeWhiteSpace(std::string);


int main()
{
    std::string str;
    std::stringstream ss;
    std::getline(std::cin, str);
    ss << removeWhiteSpace(str);
    std::cout << compareStrings(ss);
    return 0;
}

std::string compareStrings(std::istream &ss)
{
    std::string str;
    std::getline(ss, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != str[str.length() - 1 - i])
        {
            std::string ANS = "no";
            return ANS;
        }
    }
    std::string ANS = "yes";
    return ANS;
}

std::string removeWhiteSpace(std::string str)
{
    std::stringstream ss;
    ss << str;
    std::string stri;
    std::string mainstr;

    while (!ss.eof())
    {
        std::getline(ss, stri, ' ');
        mainstr += stri;
    }
    return mainstr;
}

