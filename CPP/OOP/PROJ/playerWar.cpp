#include <iostream>
//
using namespace std;
//
class Player {
    private:
        string Name;
        int InitialPoints = 100;
        int RoundPoints[10];
        char RoundAction[10];
        int RoundAtackedPlayer[10];
    //
    public:
        void setName(string name) { Name = name; }
        //
        void setRoundPoints(int roundPoints, int round) { RoundPoints[round] = roundPoints; }
        //
        void setRoundAction(char roundAction, int round) { RoundAction[round] = roundAction; }
        //
        void setRoundAtackedPlayer(int roundAtackedPlayer, int round) { RoundAtackedPlayer[round] = roundAtackedPlayer; }
        //
        int getRoundPoints(int round) { return RoundPoints[round]; }
        //
        char getRoundAction(int round) { return RoundAction[round]; }
        //
        int getRoundAtackedPlayer(int round) { return RoundAtackedPlayer[round]; }
        //
        void printDetails() {
            cout << "| ";
        }
};
//
int main() {
    Player;
    //
    return 0;
}
