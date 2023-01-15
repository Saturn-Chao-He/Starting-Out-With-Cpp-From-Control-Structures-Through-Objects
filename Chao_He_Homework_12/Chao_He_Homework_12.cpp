//******************************************************************************
// Computer Science 50X2
// Fall 2019
// Assignment # 12
// Due Date: Wednesday, Ocorber 16
// Instructor: Dr. Jeff Jenness
// Programmer: Chao He
// Description: input a string and call a function that accepts a pointer to a 
// C-string as an argument and displays its contents backward   
// Input: phrase
// Output: Display the backward string
//******************************************************************************

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;

// Function Prototype
void backward( char* );

// constant variables
const int SIZE = 100;

int main ()
{
    char phrase[SIZE];
    int i = 0;

    cout << endl
         << '\t' << '\t' << '\t' << " Backward String " << endl;
    cout << "****************************************************************************** "
         << endl << endl;
    cout << "Please input string > ";
    cin.getline(phrase, SIZE);
    cout << endl;
    cout << "The string you entered is > ";

    while(phrase[i] != '\0')
    {
        cout << phrase[i];
        i++;
    }
    cout << endl << endl;
    cout << "The backward string is > ";
    backward(phrase);
    cout << endl << endl;

    return 0;
}

void backward( char *s)
{
    int i = 0;
    int j;

    while( s[i] != '\0')
    {
        i++;
    }

    for(j = i; j >= 0; j--)
    {
        cout << s[j];
    }

}
