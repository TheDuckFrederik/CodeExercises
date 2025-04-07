import random, strutils

proc main() =
  var
    correctNumber, guessedNumber, itr: int
    playAgain: char = 'y'

  randomize()

  while playAgain in {'y', 'Y'}:
    if itr != 0:
      echo "Wish to continue? (Y/n)"
      echo "---> "
      let input = readLine(stdin)
      if input.len > 0:
        playAgain = input[0]
      else:
        playAgain = 'y'

    if playAgain notin {'y', 'Y'}:
      break

    correctNumber = rand(10) + 1

    echo "Guess the number between 1 - 10:"
    echo "---> "
    if not readLine(stdin).parseInt(guessedNumber):
      echo "\n----------------------------------------------------------------------"
      echo "Invalid input. Please enter a valid integer."
      echo "----------------------------------------------------------------------\n"
      continue

    if guessedNumber == correctNumber:
      echo "----------------------------------------------------------------------"
      echo "Hurray, you guessed correctly! Indeed the number was ", correctNumber
      echo "----------------------------------------------------------------------\n"
    else:
      echo "----------------------------------------------------------------------"
      echo "You didn't guess correctly! The correct number was ", correctNumber
      echo "Better luck next time."
      echo "----------------------------------------------------------------------\n"

    itr += 1

main()