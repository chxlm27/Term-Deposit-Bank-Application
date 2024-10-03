#include "RaiffeisenBank.h"
#include "ColorConstants.h"
#include <iostream>
#include <iomanip>

using namespace std;

RaiffeisenBank::RaiffeisenBank() {
    setThreeMonths(4.80);
    setSixMonths(5.00);
    setTwelveMonths(5.00);
    setTwentyFourMonths(5.30);
}

void RaiffeisenBank::displayName() const {
    cout << YELLOW << "                                   ----- RAIFFEISEN BANK -----\n\n\n" << RESET;
}

void RaiffeisenBank::displayMessage() const {
    cout << RED << "At RaiffeisenBank, we offer the following term deposits:\n\n" << RESET;
    cout << GREEN << "1. Three months deposit (3 Months RON):                    " << getThreeMonths() << "% annually.\n" << RESET;
    cout << YELLOW << "2. Six months flexi-deposit (6 Months RON):                " << getSixMonths() << "% annually.\n" << RESET;
    cout << CYAN << "3. Twelve months deposit (12 Months RON):                  " << getTwelveMonths() << "% annually.\n" << RESET;
    cout << ORANGE << "4. Twenty four months deposit (24 Months RON):             " << getTwentyFourMonths() << "% annually.\n\n\n" << RESET;
}
