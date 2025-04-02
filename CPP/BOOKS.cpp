#include <iostream>
//
using namespace std;
//
class Book {
    public:
        string title;
        string author;
        int releaseYear;
        string genere;
        long int ISBN;
};
//
int main() {
    Book book1;
    //
    book1.title = "El Paciente";
    book1.author = "Juan Gomez Jurado";
    book1.releaseYear = 2014;
    book1.genere = "Suspense, fiction";
    book1.ISBN = 9788408139317;
    //
    cout << "Book Title: " << book1.title << ", Author: " << book1.author << ", Year of Release: " << book1.releaseYear << ", Genere: " << book1.genere << " & ISBN: " << book1.ISBN;
    return 0;
}
