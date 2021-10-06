//Author: S.G.Seyone
//QUESTION COMPLETED IN 35min.

#include <iostream>
#include <sstream>

using namespace std;

double doubleSummer(double arg1, double arg2, double arg3) //use a verb form usually.
{
    double output = arg1 + arg2 + arg3;
    return output;
}

double doubleSummer(double arg1, double arg2, double arg3, double arg4)
{
    double output = arg1 + arg2 + arg3 + arg4;
    return output;
}

double divider(double numerator, int divisor) // divide would be better
{
    double output = numerator / divisor;
    return output;
}

double sanitizedInputsDou()
{
    string lineInput;

    cout << ">> ";
    getline(cin, lineInput);
    double output = stod(lineInput);

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
    int GPACounter = -1;
    double FGPA;
    string criteria;
    do
    {
        cout << "FGPA Calculator\n\n";
        cout << "To being, please enter your personal information as requested below.\n";

        cout << "Student Name:\n";
        string sName = sanitizedInputsStr();

        cout << "Student Registration Number:\n";
        string sReg = sanitizedInputsStr();

        do
        {
            cout << "Degree Criteria (General or Special):\n";
            criteria = sanitizedInputsStr();

            if (criteria == "General" || criteria == "general" || criteria == "GENERAL")
            {
                GPACounter = 3;
            }
            else if (criteria == "Special" || criteria == "special" || criteria == "SPECIAL")
            {
                GPACounter = 4;
            }
            else
            {
                cout << "Your degree can only be 'General' or 'Special'. Please choose between the two.\n";
            }
        } while (GPACounter < 1);

        double GPA[GPACounter];

        for (int i = 0; i < GPACounter; i++)
        {
            cout << i + 1 << ". Please enter your GPA\n";
            GPA[i] = sanitizedInputsDou();
        }

        switch (GPACounter)
        {
        case 3:
            FGPA = divider(doubleSummer(GPA[0], GPA[1], GPA[2]), 3);
            break;

        case 4:
            FGPA = divider(doubleSummer(GPA[0], GPA[1], GPA[2], GPA[3]), 4);
            break;
        }

        cout << "Name :\t\t\t" << sName << endl;
        cout << "Registration Number :\t" << sReg << endl;
        cout << "Degree type :\t\t" << criteria << endl
             << endl;

        for (int i = 0; i < GPACounter; i++)
        {
            cout << "Level " << i + 1 << " GPA " << GPA[i] << ", ";
        }
        cout << endl;

        cout << "FGPA :\t" << FGPA << endl;

        cout << "\nWould you like to perform another operation? (Y/N)\n";
        string redoSelector;
        redoSelector = sanitizedInputsStr();
        if (redoSelector == "n" || redoSelector == "N")
        {
            return 0;
        }
    } while (true);
}