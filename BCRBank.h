#ifndef BCRBANK_H
#define BCRBANK_H

#include "Bank.h"

class BCRBank : public Bank {
public:
    BCRBank();
    void displayName() const override;
    void displayMessage() const override;
};

#endif
