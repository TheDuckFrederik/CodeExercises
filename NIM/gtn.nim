import std/random
import std/rdstdin
#
proc main() =
    var randNum: int;
    var guess: int;
    #
    while true:
        let randNum = rand(1, 10);
        #
        let guessNum = readLine("Guess the number between 1 - 10:\n---> ");
        #
        if guessNum == randNum:
            echo ("----------------------------------------------------------------------\nHurray, you guessed correctly! Indeed the number was ", randNum, "\n----------------------------------------------------------------------\n\n");
        else:
            echo ("----------------------------------------------------------------------\nYou didn't guess correctly! The correct number was " << randNum << "\nBetter luck next time.\n----------------------------------------------------------------------\n\n");
        #
        let playAgain = readLine("Wish to continue? (Y/n)\n---> ");
        if playAgain == "y":
            continue;
        else:
            break;
main()
