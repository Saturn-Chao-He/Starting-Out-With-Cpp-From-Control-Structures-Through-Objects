//******************************************************************************
// Computer Science 50X2
// Fall 2019
// Assignment # 15
// Due Date: Monday, November 11
// Instructor: Dr. Jeff Jenness
// Programmer: Chao He
// Description: Demonstrate the class in a program that creates a Car object, then call the accelerate and break function 
//              five times, get the current speed and display it each time.
// Input : Year, Make, Speed
// Output: Current speed of each accelerating or break
//******************************************************************************

// main function file for the Car class
#include <iostream>
#include "car.hpp"
#include <string>

using namespace std;

int main ()
{
    int Year;
    string Make;
    int Speed;

    Car carSpeed( Year, Make );

    cout << endl << '\t' << '\t' << " Car Class " << endl
         << "***************************************************************************" << endl << endl;
    cout << " Please input the car's year model > ";
    cin  >> Year;
    cout << endl << " Please input the make of the car > ";
    cin  >> Make;
    cout << endl << " Please input the current speed of the car > ";
    cin  >> Speed;
    while(Speed < 0)
    {
        cout << " Invalid speed. Please input a speed which is equal or more than 0. Input again > ";
        cin >> Speed;
    }

    //Store data of the car
    carSpeed.setYearModel(Year);
    carSpeed.setMake(Make);
    carSpeed.setSpeed(Speed);

    cout << endl;
    //accelerate
    for( int i = 0; i < 5; i++ )
    {
        carSpeed.accelerate();
        cout << " Accelerated " << i+1 << " times, " << " the current speed is "
             << carSpeed.getSpeed() << endl << endl;
    }

    //break
    for( int i = 0; i < 5; i++ )
    {
        carSpeed.breakSpeed();
        cout << " Broke " << i+1 << " times, " << " the current speed is "
             << carSpeed.getSpeed() << endl << endl;
    }

    return 0;
}