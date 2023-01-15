//******************************************************************************
// Computer Science 50X2
// Fall 2019
// Assignment # 07
// Due Date: Monday, September 16
// Instructor: Dr. Jeff Jenness
// Programmer: Chao He
// Description: a game that lets the user play of Rock, Paper, Scissors against the computer
// Input: user_number
// Output: the result of the game
//******************************************************************************

# include <iostream>
# include <cstdlib>
# include <ctime>

using namespace std;

// Function Prototype
int get_user_number (  );
void show_user_choice ( int );
void show_computer_choice ( int );
void judge ( int, int );

int main ()
{
// Generate a random number, every second the number is different, so generate it in main function.*******************
    // Constants
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 3;

    // Variables
    int computer_number;
    int user_number;
    char ch;

    do
    {
        cout << " ****************************************************************************** " << endl << endl;
        cout << " Weird Dr. Jenness play game of Rock, Paper, Scissors with you  ";
        do
        {
            // Generate random number
            // Get the system time
            unsigned seed = time(0);

            // Seed the random number generator
            srand(seed);
            computer_number = ( rand () % ( MAX_VALUE - MIN_VALUE + 1) ) + MIN_VALUE;
            cout << endl;

            user_number = get_user_number (  );
            cout << endl << endl;

            show_user_choice ( user_number );
            cout << endl << endl;

            show_computer_choice ( computer_number );
            cout << endl << endl;

            if ( 1 == computer_number && 1== user_number )
                cout << " Tied. Please input again! ";

            if ( 2 == computer_number && 2 == user_number )
                cout << " Tied. Please input again! ";

            if ( 3 == computer_number && 3 == user_number )
                cout << " Tied. Please input again! ";
        }while (   (1 == computer_number && 1 == user_number)
                || (2 == computer_number && 2 == user_number)
                || (3 == computer_number && 3 == user_number) );

        judge ( computer_number, user_number );
        cout << endl << endl;

        cout << " ****************************************************************************** " << endl;
        cout << " Would you like to play again? (Y/N): ";
        cin >> ch;
        cout << endl;
    }while ( 'Y' == ch || 'y' == ch );

    return 0;
}

// Input and store the user's number
int get_user_number ( )
{
    int user_number;

    cout << endl
         << "  1. O   Stone " << endl
         << "  2. []  Paper " << endl
         << "  3. <   Scissors " << endl << endl
         << " Please input what you would like to choose >  ";
    cin  >> user_number;

    return user_number;
}

//Show the user's choice
void show_user_choice( int user_num )
{
    if ( user_num == 1)
        cout << " You chose :  O ";

    if ( 2 == user_num )
        cout << " You chose :  [] ";

    if ( 3 == user_num )
        cout << " You chose :  < ";
}

//Show computer's choice
void show_computer_choice ( int comp_num )
{
    if ( 1 == comp_num )
        cout << " Dr. Jenness chose :  O " ;

    if ( 2 == comp_num )
        cout << " Dr. Jenness chose :  [] " ;

    if ( 3 == comp_num )
        cout << " Dr. Jenness chose :   < " ;
}

// Judge the game
void judge ( int computer, int user )
{
    if ( 1 == computer && 2 == user ) // Dr. stone  vs You paper
        cout << " You win o(^_^)o ";

    if ( 1 == computer && 3 == user ) // Dr. stone  vs You scissors
        cout << " Weird Dr. Jenness win, you lose o(>_<)o ";

    if ( 2 == computer && 1 == user ) // Dr. paper  vs You stone
        cout << " Weird Dr. Jenness win, you lose o(>_<)o ";

    if ( 2 == computer && 3 == user ) // Dr. paper  vs You scissors
        cout << " You win o(^_^)o ";

    if ( 3 == computer && 1 == user ) // Dr. scissors vs You stone
        cout << " You win o(^_^)o ";

    if ( 3 == computer && 2 == user ) // Dr. scissors vs You paper
        cout << " Weird Dr. Jenness win, you lose o(>_<)o ";
}
