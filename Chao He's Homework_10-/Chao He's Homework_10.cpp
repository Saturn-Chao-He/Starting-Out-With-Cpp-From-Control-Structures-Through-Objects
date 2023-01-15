//******************************************************************************
// Computer Science 50X2
// Fall 2019
// Assignment # 10
// Due Date: Monday, September 30
// Instructor: Dr. Jeff Jenness
// Programmer: Chao He
// Description: a program with two identical arrays and sort them using bubble sort and selection sort.
// Input: two identical array
// Output: two unsorted arrays and two sorted arrays with each step
//******************************************************************************

# include <iostream>
# include <iomanip>

using namespace std;

// Function Prototype
void display_array1 ( int [], int );
void display_array2 ( int [], int );
void bubble_sort    ( int [], int );
void selection_sort ( int [], int );
void swap_elemt ( int &, int & );

// constant variables
const int ARR_SIZE = 8;

int main ()
{
    // Arrays
    int array1[ARR_SIZE] = {12,8,30,6,23,3,1,10};
    int array2[ARR_SIZE] = {18,7,33,16,13,5,2,8};


    cout << endl
         << '\t' << '\t' << '\t' << " Two methods of sorting " << endl;
    cout << " ****************************************************************************** "
         << endl;
    cout << right << setw(4);

    // Bubble sort
    display_array1 ( array1, ARR_SIZE );
    bubble_sort    ( array1, ARR_SIZE );

    cout << " ****************************************************************************** "
         << endl;

    // Selection sort
    display_array2 ( array2, ARR_SIZE );
    selection_sort ( array2, ARR_SIZE );

    return 0;
}

void display_array1 ( int arr1[], int ARR_SIZE )
{
    cout << " The first array is  " << endl;

    for ( int i = 0; i < ARR_SIZE; i++ )
         cout << "  "<< arr1[i] << "  ";
    cout << endl;
    cout << " ********************************************* "
         << endl;
}

void bubble_sort ( int a1[], int ARR_SIZE )
{
    for ( int max_elemt = ARR_SIZE - 1 ; max_elemt > 0; max_elemt -- )
    {
        for ( int j = 0; j < max_elemt; j++ )
        {
            if ( a1 [j] > a1 [j+1] )
                swap_elemt( a1 [j], a1 [j+1]  );
        }

        cout << " Each step : " << endl;
        for ( int i = 0; i < 8; i++ )
        cout << "  " << a1[i] << "  ";
        cout << endl;
    }

    cout << " ********************************************* "
         << endl;
    cout << " The sorted array is " << endl;
    for ( int i = 0; i < 8; i++ )
        cout << "  " << a1[i] << "  ";
    cout << endl << endl;
}

void display_array2 ( int arr2[], int ARR_SIZE )
{
    cout << " The second array is " << endl;

    for ( int i = 0; i < ARR_SIZE; i++ )
         cout << "  " << arr2[i] << "  ";
    cout << endl;
    cout << " ********************************************* "
         << endl;
}

void selection_sort ( int a2[], int ARR_SIZE )
{
    int minIndex, minValue;

    for ( int start = 0; start < ( ARR_SIZE - 1 ); start++ )
    {
        minIndex = start;
        minValue = a2[start];
        for ( int index = start + 1; index < ARR_SIZE; index++ )
        {
            if ( a2[index] < minValue )
            {
                minValue = a2[index];
                minIndex = index;
            }
        }
        swap_elemt ( a2[minIndex], a2[start] );

        cout << " Each step : " << endl;
        for (int i = 0; i<8; i++)
        cout << "  " << a2[i] << "  ";
        cout << endl;
    }

    cout << " ********************************************* "
         << endl;
    cout << " The sorted array is " << endl;
    for (int i = 0; i<8; i++)
        cout << "  " << a2[i] << "  ";
    cout << endl << endl;
}

void swap_elemt ( int &a, int &b )
{
    int t;
    t = a;
    a = b;
    b = t;
}

