#ifndef BANKMENU_H
#define BANKMENU_H

#include <iostream>
#include <memory>
#include <string>
#include "Bank.h"
#include "RaiffeisenBank.h"
#include "BancaTransilvania.h"
#include "INGBank.h"
#include "BCRBank.h"
#include "BRDBank.h"
#include "ColorConstants.h"

using namespace std;

void printDetails();
unique_ptr<Bank> createBank(int option);
void handleBankMenu();

#endif
