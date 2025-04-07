import strutils

proc main() =
  var
    num1, num2, type: int
    result: float
    proceedC: char = 'y'

  while proceedC in {'y', 'Y'}:
    echo "Insert the first number:"
    echo "---> "
    if not readLine(stdin).parseInt(num1):
      echo "\n----------------------------------------------------------------------"
      echo "Syntax error on the First Number. Please enter a valid integer."
      echo "----------------------------------------------------------------------\n"
      continue

    echo "Insert the second number:"
    echo "---> "
    if not readLine(stdin).parseInt(num2):
      echo "\n----------------------------------------------------------------------"
      echo "Syntax error on the Second Number. Please enter a valid integer."
      echo "----------------------------------------------------------------------\n"
      continue

    echo "What kind of operation do you wish to make?"
    echo "  1 - Addition"
    echo "  2 - Subtraction"
    echo "  3 - Multiplication"
    echo "  4 - Division"
    echo "---> "
    if not readLine(stdin).parseInt(type) or type < 1 or type > 4:
      echo "\n----------------------------------------------------------------------"
      echo "Syntax error on the operation type. Please enter a valid option (1-4)."
      echo "----------------------------------------------------------------------\n"
      continue

    case type:
    of 1:
      result = num1 + num2
      echo "\n", num1, " + ", num2, " = ", result, "\n"
    of 2:
      result = num1 - num2
      echo "\n", num1, " - ", num2, " = ", result, "\n"
    of 3:
      result = num1 * num2
      echo "\n", num1, " * ", num2, " = ", result, "\n"
    of 4:
      if num2 == 0:
        echo "\n----------------------------------------------------------------------"
        echo "Syntax error on the Second Number. Please enter a number that isn't 0."
        echo "----------------------------------------------------------------------\n"
        continue
      result = num1.float / num2.float
      echo "\n", num1, " / ", num2, " = ", result, "\n"

    echo "Do you wish to continue (y/n)?"
    echo "---> "
    let input = readLine(stdin)
    if input.len > 0:
      proceedC = input[0]
    else:
      proceedC = 'y'

    if not (proceedC in {'y', 'Y', 'n', 'N'}):
      echo "\n----------------------------------------------------------------------"
      echo "Syntax error. Please enter a valid option (y/n)."
      echo "----------------------------------------------------------------------\n"
      proceedC = 'y'

main()