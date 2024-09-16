#include <iostream>
#include <memory>
#include <map>

using namespace std;

class Bank {
private:
    double threeMonths, sixMonths, twelveMonths, twentyFourMonths;

public:
    double getThreeMonths() const {
        return threeMonths;
    }
    void setThreeMonths(double value) {
        threeMonths = value;
    }

    double getSixMonths() const {
        return sixMonths;
    }
    void setSixMonths(double value) {
        sixMonths = value;
    }

    double getTwelveMonths() const {
        return twelveMonths;
    }
    void setTwelveMonths(double value) {
        twelveMonths = value;
    }

    double getTwentyFourMonths() const {
        return twentyFourMonths;
    }
    void setTwentyFourMonths(double value) {
        twentyFourMonths = value;
    }

    double calculateAmount(int option, double amount) const {
        const double tax = 0.1;
        switch (option) {
        case 1:
            amount = amount * (getThreeMonths() / 100) / 4;
            break;
        case 2:
            amount = amount * (getSixMonths() / 100) / 2;
            break;
        case 3:
            amount = amount * (getTwelveMonths() / 100);
            break;
        case 4:
            amount = amount * (getTwentyFourMonths() / 100) * 4;
            break;
        default:
            return 0.0;
        }
        amount -= (amount * tax);
        return amount;
    }

    virtual void displayName() const = 0;
    virtual void displayMessage() const = 0;
    virtual ~Bank() {}
};

class RaiffeisenBank : public Bank {
public:
    const double threeMonths = 4.80;
    const double sixMonths = 5.00;
    const double twelveMonths = 5.00;
    const double twentyFourMonths = 5.30;

    RaiffeisenBank() {
        setThreeMonths(4.80);
        setSixMonths(5.00);
        setTwelveMonths(5.00);
        setTwentyFourMonths(5.30);
    }

    void displayName() const override {
        cout << "                                   ----- RAIFFEISEN BANK -----\n\n\n";
    }
    void displayMessage() const override {
        cout << "At RaiffeisenBank, we offer the following term deposits:\n\n";
        cout << "1. Three months deposit (3 Months RON):                    4.80% annually.\n";
        cout << "2. Six months flexi-deposit (6 Months RON):                5.00% annually.\n";
        cout << "3. Twelve months deposit (12 Months RON):                  5.00% annually.\n";
        cout << "4. Twenty four months deposit (24 Months RON):             5.30% annually.\n\n\n";
    }
};

class BancaTransilvania : public Bank {
public:
    const double threeMonths = 4.70;
    const double sixMonths = 4.95;
    const double twelveMonths = 5.20;
    const double twentyFourMonths = 5.35;

    BancaTransilvania()
    {
        setThreeMonths(4.70);
        setSixMonths(4.95);
        setTwelveMonths(5.20);
        setTwentyFourMonths(5.25);
    }

    void displayName() const override {
        cout << "                                   ----- BANCA TRANSILVANIA -----\n\n\n";
    }
    void displayMessage() const override {
        cout << "At Banca Transilvania, we offer the following term deposits:\n\n";
        cout << "1. Three months deposit (3 Months RON):                   4.70% annually.\n";
        cout << "2. Six months flexi-deposit (6 Months RON):               4.95% annually.\n";
        cout << "3. Twelve months deposit (12 Months RON):                 5.20% annually.\n";
        cout << "4. Twenty four months deposit (24 Months RON):            5.25% annually.\n\n\n";
    }
};

class INGBank : public Bank {
public:
    const double threeMonths = 4.10;
    const double sixMonths = 4.60;
    const double twelveMonths = 5.00;
    const double twentyFourMonths = 5.20;

    INGBank()
    {
        setThreeMonths(4.10);
        setSixMonths(4.60);
        setTwelveMonths(5.00);
        setTwentyFourMonths(5.20);
    }

    void displayName() const override {
        cout << "                                   ----- ING -----\n\n\n";
    }
    void displayMessage() const override {
        cout << "At ING BANK, we offer the following term deposits:\n\n";
        cout << "1. Three months deposit (3 Months RON):                  4.10% annually.\n";
        cout << "2. Six months flexi-deposit (6 Months RON):              4.60% annually.\n";
        cout << "3. Twelve months deposit (12 Months RON):                5.00% annually.\n";
        cout << "4. Twenty four months deposit (24 Months RON):           5.20% annually.\n\n\n";
    }
};

class BCRBank : public Bank {
public:
    const double threeMonths = 4.20;
    const double sixMonths = 4.60;
    const double twelveMonths = 5.00;
    const double twentyFourMonths = 5.10;

    BCRBank()
    {
        setThreeMonths(4.20);
        setSixMonths(4.60);
        setTwelveMonths(5.00);
        setTwentyFourMonths(5.10);
    }

    void displayName() const override {
        cout << "                                   ----- BCR -----\n\n\n";
    }
    void displayMessage() const override {
        cout << "At BCR, we offer the following term deposits:\n\n";
        cout << "1. Three months deposit (3 Months RON):                4.20% annually.\n";
        cout << "2. Six months flexi-deposit (6 Months RON):            4.60% annually.\n";
        cout << "3. Twelve months deposit (12 Months RON):              5.00% annually.\n";
        cout << "4. Twenty four months deposit (24 Months RON):         5.10% annually.\n\n\n";
    }
};

class BRDBank : public Bank {
public:
    const double threeMonths = 3.85;
    const double sixMonths = 4.00;
    const double twelveMonths = 4.30;
    const double twentyFourMonths = 4.40;
    
    BRDBank()
    {
        setThreeMonths(3.85);
        setSixMonths(4.00);
        setTwelveMonths(4.30);
        setTwentyFourMonths(4.40);
    }

    void displayName() const override {
        cout << "                                   ----- BRD -----\n\n\n";
    }
    void displayMessage() const override {
        cout << "At BRD, we offer the following term deposits:\n\n";
        cout << "1. Three months deposit (3 Months RON):               3.85% annually.\n";
        cout << "2. Six months flexi-deposit (6 Months RON):           4.00% annually.\n";
        cout << "3. Twelve months deposit (12 Months RON):             4.30% annually.\n";
        cout << "4. Twenty four months deposit (24 Months RON):        4.40% annually.\n\n\n";
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
        int option;
        double amount;
        bank->displayName();
        bank->displayMessage();
        cout << "Choose a deposit type: ";
        cin >> option;
        cout << '\n';
        cout << "Enter the amount of RON for the deposit: ";
        cin >> amount;
        cout << "The accumulated wealth is: " << bank->calculateAmount(option,amount) << " RON\n";
    }
    else {
        cout << "Invalid option. Please choose a number between 1 and 5.\n";
    }

    return 0;
}
