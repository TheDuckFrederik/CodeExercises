#include <iostream>

using namespace std;

int main() {
    int num1, num2, type;
    double result; // Changed result to double
    char proceedC = 'y';

    while (proceedC == 'y' || proceedC == 'Y') {
        cout << "Insert the first number:\n---> ";
        cin >> num1;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n----------------------------------------------------------------------\nSyntax error on the First Number. Please enter a valid integer.\n----------------------------------------------------------------------\n\n";
            continue;
        }

        cout << "Insert the second number:\n---> ";
        cin >> num2;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n----------------------------------------------------------------------\nSyntax error on the Second Number. Please enter a valid integer.\n----------------------------------------------------------------------\n\n";
            continue;
        }

        cout << "What kind of operation do you wish to make?\n  1 - Addition\n  2 - Subtraction\n  3 - Multiplication\n  4 - Division\n---> ";
        cin >> type;

        if (cin.fail() || type < 1 || type > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n----------------------------------------------------------------------\nSyntax error on the operation type. Please enter a valid option (1-4).\n----------------------------------------------------------------------\n\n";
            continue;
        }

        switch (type) {
            case 1:
                result = num1 + num2;
                cout << "\n" << num1 << " + " << num2 << " = " << result << "\n\n";
                break;
            case 2:
                result = num1 - num2;
                cout << "\n" << num1 << " - " << num2 << " = " << result << "\n\n";
                break;
            case 3:
                result = num1 * num2;
                cout << "\n" << num1 << " * " << num2 << " = " << result << "\n\n";
                break;
            case 4:
                if (num2 == 0) {
                    cout << "\n----------------------------------------------------------------------\nSyntax error on the Second Number. Please enter a number that isn't 0.\n----------------------------------------------------------------------\n\n";
                    continue;
                }
                result = static_cast<double>(num1) / num2; // Ensure floating-point division
                cout << "\n" << num1 << " / " << num2 << " = " << result << "\n\n";
                break;
        }

        cout << "Do you wish to continue (y/n)?\n---> ";
        cin >> proceedC;

        if (!(proceedC == 'y' || proceedC == 'Y' || proceedC == 'n' || proceedC == 'N')) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n----------------------------------------------------------------------\nSyntax error. Please enter a valid option (y/n).\n----------------------------------------------------------------------\n\n";
            proceedC = 'y'; // Default to continuing
        }
    }

    return 0;
}
