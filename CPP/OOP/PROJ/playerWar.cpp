#include <iostream>
#include <chrono>
#include <thread>
//
using namespace std;
//
class Player {
    private:
        string Name;
        int Id;
        //
        string SpaceL;
        string SpaceR;
        //
        string BotLines = "\n|------------|";
        //
        string posibleAttack[4];
        string visual[12] = {"    ----    "};
        //
        const int InitialPoints = 100;
        int CurrentPoints = InitialPoints;
        int RoundPoints[10];
        char RoundAction[10];
        string RoundAtackedPlayer[10];
        //
        string Details[12];
    //
    public:
        void setName(string name) { Name = name; }
        //
        void setId(int id) { Id = id; }
        //
        void setSpaceL(string spaceL) { SpaceL = spaceL; }
        //
        void setSpaceR(string spaceR) { SpaceR = spaceR; }
        //
        void setRoundPoints(int roundPoints, int round) { RoundPoints[round] = roundPoints; }
        //
        void setRoundAction(char roundAction, int round) { RoundAction[round] = roundAction; }
        //
        void setPosibleAtack(string p1, string p2, string p3, string p4) { posibleAttack[0] = p1; posibleAttack[1] = p2; posibleAttack[2] = p3; posibleAttack[3] = p4; }
        //
        void setVisual(string thing) {  }
        //
        void setRoundAtackedPlayer(string roundAtackedPlayer, int round) { RoundAtackedPlayer[round] = roundAtackedPlayer; }
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
        string getPlayerNameF() { return Details[0]; }
        //
        int getCurrentPoints() { return CurrentPoints; }
        //
        int getRoundPoints(int round) { return RoundPoints[round]; }
        //
        char getRoundAction(int round) { return RoundAction[round]; }
        //
        string getRoundAtackedPlayer(int round) { return RoundAtackedPlayer[round]; }
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
void Game1() {
    int Round = 1;
    int Turn = 0;
    //
    char Confirm;
    //
    bool stayG = true;
    bool stayR = true;
    //
    Player Oscar, Ariadna, Ivan, JiaYi, Colapuerto;
    char Action;
    int atckedPlayer;
    string atackedPlayerF;
    //
    Oscar.setName("Oscar");
    Ariadna.setName("Ariadna");
    Ivan.setName("Ivan");
    JiaYi.setName("Jia Yi");
    Colapuerto.setName("Colapuerto");
    //
    Oscar.setId(1);
    Ariadna.setId(2);
    Ivan.setId(3);
    JiaYi.setId(4);
    Colapuerto.setId(5);
    //
    string Players[5] = {Oscar.getPlayerName(), Ariadna.getPlayerName(), Ivan.getPlayerName(), JiaYi.getPlayerName(), Colapuerto.getPlayerName()};
    //
    while (stayG == true) {
        while (stayR == true) {
            cout << "Que accion desea realizar " << Players[Turn] << "? (A/D)\n---> ";
            cin >> Action;
            //
            if (Turn == 4) { stayR = false; }
            //
            if (Action == 'A' || Action == 'a') {
                cout << " Que jugador desea atacar " << Players[Turn] << "?\n    1. " << Players[Turn + 1] << "\n    2. " << Players[Turn + 2] << "\n    3. " << Players[Turn + 3] << "\n    4. " << Players[Turn + 4] << "\n---> ";
                cin >> atckedPlayer;
                //
                int aP = atckedPlayer;
                string aPF; 
                //
                switch (Turn) {
                    case 0:
                        switch (aP) {
                            case 1: aPF = "Ariadna"; break;
                            case 2: aPF = "Ivan"; break;
                            case 3: aPF = "Jia Yi"; break;
                            case 4: aPF = "Colapuerto"; break;
                        }
                        //
                        Oscar.setRoundAtackedPlayer(aPF, Round);
                        break;
                    //
                    case 1:
                        switch (aP) {
                            case 1: aPF = "Ivan"; break;
                            case 2: aPF = "Jia Yi"; break;
                            case 3: aPF = "Colapuerto"; break;
                            case 4: aPF = "Oscar"; break;
                        }
                        //
                        Ariadna.setRoundAtackedPlayer(aPF, Round);
                        break;
                    //
                    case 2:
                        switch (aP) {
                            case 1: aPF = "Jia Yi"; break;
                            case 2: aPF = "Colapuerto"; break;
                            case 3: aPF = "Oscar"; break;
                            case 4: aPF = "Ariadna"; break;
                        }
                        //
                        Ivan.setRoundAtackedPlayer(aPF, Round);
                        break;
                    //
                    case 3:
                        switch (aP) {
                            case 1: aPF = "Colapuerto"; break;
                            case 2: aPF = "Oscar"; break;
                            case 3: aPF = "Ariadna"; break;
                            case 4: aPF = "Ivan"; break;
                        }
                        //
                        JiaYi.setRoundAtackedPlayer(aPF, Round);
                        break;
                    //
                    case 4:
                        switch (aP) {
                            case 1: aPF = "Oscar"; break;
                            case 2: aPF = "Ariadna"; break;
                            case 3: aPF = "Ivan"; break;
                            case 4: aPF = "Jia Yi"; break;
                        }
                        //
                        Colapuerto.setRoundAtackedPlayer(aPF, Round);
                        break;
                }
                //
                cout << "\n" << Players[Turn] << " a elegido atacar a " << aPF << "\n\n";
                //
                cout << "Estas seguro? (y/n)\n---> ";
                cin >> Confirm;
                //
                if (Confirm == 'y' || Confirm == 'Y') {
                    Turn ++;
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
            } else if (Action == 'D' || Action == 'd') {
                cout << "Estas seguro? (y/n)\n---> ";
                cin >> Confirm;
                //
                if (Confirm == 'y' || Confirm == 'Y') {
                    cout << Players[Turn] << " a decidido defenderse\n\n";
                    //
                    Turn ++;
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
            } else {
                clearScreen();
                //
                cout << "\n\n\n\nSYNTAX ERR!\nWAIT PLEASE\n\n\n\n";
                //
                this_thread::sleep_for(chrono::seconds(3));
                //
                clearScreen();
            }
            //
            clearScreen();
        }
    }
    //
    cout << Oscar.getRoundAtackedPlayer(1) << "\n"; 
    cout << Ariadna.getRoundAtackedPlayer(1) << "\n"; 
    cout << Ivan.getRoundAtackedPlayer(1) << "\n"; 
    cout << JiaYi.getRoundAtackedPlayer(1) << "\n"; 
    cout << Colapuerto.getRoundAtackedPlayer(1) << "\n"; 
}
//
void Game2() {
    int Round = 1;
    int Turn = 0;
    //
    char Confirm;
    //
    bool stayG = true;
    bool stayR = true;
    //
    Player Oscar, Ariadna, Ivan, JiaYi, Colapuerto;
    char Action;
    int atckedPlayer;
    string atackedPlayerF;
    //
    Oscar.setName("Oscar");
    Ariadna.setName("Ariadna");
    Ivan.setName("Ivan");
    JiaYi.setName("Jia Yi");
    Colapuerto.setName("Colapuerto");
    //
    Oscar.setId(1);
    Ariadna.setId(2);
    Ivan.setId(3);
    JiaYi.setId(4);
    Colapuerto.setId(5);
    //
    string Players[5] = {Oscar.getPlayerName(), Ariadna.getPlayerName(), Ivan.getPlayerName(), JiaYi.getPlayerName(), Colapuerto.getPlayerName()};
    //
}
//
int main() {
    startMenu();
    //
    Game2();
    //
    //
    return 0;
}
