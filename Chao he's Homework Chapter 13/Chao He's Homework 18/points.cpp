//******************************************************************************
// Computer Science 50X2
// Fall 2019
// Assignment # 18
// Due Date: Monday, November 11
// Instructor: Dr. Jeff Jenness
// Programmer: Chao He
// Description: A program with class ask the user to enter a temperature, then display a list of the substances 
//              that will freeze or boil at that temperature.
// Input : temp1
// Output: a report list the substances that will freeze or boil at that temperature.
//******************************************************************************

// main function file for the Points class
#include <iostream>
#include <cctype>
#include "points.hpp"

using namespace std;

bool Points::isEthylFreezing()
{
    if(temperature <= -173)
        return true;
    else
        return false;   
}

bool Points::isEthylBoiling()
{
    if(temperature >= 172)
        return true;
    else
        return false;
}
bool Points::isOxygenFreezing()
{
    if(temperature <= -362)
        return true;
    else
        return false;
}
bool Points::isOxygenBoiling()
{
    if(temperature >= -306)
        return true;
    else
        return false;
}
bool Points::isWaterFreezing()
{
    if(temperature <= 32)
        return true;
    else
        return false;
}
bool Points::isWaterBoiling()
{
    if(temperature >= 212)
        return true;
    else
        return false;
}

int main ()
{
    Points temp;
    int temp1;
    char c;

    //Get the data
    cout << endl << '\t' << '\t' << " Freezing and Boiling Points " << endl
         << "***************************************************************************" << endl << endl;
    do
    {
        cout << "Please input the temperature > ";
        cin  >> temp1;
        temp.setTemperature(temp1);
        cout << endl;

        //Display the list
        cout << endl << "The list of the substances " << endl;
        cout << "----------------------------------" << endl << endl;
        if(temp.isEthylFreezing())
        {
            cout << "The ethyl alcohol will freeze. " << endl << endl;
        }
        if(temp.isEthylBoiling())
        {
            cout << "The ethyl alcohol will boil. " << endl << endl;
        }
        if(temp.isOxygenFreezing())
        {
            cout << "The Oxygen will freeze. " << endl << endl;
        }
        if(temp.isOxygenBoiling())
        {
            cout << "The Oxygen will boil. " << endl << endl;
        }
        if(temp.isWaterFreezing())
        {
            cout << "The water will freeze. " << endl << endl;
        }
        if(temp.isWaterBoiling())
        {
            cout << "The water will boil. " << endl << endl;
        }
        cout << endl << "Would you like to check again? (Y/N) Input > " ;
        cin >> c;
        cout << endl;
    } while (toupper(c) == 'Y');
    
    return 0;
}