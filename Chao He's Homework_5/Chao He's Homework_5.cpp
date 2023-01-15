/*
* Program: Homework_5.cpp

* Date: 2019-09-05

* Purpose: Display the Population Bar Chart

* Input: the data in the People.txt

* Output: the population bar chart and the year

* Author: Chao He  50542901
*/

#include <iostream>
#include<fstream>

using namespace std;

int main(void)
{

    int i,j,k,l;

    int year = 1900;

    int data[6] = {0} ;

    int asterisk_number[6] = {0};

    ifstream infile;

    infile.open("People.txt");

    for ( int i = 0; i < 6 ; i++ )
	{
			infile >> data[i];
	}

	infile.close();

    for ( int k = 0; k < 6 ; k++ )
	{
			asterisk_number[k] = data[k]/1000;
	}

	cout << '\t' << " PRAIRIEVILLE POPULATION GROWTH " << endl

         << '\t' << "(each * represents 1,000 people) " << endl << endl;

        for ( l = 0; l < 6 ; l++ )
        {
            cout << " " << year + l*20 << "  ";

            for ( j = 0; j < asterisk_number[l] ; j++ )
            {
                cout << "*";
            }

            cout << endl;
        }

    return 0;
}
/*
The result is:
-----------------------------------------------------------------
         PRAIRIEVILLE POPULATION GROWTH
        (each * represents 1,000 people)

 1900  **
 1920  ****
 1940  *****
 1960  *******
 1980  *********
 2000  ************
-------------------------------------------------------------------
*/
