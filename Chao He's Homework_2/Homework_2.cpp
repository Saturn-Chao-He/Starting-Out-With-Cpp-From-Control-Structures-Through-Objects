/*
* Program: Homework_2.cpp
* Date: 2019-08-27
* Purpose: Calculate Monthly Payments
* Input: Loan Amount, Monthly Interest Rate, Number of Payments
* Output: Monthly Payment, Amount Paid Back, Interest Paid
* Author: Chao He  50542901
*/

# include <iostream>
# include <cmath>
# include <iomanip>

using namespace std;

int main( void )
{
    double Loan_Amount, Monthly_Interest_Rate, Number_of_Payments;

    double Monthly_Payment, Amount_Paid_Back, Interest_Paid;

    cout << " Please input the Loan Amount > ";

    cin >> Loan_Amount;

    cout << " Please input the Monthly Interest Rate > ";

    cin >> Monthly_Interest_Rate;

    cout << " Please input the Number of Payments > ";

    cin >> Number_of_Payments;

    cout << endl << endl;

    Monthly_Payment = (Loan_Amount) * (Monthly_Interest_Rate * 0.01)
                      * pow( ( 1 + Monthly_Interest_Rate *0.01 ), Number_of_Payments)
                      / ( ( pow( (1+ (Monthly_Interest_Rate * 0.01) ), Number_of_Payments) ) - 1);

    Amount_Paid_Back = (Number_of_Payments) * (Monthly_Payment);

    Interest_Paid = (Amount_Paid_Back) - (Loan_Amount);



    cout << left << setw(25) << " Loan Amount: "
         << right << setw(2) << '$' << right << setw(10)
         << setiosflags(ios::fixed) << setprecision(2)
         << Loan_Amount <<endl;

    cout << left << setw(25) << " Monthly Interest Rate: "
         << right << setw(11) << setiosflags(ios::fixed)
         << setprecision(0) << Monthly_Interest_Rate
         << '%' <<endl;

    cout << left << setw(25) << " Number of Payments: "
         << right << setw(12) << setiosflags(ios::fixed)
         << setprecision(0) << Number_of_Payments <<endl;

    cout << left << setw(25) << " Monthly Payment: "
         << right << setw(2) << '$' << right << setw(10)
         << setiosflags(ios::fixed) << setprecision(2)
         << Monthly_Payment <<endl;

    cout << left << setw(25) << " Amount Paid Back: "
         << right << setw(2) << '$' << right << setw(10)
         << setiosflags(ios::fixed) << setprecision(2)
         << Amount_Paid_Back <<endl;

    cout << left << setw(25) << " Interest Paid: "
         << right << setw(2) << '$' << right << setw(10)
         << setiosflags(ios::fixed) << setprecision(2)
         << Interest_Paid <<endl;

    return 0;
}

/*
The result is:
-----------------------------------------------------------------
 Please input the Loan Amount > 10000
 Please input the Monthly Interest Rate > 1
 Please input the Number of Payments > 36


 Loan Amount:             $  10000.00
 Monthly Interest Rate:            1%
 Number of Payments:               36
 Monthly Payment:         $    332.14
 Amount Paid Back:        $  11957.15
 Interest Paid:           $   1957.15
-------------------------------------------------------------------
*/
