//******************************************************************************
// Computer Science 50X2
// Fall 2019
// Assignment # 09
// Due Date: Monday, September 23
// Instructor: Dr. Jeff Jenness
// Programmer: Chao He
// Description: Input nine numbers 1 through 9 exactly, then test if the square
//              is a Lo Shu Magic Square through calculate the sum of each row,
//              column and diagonal.
// Input: arr[3][3]
// Output: sum_row [], sum_column [], sum_diagonal [] and the result of determination
//******************************************************************************

# include <iostream>

using namespace std;

// Function Prototype
void get_number (int [][3], int );
void test ( int [][3], int);

int main ()
{
    // Variables
    int arr[3][3];

    cout << '\t' << '\t'<<" Lo Shu Magic Square " << endl;
    cout << " ****************************************************************************** "
         << endl;
    cout << " Please input nine numbers 1 through 9 exactly " << endl;
    get_number ( arr, 3);

    test ( arr, 3 );

    cout << endl << endl;

    return 0;
}

//Input the two-dimensional array
void get_number (int arr[][3], int row )
{
    for ( int row = 0; row < 3; row++ )
    {
        for ( int column = 0; column < 3; column++)
        {
            cout << " Input the number for row " << row+1 << " column" << column+1
                 << " of the Lo Shu Magic Square" << " > ";
            cin >> arr[row][column];
        }
    }
    cout << endl;
}
// Function for testing if the array is a Lo Shu Magic Square
void test ( int arr[][3], int x )
{
    int sum_row [3] = {0,0,0};
    int sum_column [3] = {0,0,0};
    int sum_diagonal [2] = {0,0};

    // Sum of row
    for ( int x = 0; x < 3; x++ )
    {
        for ( int y = 0; y < 3; y++)
        {
            sum_row [x] = sum_row [x] + arr[x][y];
        }
    }
    cout << " The sum of each row is " << endl;
    cout << "  " << sum_row [0] << endl
         << "  " << sum_row [1] << endl
         << "  " << sum_row [2] << endl;

    // Sum of column
    for ( int y = 0; y < 3; y++ )
    {
        for ( int x = 0; x < 3; x++)
        {
            sum_column [y] = sum_column [y] + arr[x][y];
        }
    }
    cout << " The sum of each column is " << endl;
    cout << "  " << sum_column [0] << endl
         << "  " << sum_column [1] << endl
         << "  " << sum_column [2] << endl;

    // Sum of sum_diagonal
    cout << " The sum of each diagonal is " << endl;
    sum_diagonal [0] = arr[0][0] + arr[1][1] + arr[2][2];
    sum_diagonal [1] = arr[0][2] + arr[1][1] + arr[2][0];

    cout << "  " << sum_diagonal [0] << endl;
    cout << "  " << sum_diagonal [1] << endl;
    cout << endl;

    // Determination
    if (   ( sum_row [0] == sum_row [1] && sum_row [1] == sum_row [2] )
        && ( sum_column [0] == sum_column [1] && sum_column [1] == sum_column [2] )
        && ( sum_diagonal [0] == sum_diagonal [1]) )

            cout << " This two-dimensional array is a Lo Shu Magic Square. " << endl;
    else

            cout << " This two-dimensional array is not a  Lo Shu Magic Square. " << endl;
}
