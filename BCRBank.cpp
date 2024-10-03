#include "BCRBank.h"
#include "ColorConstants.h"
#include <iostream>
#include <iomanip>

using namespace std;

BCRBank::BCRBank() {
    setThreeMonths(4.20);
    setSixMonths(4.60);
    setTwelveMonths(5.00);
    setTwentyFourMonths(5.10);
}

void BCRBank::displayName() const {
    cout << YELLOW << "                                   ----- BCR -----\n\n\n" << RESET;
}

void BCRBank::displayMessage() const {
    cout << RED << "At BCR, we offer the following term deposits:\n\n" << RESET;
    cout << GREEN << "1. Three months deposit (3 Months RON):                " << getThreeMonths() << "% annually.\n" << RESET;
    cout << YELLOW << "2. Six months flexi-deposit (6 Months RON):            " << getSixMonths() << "% annually.\n" << RESET;
    cout << CYAN << "3. Twelve months deposit (12 Months RON):              " << getTwelveMonths() << "% annually.\n" << RESET;
    cout << ORANGE << "4. Twenty four months deposit (24 Months RON):         " << getTwentyFourMonths() << "% annually.\n\n\n" << RESET;
}
