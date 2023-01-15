//******************************************************************************
// Computer Science 50X2
// Fall 2019
// Assignment # 08
// Due Date: Monday, September 23
// Instructor: Dr. Jeff Jenness
// Programmer: Chao He
// Description: Monkey Business. Input the data of monkey's diet, calculate the
//              average of all monkeys and find the least and greatest of each
//              monkey.
// Input: amount[3][5]
// Output: Table of Data, average, least_amount, greatest_amount
//******************************************************************************

# include <iostream>
# include <iomanip>

using namespace std;

int main ()
{
    // Variables
    double amount[3][5];
    int day_number = 0;
    int monkey_number = 0;


    cout << '\t' << '\t'<<" Inputing data of Monkey's Diet " << endl;
    cout << " ****************************************************************************** "
         << endl;

    //Input the amount of each day
    for ( monkey_number = 0; monkey_number < 3; monkey_number++ )
    {
        for ( day_number = 0; day_number < 5; day_number++)
        {
            do
            {
                cout << " Please input the amount of day " << ( day_number+1 )
                     << " for monkey " << ( monkey_number+1 ) << " > ";

                cin >> amount[monkey_number][day_number];

                if ( amount[monkey_number][day_number] < 0 )
                    cout << " Invalid input, please do not input an negative amount, input again. "
                         << endl;
            }
            while ( amount[monkey_number][day_number] < 0 );
        }
    }
    cout << endl << endl;

    // Display the table
    cout << '\t' << '\t' <<" Report of Monkey's Diet " << endl;
    cout << " ****************************************************************************** "
         << endl;

    for ( monkey_number = 0; monkey_number < 3; monkey_number++ )
    {
        cout << " Monkey " <<  ( monkey_number+1 ) << "  ";

        for ( day_number = 0; day_number < 5; day_number++ )
        {

            cout << setw(4) << fixed << showpoint << setprecision(1)
                 << amount[monkey_number][day_number] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    cout << " ****************************************************************************** "
         << endl;

    // Calculate the average amount of food eaten per day by the whole family of monkeys
    double sum = 0;
    double average;

    for ( monkey_number = 0; monkey_number < 3; monkey_number++ )
    {
        for ( day_number = 0; day_number < 5; day_number++ )
        {
            sum += amount[monkey_number][day_number];
        }
    }
    average = sum / (3*5);
    cout << " The average amount of food eaten per day by the whole family of monkeys is "
         << average << endl;

    // Find the least amount of food eaten during the week by any one monkey
    double least_amount;

    for ( monkey_number = 0; monkey_number < 3; monkey_number++ )
    {
        cout << " The least amount of food eaten during the week for monkey "
             << ( monkey_number+1 ) << " is ";

        least_amount = amount[monkey_number][0];
        for ( day_number = 1; day_number < 5; day_number++ )
        {
            if ( least_amount > amount[monkey_number][day_number] )
                 least_amount = amount[monkey_number][day_number];
        }
        cout << least_amount;
        cout << endl;
    }

    // Find the greatest amount of food eaten during the week by any one monkey
    double greatest_amount;

    for ( monkey_number = 0; monkey_number < 3; monkey_number++ )
    {
        cout << " The greatest amount of food eaten during the week for monkey "
             << ( monkey_number+1 ) << " is ";

        greatest_amount = amount[monkey_number][0];
        for ( day_number = 1; day_number < 5; day_number++ )
        {
            if ( greatest_amount < amount[monkey_number][day_number] )
                 greatest_amount = amount[monkey_number][day_number];
        }
        cout << greatest_amount;
        cout << endl;
    }
    cout << endl << endl;

    return 0;
}
