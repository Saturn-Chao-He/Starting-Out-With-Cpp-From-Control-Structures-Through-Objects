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

//Specificaton file for the Car class
#ifndef CAR_H
#define CAR_H
#include <string>
#include <iostream>

using namespace std;

class Car
{
private:
    int yearModel;
    string make;
    int speed;

public:
    Car(int y, string m)
    {yearModel = y; make = m; speed = 0;}
    
    void setMake(string m)
    { make = m; }

    void setYearModel(int y)
    { yearModel = y; }
    
    void setSpeed(int s)
    { speed = s; }

    int getYearModel() const
    { return yearModel; }

    string getMake() const
    { return make; }

    int getSpeed() const
    { return speed; }

    void accelerate()
    { speed += 5; }

    void breakSpeed()
    { speed -= 5; }
    
};
#endif