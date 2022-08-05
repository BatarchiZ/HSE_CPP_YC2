////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Contest X Problem Y
/// \author     Student's Name
/// \version    0.1.0
/// \date       25.01.2021
///
/// Creating a minefield game
///
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <vector>

typedef std::vector<int> Row;
typedef std::vector<Row> GamePlan;

//Initializes Field
GamePlan inputGamePlan(int, int);

Row inputRow(int);

//Increases number around bombs and marks bomb location in integer form
GamePlan bombAction(std::istream &, GamePlan &, int);

GamePlan iterateMatrix(GamePlan &, int, int);

bool numberIncreaseJ(int, int);

//Output
void outPut(GamePlan);

int main()
{
//    const std::string INP_FILE_NAME = "../../code/g/input.txt";

//Read File
    const std::string INP_FILE_NAME = "input.txt";
    std::ifstream input_file;
    input_file.open(INP_FILE_NAME);

    //Initialize and read first parameters
    std::string strN;
    std::string strM;
    std::string strK;
    std::getline(input_file, strN, ' ');
    std::getline(input_file, strM, ' ');
    std::getline(input_file, strK, '\n');
    int intN = stoi(strN);
    int intM = stoi(strM);
    int intK = stoi(strK);


    GamePlan gp = inputGamePlan(intN, intM);
    GamePlan gp1 = bombAction(input_file, gp, intK);

    //Output
    outPut(gp1);
    return 0;
}


Row inputRow(int columnN)
{
    Row row;
    if (columnN == 0)
        return row;
    for (int i = 0; i < columnN; i++)
    {
        row.push_back(0);
    }
    return row;
}

GamePlan inputGamePlan(int rowM, int intN)
{
    GamePlan gamePlan;
    Row r = inputRow(intN);
    for (int i = 0; i < rowM; i++)
    {
        gamePlan.push_back(r);
        r = inputRow(intN);
    }
    return gamePlan;
}


GamePlan bombAction(std::istream &is, GamePlan &gamePlan, int k0)
{
    std::string indexN;
    std::string indexM;

    for (int k = 0; k < k0; k++)
    {
        std::getline(is, indexN, ' ');
        std::getline(is, indexM, '\n');
        int indexIntN = stoi(indexN);
        int indexIntM = stoi(indexM);
        gamePlan = iterateMatrix(gamePlan, indexIntN, indexIntM);
    }
    return gamePlan;
}

//Functions for bombAction
GamePlan iterateMatrix(GamePlan &gamePlan, int indexIntN, int indexIntM)
{
    //Decalre Variables
    std::vector<std::vector<int> >::iterator row;
    std::vector<int>::iterator col;
    int i = 1;
    int j = 1;

    //Use Iterator and adjust values
    for (row = gamePlan.begin(); row != gamePlan.end(); row++)
    {
        for (col = row->begin(); col != row->end(); col++)
        {

            if (i == indexIntN - 1 or i == indexIntN + 1)
            {
                if (numberIncreaseJ(j, indexIntM))
                {
                    *col = *col + 1;
                }
            }

            if (i == indexIntN)
            {
                if (numberIncreaseJ(j, indexIntM))
                {
                    *col = *col + 1;
                    if (j == indexIntM)
                    {
                        *col = 9;
                    }
                }
            }
            j += 1;
        }
        i += 1;
        j = 1;
    }
    return gamePlan;
}

bool numberIncreaseJ(int j, int indexIntM)
{
    return ((j == indexIntM - 1) or (j == indexIntM) or (j == indexIntM + 1));
}

void outPut(GamePlan gp1)
{
    std::vector<std::vector<int> >::iterator row;
    std::vector<int>::iterator col;
    for (row = gp1.begin(); row != gp1.end(); row++)
    {
        for (col = row->begin(); col != row->end(); col++)
        {
            if (*col >= 9) //Add a star if matrix field is greater than 9
            {
                std::cout << "* ";
            } else
                std::cout << *col << " ";
        }
        std::cout << std::endl;
    }
}