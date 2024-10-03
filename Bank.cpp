#include "Bank.h"

double Bank::getThreeMonths() const { return threeMonths; }
void Bank::setThreeMonths(double value) { threeMonths = value; }

double Bank::getSixMonths() const { return sixMonths; }
void Bank::setSixMonths(double value) { sixMonths = value; }

double Bank::getTwelveMonths() const { return twelveMonths; }
void Bank::setTwelveMonths(double value) { twelveMonths = value; }

double Bank::getTwentyFourMonths() const { return twentyFourMonths; }
void Bank::setTwentyFourMonths(double value) { twentyFourMonths = value; }

double Bank::calculateAmount(int option, double amount) const {
    const double tax = 0.1;
    double interest = 0.0;

    switch (option) {
    case 1:
        interest = amount * (getThreeMonths() / 100) / 4;
        break;
    case 2:
        interest = amount * (getSixMonths() / 100) / 2;
        break;
    case 3:
        interest = amount * (getTwelveMonths() / 100);
        break;
    case 4:
        interest = amount * (getTwentyFourMonths() / 100) * 2;
        break;
    default:
        return 0.0;
    }
    interest -= (interest * tax);
    return amount + interest;
}
