/*
* Program: Homework_4.cpp

* Date: 2019-09-05

* Purpose: Calculate the size of the population of the organism each day

* Input: starting_number, rate_of_increase, days

* Output: population

* Author: Chao He  50542901
*/

# include <iostream>
# include <cmath>

using namespace std;

int main(void)
{
    int starting_number, days;

    int rate_of_increase; // in percentage;

    double population;

    int i;

    cout << endl << endl;

    cout << '\t' << " The Predict of the Size of a Population of Organisms " << endl << endl << endl;

    cout << " Please input the starting number of organisms > ";

    do
    {
        cin >> starting_number;

        cout << endl;

        if ( starting_number < 2 )

            cout << " Error. The starting number should not less than 2, please input again > ";

    } while ( starting_number < 2);

    cout << endl;

    cout << " Please input the rate of increase ( in percentage ) > ";

    do
    {
        cin >> rate_of_increase;

        cout << endl;

        if ( rate_of_increase < 0 )

            cout << " Error. The rate of increase should not be negative, please input again > ";

    } while ( rate_of_increase < 0 );

    cout << endl;

    cout << " Please input the number of days they will multiply > ";

    do
    {
        cin >> days;

        cout << endl;

        if ( days < 1)

            cout << " Error. The days should not less than 1, please input again > ";

    } while ( days < 1);

    cout << endl;

    cout << " ---------------------------------------------------------------------- ";

    cout << endl;

    for ( i = 1; i <= days; ++i )
    {
        population = pow (( 1 + 0.01 * rate_of_increase ), i ) * starting_number;

        cout << " The size of the population of the No. " << i << " day is " << population << endl << endl;
    }

    cout << endl;

    cout << " ---------------------------------------------------------------------- ";

    cout << endl << endl;

    return 0;
}
