#include <iostream>
#include <memory>
#include <map>

using namespace std;

class Bank {
public:
    virtual void displayName() const = 0;
    virtual void displayMessage() const = 0;
    virtual ~Bank() {}
};

class RaiffeisenBank : public Bank {
public:
    void displayName() const override {
        cout << "                                   ----- RAIFFEISEN BANK -----\n\n\n";
    }
    void displayMessage() const override {
        cout << "At RaiffeisenBank, we offer the following term deposits:\n";
        cout << "1. Three months deposit (3 Months RON):                    4.80% annually.\n";
        cout << "2. Six months flexi-deposit (6 Months RON):                5.00% annually.\n";
        cout << "3. Twelve months deposit (12 Months RON):                  5.00% annually.\n";
        cout << "4. Twenty four months deposit (24 Months RON):             5.30% annually.\n";
    }
};

class BancaTransilvania : public Bank {
public:
    void displayName() const override {
        cout << "                                   ----- BANCA TRANSILVANIA -----\n\n\n";
    }
    void displayMessage() const override {
        cout << "At Banca Transilvania, we offer the following term deposits:\n";
        cout << "1. Three months deposit (3 Months RON):                   4.70% annually.\n";
        cout << "2. Six months flexi-deposit (6 Months RON):               4.95% annually.\n";
        cout << "3. Twelve months deposit (12 Months RON):                 5.20% annually.\n";
        cout << "4. Twenty four months deposit (24 Months RON):            5.25% annually.\n";
    }
};

class INGBank : public Bank {
public:
    void displayName() const override {
        cout << "                                   ----- ING -----\n\n\n";
    }
    void displayMessage() const override {
        cout << "At ING BANK, we offer the following term deposits:\n";
        cout << "1. Three months deposit (3 Months RON):                  4.10% annually.\n";
        cout << "2. Six months flexi-deposit (6 Months RON):              4.60% annually.\n";
        cout << "3. Twelve months deposit (12 Months RON):                5.00% annually.\n";
        cout << "4. Twenty four months deposit (24 Months RON):           5.20% annually.\n";
    }
};

class BCRBank : public Bank {
public:
    void displayName() const override {
        cout << "                                   ----- BCR -----\n\n\n";
    }
    void displayMessage() const override {
        cout << "At BCR, we offer the following term deposits:\n";
        cout << "1. Three months deposit (3 Months RON):                4.20% annually.\n";
        cout << "2. Six months flexi-deposit (6 Months RON):            4.60% annually.\n";
        cout << "3. Twelve months deposit (12 Months RON):              5.00% annually.\n";
        cout << "4. Twenty four months deposit (24 Months RON):         5.10% annually.\n";
    }
};

class BRDBank : public Bank {
public:
    void displayName() const override {
        cout << "                                   ----- BRD -----\n\n\n";
    }
    void displayMessage() const override {
        cout << "At BRD, we offer the following term deposits:\n";
        cout << "1. Three months deposit (3 Months RON):               3.85% annually.\n";
        cout << "2. Six months flexi-deposit (6 Months RON):           4.00% annually.\n";
        cout << "3. Twelve months deposit (12 Months RON):             4.30% annually.\n";
        cout << "4. Twenty four months deposit (24 Months RON):        4.40% annually.\n";
    }
};

unique_ptr<Bank> createBank(int option) {
    switch (option) {
    case 1: return make_unique<RaiffeisenBank>();
    case 2: return make_unique<BancaTransilvania>();
    case 3: return make_unique<INGBank>();
    case 4: return make_unique<BCRBank>();
    case 5: return make_unique<BRDBank>();
    default: return nullptr;
    }
}

int main() {
    int option;

    cout << "Choose a bank from the following list:\n\n\n";
    cout << "1. Raiffeisen Bank\n";
    cout << "2. Banca Transilvania\n";
    cout << "3. ING\n";
    cout << "4. BCR\n";
    cout << "5. BRD\n";
    cout << "\n\nEnter an option: ";
    cin >> option;

    system("cls");

    unique_ptr<Bank> bank = createBank(option);

    if (bank) {
        bank->displayName();
        bank->displayMessage();
    }
    else {
        cout << "Invalid option. Please choose a number between 1 and 5.\n";
    }

    return 0;
}
