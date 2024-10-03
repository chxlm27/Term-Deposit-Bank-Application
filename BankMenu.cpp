#include "BankMenu.h"
#include <iomanip>

void printDetails() {
    cout << MAGENTA << "Choose a bank from the following list:\n\n\n" << RESET;
    cout << YELLOW << "1. Raiffeisen Bank\n" << RESET;
    cout << GREEN << "2. Banca Transilvania\n" << RESET;
    cout << ORANGE << "3. ING\n" << RESET;
    cout << RED << "4. BCR\n" << RESET;
    cout << CYAN << "5. BRD\n" << RESET;
    cout << MAGENTA << "B. Go Back (Exit)\n" << RESET;
    cout << "\n\nEnter an option: ";
}

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

void handleBankMenu() {
    string input;

    do {
        system("cls");
        printDetails();

        cin >> input;

        if (input == "B" || input == "b") {
            cout << "Exiting program. Goodbye!\n";
            break;
        }

        int bankOption;
        try {
            bankOption = stoi(input);
        }
        catch (invalid_argument&) {
            cout << RED << "Invalid input. Please enter a number between 1 and 5, or 'B' to exit.\n" << RESET;
            cout << "\nPress Enter to go back to the main menu...\n";
            cin.ignore();
            cin.get();
            continue;
        }

        system("cls");
        unique_ptr<Bank> bank = createBank(bankOption);

        if (bank) {
            int depositOption;
            double amount;

            bank->displayName();
            bank->displayMessage();

            cout << "Choose a deposit type (or press 'B' to go back): ";
            cin >> input;

            if (input == "B" || input == "b") {
                continue;
            }

            try {
                depositOption = stoi(input);
            }
            catch (invalid_argument&) {
                cout << RED << "Invalid input. Please enter a number between 1 and 4.\n" << RESET;
                cout << "\nPress Enter to go back to the main menu...\n";
                cin.ignore();
                cin.get();
                continue;
            }

            if (depositOption < 1 || depositOption > 4) {
                cout << RED << "Invalid deposit type. Please choose a number between 1 and 4.\n" << RESET;
                cout << "\nPress Enter to go back to the main menu...\n";
                cin.ignore();
                cin.get();
                continue;
            }

            cout << '\n';
            cout << GREEN << "Enter the amount of RON for the deposit (or press 'B' to go back): " << RESET;
            cin >> input;

            if (input == "B" || input == "b") {
                continue;
            }

            try {
                amount = stod(input);
            }
            catch (invalid_argument&) {
                cout << RED << "Invalid amount. Please enter a valid number.\n" << RESET;
                cout << "\nPress Enter to go back to the main menu...\n";
                cin.ignore();
                cin.get();
                continue;
            }

            double accumulatedWealth = bank->calculateAmount(depositOption, amount);

            if (accumulatedWealth == 0.0) {
                cout << RED << "An error occurred during the calculation.\n" << RESET;
            }
            else {
                cout << fixed << setprecision(3);
                cout << ORANGE << "The total accumulated wealth is: " << accumulatedWealth << " RON\n" << RESET;
            }

            cout << "\nPress Enter to go back to the main menu...\n";
            cin.ignore();
            cin.get();
        }
        else {
            cout << RED << "Invalid option. Please choose a number between 1 and 5.\n" << RESET;
            cout << "\nPress Enter to go back to the main menu...\n";
            cin.ignore();
            cin.get();
        }
    } while (true);
}
