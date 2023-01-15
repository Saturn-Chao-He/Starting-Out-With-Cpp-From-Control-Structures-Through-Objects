//Specificaton file for the Mortgage class
#ifndef MORTGAGE_H
#define MORTGAGE_H

class Mortgage
{
private:
    double loan;
    double rate;
    int year;

public:
    Mortgage()
    { loan = 0.0; rate = 0.0; year = 0; }
 
    double getLoanAmount() const
    { return loan; }

    double getInterestRate() const
    { return rate;}

    double getYear() const
    { return year; }

    void setLoanAmount(double l);
    void setInterestRate(double r);
    void setYear(double y);
    double getPayment() const;
    double getTotalAmount() const;
};
#endif