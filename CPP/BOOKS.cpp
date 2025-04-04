#include <iostream>
#include <vector>
//
using namespace std;
//
class Book {
    private:
        string title;
        string author;
        int releaseYear;
        string genere;
        long int ISBN;
    //
    public:
        Book(string t, string a, int year, string g, long int isbn) {
            title = t;
            author = a;
            releaseYear = year;
            genere = g;
            ISBN = isbn;
        }
        //
        string getTitle() { return title; }
        string getAuthor() { return author; }
        int getReleaseYear() { return releaseYear; }
        string getGenere() { return genere; }
        long int getISBN() { return ISBN; }
        //
        void printDetails(int bookNumber) {
            cout << "--------------------------------------------------------------------------------------------------------------------------------\n" 
            << "Book Number: " << bookNumber 
            <<"\nBook Title: " << title 
            << "\nAuthor: " << author 
            << "\nYear of Release: " << releaseYear 
            << "\nGenere: " << genere 
            << "\nISBN: " << ISBN 
            << "\n--------------------------------------------------------------------------------------------------------------------------------\n";
        }
};
//
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//
Book createBook() {
    string inputTitle;
    string inputAuthor;
    int inputReleaseYear;
    string inputGenere;
    long int inputISBN;
    //
    cin.ignore();
    //
    cout << "Title of the book:\n---> ";
    getline(cin, inputTitle);
    //
    cout << "Author of the book:\n---> ";
    getline(cin, inputAuthor);
    //
    cout << "Year in which the book was released:\n---> ";
    cin >> inputReleaseYear;
    //
    cin.ignore();
    //
    cout << "Generes of the book:\n---> ";
    getline(cin, inputGenere);
    //
    cout << "ISBN of the book:\n---> ";
    cin >> inputISBN;
    //
    clearScreen();
    //
    return Book(inputTitle, inputAuthor, inputReleaseYear, inputGenere, inputISBN);
}
//
int main() {
    char proceedT = 'y';
    char proceed = 'y';
    int itr = 0;
    int menu;
    //
    vector<Book> books;
    //
    while (proceed == 'y' | proceed == 'Y') {
        cout << "Welcome to your BookShelf\n    1. Add a Book\n    2. Search a Book\n    3. Show all books\n    4. Exit\n---> ";
        cin >> menu;
        
        if (cin.fail() || menu < 1 || menu > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            //
            clearScreen();
            cout << "\n----------------------------------------------------------------------\nSyntax error on the operation type. Please enter a valid option (1-4).\n----------------------------------------------------------------------\n\n";
            continue;
        } else {
            clearScreen();
        }
        //
        switch (menu) {
            case 1:
                {
                    Book newBook = createBook();
                    books.push_back(newBook);
                    books[books.size() - 1].printDetails(books.size());
                }
                break;
            //
            case 2:
                {
                    int num;
                    cout << "Enter the book number:\n---> ";
                    cin >> num;
                    //
                    if (cin.fail() || num <= 0 || num > books.size()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        clearScreen();
                        cout << "\n----------------------------------------------------------------------\nSyntax error on the operation type. Please enter a valid book number.\n----------------------------------------------------------------------\n\n";
                        continue;
                    } else {
                        clearScreen();
                    }
                    //
                    books[num - 1].printDetails(num);
                }
                break;
            //
            case 3:
                for (size_t i = 0; i < books.size(); i++) {
                    books[i].printDetails(i + 1);
                }
                break;
            //
            case 4:
                proceed = 'n';
                proceedT = 'n';
                break;
        }
        //
        if (proceedT == 'y' | proceedT == 'Y') {
            cout << "Do you wish to continue (y/n)?\n---> ";
            cin >> proceed;
            proceedT = proceed;
            cin.ignore();
            //
            if (proceed == 'y' | proceed == 'Y') {
                clearScreen();
            }
        }
    }
    //
    return 0;
}
