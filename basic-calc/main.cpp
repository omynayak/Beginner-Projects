#include <iostream>
#include <stdbool.h>
using namespace std;

bool switchCase(float &values, bool &flag);

union choicesAndValues
{
    char choice;
    float tempVal;
    char operation;
    float secondVal;
} cAndV;



int main()
{
    cout << "Would you like to begin?(y/n): ";
    cin >> cAndV.choice;
    while (cAndV.choice != 'y' && cAndV.choice != 'n')
    {
        cout << "Invalid input. Please try again: ";
        cin >> cAndV.choice;
    }

    float values;
    bool flag = true;
    while (cAndV.choice == 'y')
    {
        if (flag)
        {
            cout << "Enter the first value: ";
            cin >> cAndV.tempVal;
            values = cAndV.tempVal;
            flag = false;
        }

        bool secondFlag = switchCase(values, flag);
        if(secondFlag) 
        {
            cAndV.choice = 'y';
            continue;
        }

        if (!(flag))
        {
            cout << "The answer is: " << values << endl;
        }

        cout << "Would you like to continue?(y/n) ";
        cin >> cAndV.choice;
        if (cAndV.choice != 'y')
            break;
    }

    cout << "Please come back soon!\n";
    return 0;
}


bool switchCase(float &values, bool &flag)
{
    cout << "Please choose the operation:(+ - / * % /c)";
        cin >> cAndV.operation;
        switch (cAndV.operation)
        {
        case '+':
            cout << "Enter the value: ";
            cin >> cAndV.secondVal;
            values += cAndV.secondVal;
            break;

        case '-':
            cout << "Enter the value: ";
            cin >> cAndV.secondVal;
            values -= cAndV.secondVal;
            break;

        case '*':
            cout << "Enter the value: ";
            cin >> cAndV.secondVal;
            values *= cAndV.secondVal;
            break;

        case '/':
            cout << "Enter the value: ";
            cin >> cAndV.secondVal;
            while(!cAndV.secondVal)
            {
                cout << "Invalid input. Try again: ";
                cin >> cAndV.secondVal;
            }
            values /= cAndV.secondVal;
            break;

        case '%':
            cout << "Enter the value: ";
            cin >> cAndV.secondVal;
            while(!int(cAndV.secondVal))
            {
                cout << "Cannot modulo by zero. Try again: ";
                cin >> cAndV.secondVal;
            }
            values = int(values) % int(cAndV.secondVal);
            break;

        case 'c':
            cout << "Clearing Calculator.\n";
            values = 0;
            flag = true;
            break;

        default:
            cout << "Invalid operation. Try again.\n";
            return true;
        }
        return false;
}