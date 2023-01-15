/*
* Program: Homework_3.cpp
* Date: 2019-08-29
* Purpose: Fat Gram Calculator
* Input: Total Calories, Fat Grams
* Output: Percentage
* Author: Chao He  50542901
*/

# include <iostream>

using namespace std;

int main(void)
{
    double Total_Calories, Fat_Grams;

    double Calories_of_Fat;

    double Percentage; // The percentage of the calories from fat in the food

    cout << "Please input the total calories of the food > ";

    do
    {
        cin >> Total_Calories;

        cout << endl;

        if ( Total_Calories <= 0 )

           cout << "Error, please input a number more than 0 > ";

    }while ( Total_Calories <= 0 );

    cout << endl;

    cout << "Please input the fat grams of the food > ";

    do
    {
        cin >> Fat_Grams;

        Calories_of_Fat = Fat_Grams * 9;

        cout << endl;

        if  ( Fat_Grams < 0 || Calories_of_Fat > Total_Calories )
        {
            cout << "Error, please search and input the right fat grams on food label,"
                 << endl << endl << " it should be more than 0 and less than "
                 << Total_Calories/9 << " > ";

        }

    }while ( Fat_Grams < 0 || Calories_of_Fat > Total_Calories );

    Percentage = 100 * ( 9 * Fat_Grams ) / (Total_Calories);

    cout << endl;

    cout << "The percentage of the calories from fat in the food is "
         << Percentage << '%' << endl << endl;

    if (Percentage < 30 )

         cout << "The food is low in fat."
              << endl << endl << endl << endl;

    else

         cout << "Do you want to be a pig? Just eat it."
              << endl << endl << endl << endl;

    return 0;
}
