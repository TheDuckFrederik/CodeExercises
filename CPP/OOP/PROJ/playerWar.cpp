#include <iostream>
#include <chrono>
#include <thread>
//
using namespace std;
//
class Player {
    private:
        string Name;
        //
        string SpaceL;
        string SpaceR;
        //
        string BotLines = "\n|------------|";
        //
        const int InitialPoints = 100;
        int CurrentPoints = InitialPoints;
        int RoundPoints[10];
        char RoundAction[10];
        int RoundAtackedPlayer[10];
        //
        string Details[12];
    //
    public:
        void setName(string name) { Name = name; }
        //
        void setSpaceL(string spaceL) { SpaceL = spaceL; }
        //
        void setSpaceR(string spaceR) { SpaceR = spaceR; }
        //
        void setRoundPoints(int roundPoints, int round) { RoundPoints[round] = roundPoints; }
        //
        void setRoundAction(char roundAction, int round) { RoundAction[round] = roundAction; }
        //
        void setRoundAtackedPlayer(int roundAtackedPlayer, int round) { RoundAtackedPlayer[round] = roundAtackedPlayer; }
        //
        void makeSpaces() {
            switch (Name.length()) {
                case 4:
                    SpaceL = "    ";
                    SpaceR = SpaceL;
                    //  Ivan
                    break;
                //
                case 5:
                    SpaceL = "    ";
                    SpaceR = "   ";
                    //  Oscar
                    break;
                //
                case 6:
                    SpaceL = "   ";
                    SpaceR = SpaceL;
                    //  Jia Yi
                    break;
                //
                case 7:
                    SpaceL = "   ";
                    SpaceR = "  ";
                    //  Ariadna
                    break;
                //
                case 10:
                    SpaceL = " ";
                    SpaceR = SpaceL;
                    //  Colapuerto
                    break;
                //
                default:
                    SpaceL = "      ";
                    SpaceR = SpaceL;
            }
        }
        //
        void setPlayerInfo() { Details[0] = "|", SpaceL, Name, SpaceR, "|", BotLines; }
        //
        string getPlayerName() { return Name; }
        //
        int getCurrentPoints() { return CurrentPoints; }
        //
        int getRoundPoints(int round) { return RoundPoints[round]; }
        //
        char getRoundAction(int round) { return RoundAction[round]; }
        //
        int getRoundAtackedPlayer(int round) { return RoundAtackedPlayer[round]; }
        //
        string getPlayerNameF() { return Details[0]; }
};
//
void printHeader(int round) {
    //
    if (round >= 1 && round <= 5) {
        cout << "             |--------------------------------------|--------------------------------------|--------------------------------------|--------------------------------------|--------------------------------------|\n";
        cout << "             |                Round1                |                Round2                |                Round3                |                Round4                |                Round5                |\n";
        cout << "             |--------------------------------------|--------------------------------------|--------------------------------------|--------------------------------------|--------------------------------------|\n";
        cout << "|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|\n";
        cout << "|    Name    |   Points   |   Action   |   Atacked  |   Points   |   Action   |   Atacked  |   Points   |   Action   |   Atacked  |   Points   |   Action   |   Atacked  |   Points   |   Action   |   Atacked  |\n";
        cout << "|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|\n";
    } else if (round >= 6 && round <= 10) {
        cout << "             |--------------------------------------|--------------------------------------|--------------------------------------|--------------------------------------|--------------------------------------|\n";
        cout << "             |                Round6                |                Round7                |                Round8                |                Round9                |                Round10               |\n";
        cout << "             |--------------------------------------|--------------------------------------|--------------------------------------|--------------------------------------|--------------------------------------|\n";
        cout << "|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|\n";
        cout << "|    Name    |   Points   |   Action   |   Atacked  |   Points   |   Action   |   Atacked  |   Points   |   Action   |   Atacked  |   Points   |   Action   |   Atacked  |   Points   |   Action   |   Atacked  |\n";
        cout << "|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|\n";
    }
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
void Game() {
    int Round = 1;
    int Turn = 0;
    //
    char Confirm;
    //
    bool stayG = true;
    bool stayR = true;
    bool stayT = true;
    //
    Player Oscar, Ariadna, Ivan, JiaYi, Colapuerto;
    char Action;
    string atckedPlayer;
    //
    Oscar.setName("Oscar");
    Ariadna.setName("Ariadna");
    Ivan.setName("Ivan");
    JiaYi.setName("Jia Yi");
    Colapuerto.setName("Colapuerto");
    //
    string Players[5] = {Oscar.getPlayerName(), Ariadna.getPlayerName(), Ivan.getPlayerName(), JiaYi.getPlayerName(), Colapuerto.getPlayerName()};
    //
    while (stayG == true) {
        while (stayR == true) {
            cout << "Que accion desea realizar " << Players[Turn] << "? (A/D)\n---> ";
            cin >> Action;
            //
            if (Action == 'A' || Action == 'a') {
                cout << Players[Turn] << " chose to Attack\n\n";
                //
                Turn ++;
            } else if (Action == 'D' || Action == 'd') {
                cout << "Estas seguro? (y/n)\n---> ";
                cin >> Confirm;
                //
                if (Confirm == 'y' || Confirm == 'Y') {
                    cout << Players[Turn] << " chose to Defend\n\n";
                    //
                    Turn ++;
                } else if (Confirm == 'n' || Confirm == 'N') {
                    cout << "Ok, reseting! \n";
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
}
//
int main() {
    startMenu();
    //
    Game();
    //
    return 0;
}
