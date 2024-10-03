#ifndef RAIFFEISENBANK_H
#define RAIFFEISENBANK_H

#include "Bank.h"

class RaiffeisenBank : public Bank {
public:
    RaiffeisenBank();
    void displayName() const override;
    void displayMessage() const override;
};

#endif
