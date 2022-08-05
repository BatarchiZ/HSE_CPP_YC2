#include <vector>
#include <string>

std::vector<std::string> split(const std::string &str, char delimiter)
{
    std::vector<std::string> v;
    std::string newstr;
    for (char i: str) //Iterate over string
    {
        if (i != delimiter)
        {
            newstr += i;
        }
        else
        {
            v.insert(v.end(), newstr); //Add to vector
            newstr = "";
        }

    }
    v.insert(v.end(), newstr); //Add to vector when string finishes
    return v;
}