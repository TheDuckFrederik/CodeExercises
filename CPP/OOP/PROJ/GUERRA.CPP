#include <iostream>
#include <string>
#include <chrono>
#include <thread>
//
using namespace std;
//
class Player {
public:
    string name;
    int points;
    string action;
    int targetIndex;
    int pointsA[10];
    string actionA[10];
    int targetIndexA[10];
    //
    Player(string n) : name(n), points(100), action(""), targetIndex(-1) {}
};
//
void displayPlayers(Player players[5], int round) {
    cout << "\n---------------------------\n";
    cout << "Round " << round << " | "; 
    for (int i = 0; i < 5; ++i) {
        cout << players[i].name << " [" << players[i].points << " pts]";
        if (i < 4) cout << " | ";
    }
    //
    cout << "\n---------------------------\n";
}
//
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
//
void getPlayerChoice(Player& player, int playerIndex, int round) {
    string choice;
    int target;
    cout << player.name << ", choose your action (A/D)\n---> ";
    cin >> choice;
    //
    while (choice != "A" && choice != "D") {
        cout << "Invalid choice. Enter 'A' or 'D': ";
        cin >> choice;
    }
    //
    player.action = choice;
    //
    if (choice == "A") {
        cout << "\nWho do you want to attack?\n    0: Oscar\n    1: Ariadna\n    2: Ivan\n    3: Jia Yi\n    4: Colapuerto\n---> ";
        cin >> target;
        while (target < 0 || target > 4 || target == playerIndex) {
            cout << "Invalid target. Choose another player (0-4, not yourself): ";
            cin >> target;
        }
        player.targetIndex = target;
        player.targetIndexA[round] = target;
    }
}
//
void resolveRound(Player players[5], int round) {
    for (int i = 0; i < 5; ++i) {
        players[i].pointsA[round + 1];
    }
    // 
    for (int i = 0; i < 5; ++i) {
        if (players[i].action == "D") {
            players[i].points -= 4;
            for (int j = 0; j < 5; ++j) {
                if (i != j) players[j].points += 1;
            }
        }
    }
    //
    for (int i = 0; i < 5; ++i) {
        if (players[i].action == "A") {
            int target = players[i].targetIndex;
            if (players[target].action == "D") {
                players[i].points -= 10;
                players[target].points += 10;
            } else {
                players[i].points += 10;
                players[target].points -= 10;
            }
        }
    }
}
//
void startMenu() {
    char smChoice;
    //
    while (true) {
        cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
        cout << "|                                                                                                                                                                                                               |\n";
        cout << "|                                                                             GGGG    UU   UU   EEEEEEE   RRRRRR    RRRRRR      AAA                                                                             |\n";
        cout << "|                                                                            GG  GG   UU   UU   EE        RR   RR   RR   RR    AAAAA                                                                            |\n";
        cout << "|                                                                           GG        UU   UU   EEEEE     RRRRRR    RRRRRR    AA   AA                                                                           |\n";
        cout << "|                                                                           GG   GG   UU   UU   EE        RR  RR    RR  RR    AAAAAAA                                                                           |\n";
        cout << "|                                                                            GGGGGG    UUUUU    EEEEEEE   RR   RR   RR   RR   AA   AA                                                                           |\n";
        cout << "|                                                                                                                                                                                                               |\n";
        cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
        //
        cout << "\nBienvenido Mishi! Deseas empezar? (y/n)\n---> ";
        cin >> smChoice;
        //
        if (smChoice == 'y' || smChoice == 'Y') {
            clearScreen();
            //
            break;
        } else if (smChoice == 'n' || smChoice == 'N') {
            exit(0);
        } else {
            while (true) {
                clearScreen();
                //
                cout << "\n\n\n\nSYNTAX ERR!\nWAIT PLEASE\n\n\n\n";
                //
                this_thread::sleep_for(chrono::seconds(3));
                //
                clearScreen();
                break;
            }
        }
    }
}
//
void printResults(Player players[5]) {
    //
    for (int p = 0; p <= 4; p++) {
        for (int i = 0; i <= 9; i ++) {
            cout << "En la Ronda " << i + 1 << ": " << players[p].name << " tenia " << players[p].pointsA << " puntos!\n";
        }
        //
        cout << "-------------------------------------------------------------------------------------------------------\n";
    }
}
//
int main() {
    startMenu();
    //
    Player players[5] = {
        Player("Oscar"),
        Player("Ariadna"),
        Player("Ivan"),
        Player("Jia Yi"),
        Player("Colapuerto")
    };
    //
    for (int round = 1; round <= 10; ++round) {
        while(true) {
            for (int i = 0; i < 5; ++i) {
                cout << "\n=== Ronda " << round << " ===\n";
                displayPlayers(players, round);
                //
                getPlayerChoice(players[i], i, round);
                //
                clearScreen();
            }
            //
            char Confirm;
            //
            cout << "\nEstas seguro? (y/n)\n---> ";
            cin >> Confirm;
            //
            if (Confirm == 'y' || Confirm == 'Y') {
                resolveRound(players, round);
                clearScreen();
                break;
            } else if (Confirm == 'n' || Confirm == 'N') {
                clearScreen();
                cout << "\n\n\n\nOk, reseting!\n\n\n\n";
                this_thread::sleep_for(chrono::seconds(3));
                clearScreen();
            } else {
                clearScreen();
                //
                cout << "\n\n\n\nSYNTAX ERR!\nWAIT PLEASE\n\n\n\n";
                //
                this_thread::sleep_for(chrono::seconds(3));
                //
                clearScreen();
            }
        }
    }
    //
    return 0;
}
