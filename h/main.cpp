#include <iostream>
#include <fstream>
#include <vector>

std::string common_suffix(const std::string &a, const std::string &b)
{
    std::vector<char> testVec;
    std::string str = "";
    int j = b.size() - 1;
    int i = a.size() - 1;
    //If last letter matches
    if (a[i] == b[j])
    {

        {
            while (a[i] == b[j] and i > -1 and j > -1) //While the letters are matching; we don't reach eos.
            {
                testVec.insert(testVec.begin(), a[i]);
                i -= 1;
                j -= 1;
            }
        }
        for (char i: testVec) //return vector to Str
        {
            str += i;
        }
    }
    return str;
}