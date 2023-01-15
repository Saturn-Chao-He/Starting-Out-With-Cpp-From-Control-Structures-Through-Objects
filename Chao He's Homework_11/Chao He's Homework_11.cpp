# include <iostream>

using namespace std;

// Function Prototype
int * get_data( int );
void display_array( int *, int );

int main ()
{
    int num;

    cout << endl
         << '\t' << '\t' << '\t' << " Array Allocator " << endl;
    cout << " ****************************************************************************** "
         << endl;
    cout << " Please input the size of the array > ";
    cin >> num;
    cout << endl;
    int *array = NULL;
    array = get_data( num );

    //Display the array
    cout << " The dynamical array is ";
    for( int i = 0; i < num; i++ )
        cout << array[i] << "  ";
    cout << endl << endl;

    delete [] array;
    array = NULL;
    return 0;
}

int * get_data( int number)
{
    int *arr = NULL;

    if( number <= 0 )
        return NULL;

    arr = new int( number );

    for( int i = 0; i < number; i++ )
    {
        cout << " Please input the data > ";
        cin >> arr[i];
        cout << endl;
    }

    return arr;

}

