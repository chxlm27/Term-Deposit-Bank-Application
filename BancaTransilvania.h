#ifndef BANCATRANSILVANIA_H
#define BANCATRANSILVANIA_H

#include "Bank.h"

class BancaTransilvania : public Bank {
public:
    BancaTransilvania();
    void displayName() const override;
    void displayMessage() const override;
};

#endif
