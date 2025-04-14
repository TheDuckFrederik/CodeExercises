#include <iostream>
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
        int getCurrentPoints() { return CurrentPoints; }
        //
        int getRoundPoints(int round) { return RoundPoints[round]; }
        //
        char getRoundAction(int round) { return RoundAction[round]; }
        //
        int getRoundAtackedPlayer(int round) { return RoundAtackedPlayer[round]; }
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
        void printPlayerName() {
            makeSpaces();
            //
            cout << "|" << SpaceL << Name << SpaceR << "|" << BotLines << "\n";
        }
        //
        void printPlayerDatails() { printPlayerName(); }
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
void startMenu() {
    cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
    cout << "|                                                                                                                                                                                                               |\n";
    cout << "|                                                                             GGGG    UU   UU   EEEEEEE   RRRRRR    RRRRRR      AAA                                                                             |\n";
    cout << "|                                                                            GG  GG   UU   UU   EE        RR   RR   RR   RR    AAAAA                                                                            |\n";
    cout << "|                                                                           GG        UU   UU   EEEEE     RRRRRR    RRRRRR    AA   AA                                                                           |\n";
    cout << "|                                                                           GG   GG   UU   UU   EE        RR  RR    RR  RR    AAAAAAA                                                                           |\n";
    cout << "|                                                                            GGGGGG    UUUUU    EEEEEEE   RR   RR   RR   RR   AA   AA                                                                           |\n";
    cout << "|                                                                                                                                                                                                               |\n";
    cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";

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
int main() {
    Player Oscar, Ariadna, Ivan, JiaYi, Colapuerto;
    int Round;
    //
    startMenu();
    //
    Oscar.setName("Oscar");
    Ariadna.setName("Ariadna");
    Ivan.setName("Ivan");
    JiaYi.setName("Jia Yi");
    Colapuerto.setName("Colapuerto");
    //
    printHeader(5);
    //
    Oscar.printPlayerDatails();
    Ariadna.printPlayerDatails();
    Ivan.printPlayerDatails();
    JiaYi.printPlayerDatails();
    Colapuerto.printPlayerDatails();
    //
    return 0;
}
