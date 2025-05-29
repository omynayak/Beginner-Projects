/*
author: omynayak
function and description: serves as a calculator that helps exercise essential programming practices like flow control,
                            conditionals, unions and basic input/output
*/

#include <iostream>
#include <stdbool.h>
using namespace std;

//Define a union that holds all the variables I will be using
//Using a union since no two of these variables will need to exist simultaneously
union choicesAndValues
{
    char choice;
    char operation;
    float secondVal;
} cAndV;


//Where all the magic happens
int main()
{
    // Read and validate the input choice to begin or not
    cout << "Would you like to begin?(y/n): ";
    cin >> cAndV.choice;
    while (cAndV.choice != 'y' && cAndV.choice != 'n')
    {
        cout << "Invalid input. Please try again: ";
        cin >> cAndV.choice;
    }
    
    // Start a while loop that contains the main part of the program with a bool flag to check if it is the first value being entered
    float values;
    bool flag = true;
    while (cAndV.choice == 'y') 
    {
        if (flag)
        {
            cout << "Enter the first value: ";
            cin >> cAndV.secondVal;
            values = cAndV.secondVal;
            flag = false;
        }

        // The program continuously overwrites the "values" variable from here on, discarding any previous value stored by replacing it
        // with an updated version complete with the computation performed on it with the other number entered
        cout << "Please choose the operation:(+ - / * % /c)";
        cin >> cAndV.operation;

        // Apply operations based on the input character
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

        // The default condition in case the input was not in the list
        default:
            cout << "Invalid operation. Try again.";
            continue;
        }

        // If the calculator value was NOT cleared and reset, display the current output
        if (!(flag))
        {
            cout << "The answer is: " << values << endl;
        }

        // Take input for the choice variable that controls the while loop
        cout << "Would you like to continue?(y/n) ";
        cin >> cAndV.choice;
        if (cAndV.choice != 'y')
            break;
    }

    cout << "Please come back soon!\n";
    return 0;
}