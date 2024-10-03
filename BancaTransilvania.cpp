#include "BancaTransilvania.h"
#include "ColorConstants.h"
#include <iostream>
#include <iomanip>

using namespace std;

BancaTransilvania::BancaTransilvania() {
    setThreeMonths(4.70);
    setSixMonths(4.95);
    setTwelveMonths(5.20);
    setTwentyFourMonths(5.35);
}

void BancaTransilvania::displayName() const {
    cout << YELLOW << "                                   ----- BANCA TRANSILVANIA -----\n\n\n" << RESET;
}

void BancaTransilvania::displayMessage() const {
    cout << RED << "At Banca Transilvania, we offer the following term deposits:\n\n" << RESET;
    cout << GREEN << "1. Three months deposit (3 Months RON):                   " << getThreeMonths() << "% annually.\n" << RESET;
    cout << YELLOW << "2. Six months flexi-deposit (6 Months RON):               " << getSixMonths() << "% annually.\n" << RESET;
    cout << CYAN << "3. Twelve months deposit (12 Months RON):                 " << getTwelveMonths() << "% annually.\n" << RESET;
    cout << ORANGE << "4. Twenty four months deposit (24 Months RON):            " << getTwentyFourMonths() << "% annually.\n\n\n" << RESET;
}
