//Specificaton file for the Coin class
#ifndef COIN_H
#define COIN_H
#include <string>

using namespace std;

class Coin
{
private:
    string sideUp;
    int num;// 1 stand for heads, 2 stand for tails
    int numberHead;
    int numberTail;

public:
    Coin ();
    void toss();
    void setSideUp();
    string getSideUp() const;
    int getNumHead() const
    { return numberHead; }
    int getNumTail() const
    { return numberTail; }
};
#endif