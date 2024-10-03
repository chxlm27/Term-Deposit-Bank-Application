#ifndef BANK_H
#define BANK_H

#include <string>

class Bank {
private:
    double threeMonths, sixMonths, twelveMonths, twentyFourMonths;

public:
    double getThreeMonths() const;
    void setThreeMonths(double value);

    double getSixMonths() const;
    void setSixMonths(double value);

    double getTwelveMonths() const;
    void setTwelveMonths(double value);

    double getTwentyFourMonths() const;
    void setTwentyFourMonths(double value);

    double calculateAmount(int option, double amount) const;

    virtual void displayName() const = 0;
    virtual void displayMessage() const = 0;

    virtual ~Bank() {}
};

#endif
