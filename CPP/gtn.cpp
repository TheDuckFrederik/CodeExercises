#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    //
    int correctNumber;
    int guessedNumber;
    int itr = 0;
    char playAgain = 'y';
    //
    while (playAgain == 'y' || playAgain == 'Y') {
        if (itr != 0) {
            cout << "Wish to continue? (Y/n)\n---> ";
            cin >> playAgain;
        }
        //
        correctNumber = rand() % 10 + 1;
        //
        cout << "Guess the number between 1 - 10:\n---> ";
        cin >> guessedNumber;
        //
        if (guessedNumber == correctNumber) {
            cout << "----------------------------------------------------------------------\nHurray, you guessed correctly! Indeed the number was " << correctNumber << "\n----------------------------------------------------------------------\n\n";
        } else {
            cout << "----------------------------------------------------------------------\nYou didn't guess correctly! The correct number was " << correctNumber << "\nBetter luck next time.\n----------------------------------------------------------------------\n\n";
        }
        //
        itr ++;
    }
    //
    return 0;
}