#include <iostream>
#include <memory>
#include <map>

using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string ORANGE = "\033[38;5;214m";

void printDetails()
{
    cout << MAGENTA << "Choose a bank from the following list:\n\n\n" << RESET;
    cout << YELLOW << "1. Raiffeisen Bank\n" << RESET;
    cout << GREEN << "2. Banca Transilvania\n" << RESET;
    cout << ORANGE << "3. ING\n" << RESET;
    cout << RED << "4. BCR\n" << RESET;
    cout << CYAN << "5. BRD\n" << RESET;
    cout << "\n\nEnter an option: ";
}

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
        cout << YELLOW<< "                                   ----- RAIFFEISEN BANK -----\n\n\n"<< RESET;
    }
    void displayMessage() const override {
        cout << RED<< "At RaiffeisenBank, we offer the following term deposits:\n\n"<<RESET;
        cout << GREEN<<"1. Three months deposit (3 Months RON):                    4.80% annually.\n"<< RESET;
        cout << YELLOW<<"2. Six months flexi-deposit (6 Months RON):                5.00% annually.\n" << RESET;
        cout << CYAN<<"3. Twelve months deposit (12 Months RON):                  5.00% annually.\n"<<RESET;
        cout << ORANGE<<"4. Twenty four months deposit (24 Months RON):             5.30% annually.\n\n\n"<<RESET;
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
        cout << ORANGE<<"                                   ----- BANCA TRANSILVANIA -----\n\n\n"<<RESET;
    }
    void displayMessage() const override {
        cout << RED << "At Banca Transilvania, we offer the following term deposits:\n\n"<< RESET;
        cout << GREEN << "1. Three months deposit (3 Months RON):                   4.70% annually.\n" << RESET;
        cout << YELLOW << "2. Six months flexi-deposit (6 Months RON):               4.95% annually.\n"<<RESET;
        cout << CYAN << "3. Twelve months deposit (12 Months RON):                 5.20% annually.\n"<<RESET;
        cout << ORANGE << "4. Twenty four months deposit (24 Months RON):            5.25% annually.\n\n\n"<<RESET;
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
        cout << ORANGE<<"                                   ----- ING -----\n\n\n"<<RESET;
    }
    void displayMessage() const override {
        cout << RED << "At ING BANK, we offer the following term deposits:\n\n"<<RESET;
        cout << GREEN << "1. Three months deposit (3 Months RON):                  4.10% annually.\n"<<RESET;
        cout << YELLOW << "2. Six months flexi-deposit (6 Months RON):              4.60% annually.\n"<<RESET;
        cout << CYAN << "3. Twelve months deposit (12 Months RON):                5.00% annually.\n" << RESET;
        cout << ORANGE<< "4. Twenty four months deposit (24 Months RON):           5.20% annually.\n\n\n"<<RESET;
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
        cout << ORANGE << "                                   ----- BCR -----\n\n\n" << RESET;
    }
    void displayMessage() const override {
        cout << RED << "At BCR, we offer the following term deposits:\n\n"<<RESET;
        cout << GREEN << "1. Three months deposit (3 Months RON):                4.20% annually.\n" << RESET;
        cout << YELLOW << "2. Six months flexi-deposit (6 Months RON):            4.60% annually.\n" << RESET;
        cout << CYAN << "3. Twelve months deposit (12 Months RON):              5.00% annually.\n" << RESET;
        cout << ORANGE<< "4. Twenty four months deposit (24 Months RON):         5.10% annually.\n\n\n"<<RESET;
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
        cout << ORANGE<<"                                   ----- BRD -----\n\n\n" << RESET;
    }
    void displayMessage() const override {
        cout << RED<< "At BRD, we offer the following term deposits:\n\n"<<RESET;
        cout << GREEN<< "1. Three months deposit (3 Months RON):               3.85% annually.\n"<<RESET;
        cout << YELLOW<<"2. Six months flexi-deposit (6 Months RON):           4.00% annually.\n"<<RESET;
        cout << CYAN << "3. Twelve months deposit (12 Months RON):             4.30% annually.\n" << RESET;
        cout << ORANGE << "4. Twenty four months deposit (24 Months RON):        4.40% annually.\n\n\n" << RESET;
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

    printDetails();

    int option;
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
        cout << GREEN<< "Enter the amount of RON for the deposit: " << RESET;
        cin >> amount;
        cout << ORANGE << "The accumulated wealth is: " << bank->calculateAmount(option,amount) << " RON\n" << RESET;
    }
    else {
        cout << RED << "Invalid option. Please choose a number between 1 and 5.\n" << RESET;
    }

    return 0;
}
