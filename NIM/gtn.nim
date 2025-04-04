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
        let guessNum = readLine("Guess a number between 1 and 10: ");
        #
        if guessNum == randNum:
            echo ("Lucky you guessed correctly!\nThe number was: ", randNum);
        else:
            echo ("Better luck next time pal\nThe number was: ", randNum);
        #
        let playAgain = readLine("Do you want to play again? (y/n): ");
        if playAgain == "y":
            continue;
        else:
            echo ("Thanks for playing!");
            break;
main()
