//Author: S.G.Seyone
//QUESTION COMPLETED IN 1hr, 26min.

#include <iostream>
#include <sstream>

using namespace std;

int sanitizedInputsInt()
{
    string lineInput;

    cout << ">> ";
    getline(cin, lineInput);
    int output = stoi(lineInput);

    return output;
}

string sanitizedInputsStr()
{
    string lineInput;
    cout << ">> ";
    getline(cin, lineInput);
    string output = lineInput;

    return output;
}

int main()
{
    int dataTable[4][3]{
        {29, 60, 22},
        {31, 54, 24},
        {20, 57, 16},
        {3, 18, 9}};
    string dataColHeader[3]{"AMC", "ICT", "ENS"};
    string dataRowHeader[4]{"Level-I", "Level-II", "Level-III", "Level-IV"};

    int selector;
    bool invalid;

    cout << "\t\t\tStudents' Analysis System for Faculty of Applied Sciences in Academic Year 2014/2015\n\n";
    do
    {
        invalid = false;
        cout << "\nPlease make a selection from the options given below.\n";

        cout << "\t1 - \tList the number of students for each course\n"
             << "\t2 - \tList the number of students in each level\n"
             << "\t3 - \tList the number of students following a specific course in a particular level\n"
             << "\t4 - \tDisplay the total number of students in the Faculty for tha academic year 2014/2015\n"
             << "\t5 - \tExit the program\n";

        selector = sanitizedInputsInt();
        switch (selector)
        {
        case 1:
        {
            //Requires the total of each column
            int colTotal[3]{0, 0, 0};
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    colTotal[j] += dataTable[i][j];
                }
            }
            cout << "--The number of students studying in each course--\n";
            for (int i = 0; i < 3; i++)
            {
                cout << "\t\t" << dataColHeader[i] << "\t:\t" << colTotal[i] << endl;
            }
            cout << endl;
            break;
        }

        case 2:
        {
            //Requres the total of each row
            int rowTotal[4]{0, 0, 0, 0};
            for (int j = 0; j < 3; j++)
            {
                for (int i = 0; i < 4; i++)
                {
                    rowTotal[i] += dataTable[i][j];
                }
            }
            cout << "--The number of students in each level--\n";
            for (int i = 0; i < 4; i++)
            {
                cout << "\t\t" << dataRowHeader[i] << "\t:\t" << rowTotal[i] << endl;
            }
            cout << endl;
            break;
        }
        case 3:
        {
            //Requires two selectors
            int outputNumber, selectedColHeader, selectedRowHeader;

            cout << "Please enter the Course Name (AMC, ICT, or ENS)\n";
            string cName = sanitizedInputsStr();
            cout << "Please enter the level (1, 2, 3, or 4)\n";
            int level = sanitizedInputsInt();

            //comparing Column headers, course names
            for (int j = 0; j < 3; j++)
            {
                if (dataColHeader[j] == cName)
                {
                    selectedColHeader = j;
                }
            }
            //comparing Row headers, levels
            selectedRowHeader = level - 1;

            outputNumber = dataTable[selectedRowHeader][selectedColHeader];
            cout << "The number of students who study " << cName << " at Level " << level << " is " << outputNumber << endl;
            break;
        }
        case 4:
        {
            int runningTotal = 0;

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    runningTotal += dataTable[i][j];
                }
            }
            cout << "The total number of students across all courses and levels is " << runningTotal << endl;
            break;
        }
        case 5:
        {
            return 0;
        }
        default:
        {
            cout << "\nInvalid selection. Please select a valid option.\n";
            invalid = true;
            break;
        }
        }
        //Exit option after completing an operation
        if (invalid == false)
        {
            cout << "\nWould you like to perform another operation? (Y/N)\n";
            string redoSelector;
            redoSelector = sanitizedInputsStr();
            if (redoSelector == "n" || redoSelector == "N")
            {
                return 0;
            }
        }
    } while (true);
}