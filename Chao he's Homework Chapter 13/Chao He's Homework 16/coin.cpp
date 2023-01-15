//******************************************************************************
// Computer Science 50X2
// Fall 2019
// Assignment # 16
// Due Date: Monday, November 11
// Instructor: Dr. Jeff Jenness
// Programmer: Chao He
// Description: Define a class of coin tossing, simulate and toss the coin 20 times.
// Output: results of 20 times of tossing the coin and the number of heads or tails.
//******************************************************************************

// main function file for the coin class
#include <iostream>
#include "coin.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

Coin::Coin()
{
    //Get the system time
    unsigned seed = time(0);
    //Seed the random number generator
    srand(seed);
    //Perform an initial toss
    toss();
    numberHead = 0;
    numberTail = 0;
    setSideUp();
    if(numberHead != 0)
        numberHead = 0;
    if(numberTail != 0)
        numberTail = 0;
}

void Coin::toss()
{
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 2;
    //Get a random num for the cion
    num = (rand() % (MAX_VALUE  - MIN_VALUE + 1)) + MIN_VALUE;
}

void Coin::setSideUp()
{
     if(num == 1)
    {
        numberHead++;
        sideUp = "heads";
    }
    else
    {
        numberTail++;
        sideUp = "tails";
    }  
}

string Coin::getSideUp() const
{
   return sideUp;
}

int main ()
{
    Coin coin1;

    cout << endl << '\t' << '\t' << " Coin Toss Simulator " << endl
         << "***************************************************************************" << endl << endl;
    cout << " Initial side of the coin that is facing up is " << coin1.getSideUp() << endl;
    cout << endl << " Now, toss the coin 20 times ... " << endl << endl;
    for(int i = 0; i < 20; i++)
    {
        coin1.toss();
        coin1.setSideUp();       
        cout << endl << " The No. " << i+1 << " times toss, " << " the side that is facing up is " 
             << coin1.getSideUp() << endl;
    }
    cout << endl << " The number of head that is facing up is " << coin1.getNumHead() << endl
         << endl << " Teh number of tail that is facing up is " << coin1.getNumTail() << endl
         << endl << endl;

    return 0;
}