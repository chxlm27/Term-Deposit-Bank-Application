#ifndef BRDBANK_H
#define BRDBANK_H

#include "Bank.h"

class BRDBank : public Bank {
public:
    BRDBank();
    void displayName() const override;
    void displayMessage() const override;
};

#endif
