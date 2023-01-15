//******************************************************************************
//
// Computer Science 50X2
//
// Fall 2019
//
// Assignment # 06
//
// Due Date: Monday, September 16
//
// Instructor: Dr. Jeff Jenness
//
// Programmer: Chao He
//
// Description: To calculate the average of four highest scores after dropped
//              the lowest score of five test scores
//
// Input: score1, score2, score3, score4, score5
//
// Output: lowest, average
//
//******************************************************************************

# include <iostream>
# include <iomanip>

using namespace std;

// Function Prototype

void get_score ( double & );

void calc_average ( double, double, double, double, double );

double find_lowest ( double, double, double, double, double );

// ******************************************************************************
// Function Name : main
//
// Description: to call get_score function to store scores each input and then call
//              calc_average function to do calculation.
//
// ******************************************************************************
int main ( void )
{
    cout << " ****************************************************************************** " << endl;
    cout << '\t' << " Lowest Score Drop " << endl << endl;

    double score1, score2, score3, score4, score5;

    get_score ( score1 );
    cout << endl;

    get_score ( score2 );
    cout << endl;

    get_score ( score3 );
    cout << endl;

    get_score ( score4 );
    cout << endl;

    get_score ( score5 );
    cout << endl;

    calc_average ( score1, score2, score3, score4, score5 );

    cout << endl << endl;

    cout << " ****************************************************************************** ";

    return 0;
}

// ******************************************************************************
// Function Name: get_score
//
// Description: getting five scores of test through input five scores, then store them.
//
// parameters: double &score, it is used to store the score
//
// ******************************************************************************
void get_score ( double &score )
{
    do
    {
      cout << " Please input the test scores > ";

      cin >> score; // storing five scores

      if (score < 0 || score > 100)
      {
          cout << " Invalid input. Please input a number less than 100 or larger than or equal to 0 ";
      }

    }while (score < 0 || score > 100);
}

// ******************************************************************************
// Function Name: calc_average
//
// Description: Calculating the average of four highest scores through calling the
//              "find_lowest" function to find and delete it when do sum and
//               calculate the average
//
// output: average, to output the average of the four highest cores
//
// parameters: double s1, double s2, double s3, double s4, double s5. These are used to do calculation.
//
// ******************************************************************************
void calc_average (double s1, double s2, double s3, double s4, double s5)
{
    double lowest, average;

    lowest = find_lowest ( s1, s2, s3, s4, s5 );

    cout << endl;

    average = ( s1 + s2 + s3 + s4 + s5 - lowest ) / 4.0;

    cout << setw (4) << setprecision (2) << fixed << showpoint;

    cout << " The average of the four highest scores is " << average << endl << endl;

}

// ******************************************************************************
// Function name: find_lowest
// Description: Finding the lowest scores from the five scores through comparing
//              every score and assign the smaller score to "lowest" every time
//
//
// output: lowest, to output the lowest score that should be dropped
//
// parameters: double s1, double s2, double s3, double s4, double s5. These are
//             used to do comparison.
//
// returns: lowest, this function is used to find the lowest score to do further
//          dropping in calculation
// ******************************************************************************
double find_lowest ( double s1, double s2, double s3, double s4, double s5 )
{
    double lowest = s1;

    if ( s2 < lowest)

        lowest = s2;

    if ( s3 < lowest)

            lowest = s3;

    if ( s4 < lowest)

            lowest = s4;

    if ( s5 < lowest)

            lowest = s5;

    cout << " The lowest score that should be dropped is " << lowest << endl;

    return lowest;
}
