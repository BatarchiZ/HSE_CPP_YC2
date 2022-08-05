////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Contest 2 Problem A
/// \author     Student's Name
/// \version    0.1.0
/// \date       25.01.2021
///
/// Vasya wants to change his email password, because he is afraid that his mailbox might have been hacked. According to the rules, a new password must meet the following restrictions:
///consist of ASCII table characters with codes from 33 to 127;
///be at least 8 characters and no longer than 14;
///from 4 classes of symbols - large letters, small letters, numbers, other symbols - at least three of any should be present in the password.
///Help Vasya to write a program that will verify that his new password is valid.
///The solution has to include functional decomposition. Failure to follow the decomposition requirements will result in the lower score, even if the solution gets "OK" from the contest checker. You may add extra functions in addition to the required ones. This rule applies to all tasks in the contest.
///Requirement: Implement the solution as a function that takes a password as input and returns true/false for passwords that fit or don't fit the restrictions. Use this function in the function main() to solve the problem
///
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <sstream>

//Function Prototypes
std::string toAscii(std::string &);

std::string lengthCheck(std::string &);

std::string fourClasses(std::string &);

std::string outputF(const std::string &, const std::string &, const std::string &);

//Main

int main()
{
    std::stringstream ss;
    std::string str1;
    std::getline(std::cin, str1);
    std::string answer;

    ss >> str1;

    std::string str = toAscii(str1);
    std::string str0 = lengthCheck(str1);
    std::string str3 = fourClasses(str1);
    answer = outputF(str, str0, str3);
    std::cout << answer;
    return 0;
}

std::string outputF(const std::string &str, const std::string &str0, const std::string &str3)
{
    std::string answer;
    if (str == "YES" && str0 == "YES" && str3 == "YES")
    {
        answer = "YES";
    } else
    {
        answer = "NO";
    }
    return answer;
}

std::string toAscii(std::string &ss)
{
    for (int i = 0; i < ss.length() - 1; i++)
    {
        if (ss[i] < '!' || ss[i] > '~' + 1)
        {
            std::string ans;
            ans = "NO";
            return ans;
        }
    }
    std::string ans;
    ans = "YES";
    return ans;
}

std::string lengthCheck(std::string &ss)
{
    if (ss.length() < 8 || ss.length() > 14)
    {
        std::string ans;
        ans = "NO";
        return ans;
    }
    std::string ans;
    ans = "YES";
    return ans;
}

std::string fourClasses(std::string &ss)
{
    int points = 0;
    for (char s: ss)
    {
        if (s >= 'A' and s <= 'Z')
        {
            points += 1;
            break;
        }
    }
    for (char s: ss)
    {
        if (s >= 'a' and s <= 'z')
        {
            points += 1;
            break;
        }
    }
    for (char s: ss)
    {
        if (s >= '0' and s <= '9')
        {
            points += 1;
            break;
        }

    }

    for (char i: ss)
    {
        if ((i < '0' || i > '9') && (i < 'a' || i > 'z') && (i < 'A' || i > 'Z'))
        {
            points += 1;
            break;
        }
    }
    if (points == 3 || points == 4)
    {
        std::string ans;
        ans = "YES";
        return ans;
    }
    std::string ans;
    ans = "NO";
    return ans;
}
