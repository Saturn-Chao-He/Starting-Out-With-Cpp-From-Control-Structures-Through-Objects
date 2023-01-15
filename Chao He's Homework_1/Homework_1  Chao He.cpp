/* Homework_1 of Chao He. Student ID: 50542901
   CS 5012.  Accelerated Structured Programming
   Dr. Jenness
*/

# include <iostream>
# include <cmath>

using namespace std;

int main(void)
{
    const double x = 2;
    const double pi = 3.141592657;

    double squ_area; // The area of square;
    double squ_peri; // The perimeter of square;
    double tri_area; // The area of triangle;
    double tri_peri; // The perimeter of triangle;
    double cir_area; // The area of circle;
    double cir_peri; // The perimeter of circle;

    squ_area = x * x;

    squ_peri = 4 * x;

    tri_area = 0.5*x * sqrt( x*x - ( 0.5*0.5 * x*x ) );

    tri_peri = 3 * x;

    cir_area = pi * ( 0.5*x ) * ( 0.5*x );

    cir_peri = pi * x;

    cout << " The value for X is: " << x << endl << endl;

    cout << '\t' << " A square with a side of length " << x << " has an area of "
         << squ_area << " and " << " a perimeter of " << squ_peri << endl << endl;

    cout << '\t' << " An equilateral triangle with a side of length " << x << " has an area of "
         << tri_area << endl << endl << " and " << " a perimeter of " << tri_peri << endl << endl;

    cout << '\t' << " A circle with a diameter of length " << x << " has an area of " << cir_area
         << " and " << endl << endl << " a perimeter of " << cir_peri << endl << endl;

    return 0;
}
