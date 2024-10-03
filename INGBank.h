#ifndef INGBANK_H
#define INGBANK_H

#include "Bank.h"

class INGBank : public Bank {
public:
    INGBank();
    void displayName() const override;
    void displayMessage() const override;
};

#endif
