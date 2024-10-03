#include "BRDBank.h"
#include "ColorConstants.h"
#include <iostream>

using namespace std;

BRDBank::BRDBank() {
    setThreeMonths(3.85);
    setSixMonths(4.25);
    setTwelveMonths(4.75);
    setTwentyFourMonths(5.00);
}

void BRDBank::displayName() const {
    cout << YELLOW << "                                   ----- BRD -----\n\n\n" << RESET;
}

void BRDBank::displayMessage() const {
    cout << RED << "At BRD, we offer the following term deposits:\n\n" << RESET;
    cout << GREEN << "1. Three months deposit (3 Months RON):                " << getThreeMonths() << "% annually.\n" << RESET;
    cout << YELLOW << "2. Six months flexi-deposit (6 Months RON):            " << getSixMonths() << "% annually.\n" << RESET;
    cout << CYAN << "3. Twelve months deposit (12 Months RON):              " << getTwelveMonths() << "% annually.\n" << RESET;
    cout << ORANGE << "4. Twenty four months deposit (24 Months RON):         " << getTwentyFourMonths() << "% annually.\n\n\n" << RESET;
}
