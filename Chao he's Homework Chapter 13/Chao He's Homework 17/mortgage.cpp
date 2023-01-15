//******************************************************************************
// Computer Science 50X2
// Fall 2019
// Assignment # 17
// Due Date: Monday, November 11
// Instructor: Dr. Jeff Jenness
// Programmer: Chao He
// Description: Design a class that will determine the monthly payment on a home mortgage. 
//              Get the data of mortgage and calculate monthly pament and total amount paid to the bank.
// Input : loanAmount interestRate Year
// Output: payment1.getPayment(), payment1.getTotalAmount()
//******************************************************************************

// main function file for the  Mortgage class
#include <iostream>
#include "mortgage.hpp"
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

void Mortgage::setLoanAmount(double l)
{
    if( l >= 0 )
        loan = l;
    else
    {
        cout << endl << " Invalid loan amount. " << endl << endl << endl;
        exit(EXIT_FAILURE);
    }
    
}
void Mortgage::setInterestRate(double r)
{
    if( r >= 0 )
        rate = r;
    else
    {
        cout << " Invalid interest rate. " << endl;
    }
}
void Mortgage::setYear(double y)
{
    if( y >= 0 )
        year = y;
    else
    {
        cout << " Invalid year. " << endl;
    }
}
double Mortgage::getPayment() const
{
    return  (  (loan * (rate/12) * ( pow( (1+(rate/12)) , (12*year) ) )) / ( (pow( (1+(rate/12)) , (12*year) )) - 1 ) );
}

double Mortgage::getTotalAmount() const
{
    return getPayment() * year * 12; 
}

int main ()
{
    Mortgage payment1;
    double loanAmount;
    double interestRate;
    int Year;

    //Get the data
    cout << endl << '\t' << '\t' << " Mortgage Payment " << endl
         << "***************************************************************************" << endl << endl;

    cout << " Please input the loan amount > ";
    cin  >> loanAmount;
    payment1.setLoanAmount(loanAmount);
    cout << endl;

    cout << " Please input the interest rate > ";
    cin  >> interestRate;
    payment1.setInterestRate(interestRate);
    cout << endl;

    cout << " Please input the year > ";
    cin  >> Year;
    payment1.setYear(Year);
    cout << endl;

    //Display the result
    cout << showpoint << setprecision(2) << fixed << endl;
    cout << " The monthly payment is " << payment1.getPayment() << endl << endl
         << " The total amount that paid to the bank at the end of the loan period is " << endl << endl
         << " " << payment1.getTotalAmount() << endl << endl
         << endl << endl;

    return 0;
}