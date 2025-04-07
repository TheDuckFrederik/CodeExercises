import strutils, sequtils, os

type
  Book = object
    title: string
    author: string
    releaseYear: int
    genre: string
    ISBN: int64

proc newBook(title: string, author: string, releaseYear: int, genre: string, ISBN: int64): Book =
  result.title = title
  result.author = author
  result.releaseYear = releaseYear
  result.genre = genre
  result.ISBN = ISBN

proc printDetails(book: Book, bookNumber: int) =
  echo "--------------------------------------------------------------------------------------------------------------------------------"
  echo "Book Number: ", bookNumber
  echo "Book Title: ", book.title
  echo "Author: ", book.author
  echo "Year of Release: ", book.releaseYear
  echo "Genre: ", book.genre
  echo "ISBN: ", book.ISBN
  echo "--------------------------------------------------------------------------------------------------------------------------------"

proc clearScreen() =
  if defined(windows):
    discard execShellCmd("cls")
  else:
    discard execShellCmd("clear")

proc createBook(): Book =
  var
    inputTitle, inputAuthor, inputGenre: string
    inputReleaseYear: int
    inputISBN: int64

  echo "Title of the book:"
  echo "---> ", readLine(stdin)
  inputTitle = stdin.readLine()

  echo "Author of the book:"
  echo "---> ", readLine(stdin)
  inputAuthor = stdin.readLine()

  echo "Year in which the book was released:"
  echo "---> ", readLine(stdin)
  inputReleaseYear = stdin.readLine().parseInt()

  echo "Genres of the book:"
  echo "---> ", readLine(stdin)
  inputGenre = stdin.readLine()

  echo "ISBN of the book:"
  echo "---> ", readLine(stdin)
  inputISBN = stdin.readLine().parseInt64()

  clearScreen()
  result = newBook(inputTitle, inputAuthor, inputReleaseYear, inputGenre, inputISBN)

proc main() =
  var
    proceed = 'y'
    books: seq[Book] = @[]
    menu: int

  while proceed in {'y', 'Y'}:
    echo "Welcome to your BookShelf"
    echo "    1. Add a Book"
    echo "    2. Search a Book"
    echo "    3. Show all books"
    echo "    4. Exit"
    echo "---> ", readLine(stdin)
    menu = stdin.readLine().parseInt()

    if menu < 1 or menu > 4:
      clearScreen()
      echo "\n----------------------------------------------------------------------"
      echo "Syntax error on the operation type. Please enter a valid option (1-4)."
      echo "----------------------------------------------------------------------\n"
      continue
    else:
      clearScreen()

    case menu:
    of 1:
      let newBook = createBook()
      books.add(newBook)
      books[^1].printDetails(books.len)
    of 2:
      echo "Enter the book number:"
      echo "---> ", readLine(stdin)
      let num = stdin.readLine().parseInt()

      if num <= 0 or num > books.len:
        clearScreen()
        echo "\n----------------------------------------------------------------------"
        echo "Syntax error on the operation type. Please enter a valid book number."
        echo "----------------------------------------------------------------------\n"
        continue
      else:
        clearScreen()
        books[num - 1].printDetails(num)
    of 3:
      for i, book in books:
        book.printDetails(i + 1)
    of 4:
      proceed = 'n'

    if proceed in {'y', 'Y'}:
      echo "Do you wish to continue (y/n)?"
      echo "---> ", readLine(stdin)
      proceed = stdin.readLine()[0]
      if proceed in {'y', 'Y'}:
        clearScreen()

main()