#include <iostream>
#include <vector>

std::string join(const std::vector<std::string> &tokens, char delimiter)
{
    std::vector<std::string> v1;
    std::string str;
    if (!tokens.empty())
        //Can use if tokens.size != 0
    {
        for (int i = 0; i < tokens.size() - 1; i++) //Iterate up to last token.
        {
            str += tokens[i];
            str += delimiter;
        }
        str += tokens.back(); //Add last token without delimiter
    }
    return str;
}