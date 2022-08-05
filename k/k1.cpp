#include <iostream>
#include <string>
#include <ctype.h>
std::string ExtractDigits(const std::string &s)
{
    std::string emptystr;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            emptystr += s[i];
        }
    }
    return emptystr;
}