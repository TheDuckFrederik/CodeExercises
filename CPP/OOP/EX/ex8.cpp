#include <iostream>
//
using namespace std;
//
class Item {
    private:
        string Title;
        string Author;
    //
    public:
        void setTitle(string title) { Title = title; }
        //
        void setAuthor(string author) { Author = author; }
        //
        string getTitle() { return Title; }
        //
        string getAuthor() { return Author; }
        //
        virtual void printDetails() { cout << "Title: " << Title << "\nAuthor: " << Author << "\n"; }
};
//
class Book : public Item {
    private:
        int Pages;
    //
    public:
        void setPages(int pages) { Pages = pages; }
        //
        int getPages() { return Pages; }
        //
        Book operator+(Book& other) {
            Book temp;
            //
            temp.setTitle("Combined Book");
            temp.setAuthor("Combined Authors");
            temp.setPages(this -> Pages + other.getPages());
            //
            return temp;
        }
        //
        void printDetails() { cout << "Title: " << getTitle() << "\nAuthor: " << getAuthor() << "Number of Pages: " << Pages << "\n"; }
};
//
class Magazine : public Item {
    private:
        int Pages;
        int IssueNumber;
    //
    public:
        void setPages(int pages) { Pages = pages; }
        void setIssueNumber(int issueNumber) { IssueNumber = issueNumber; }
        //
        int getPages() { return Pages; }
        int getIssueNumber() { return IssueNumber; }
        //
        bool operator==(Magazine& other) { return (getTitle() == other.getTitle() && getAuthor() == other.getAuthor() && Pages == other.getPages() && IssueNumber == other.getIssueNumber()); }
        //
        void printDetails() { cout << "Title: " << getTitle() << "\nAuthor: " << getAuthor() << "Number of Pages: " << Pages << "Issue Number: " << IssueNumber << "\n"; }
};
//
int main() {
    Book b1, b2;
    b1.setTitle("El Paciente");
    b1.setAuthor("Juan Gomez Jurado");
    b2.setTitle("Reina Roja");
    b2.setAuthor("Juan Gomez Jurado");
    //
    b1.setPages(295);
    b2.setPages(118);
    Book b3 = b1 + b2;
    cout << "Pages: " << b3.getPages() << "\n";
    //
    Magazine m1, m2;
    m1.setTitle("Absolute Batman");
    m1.setAuthor("Scott Snyder");
    m1.setPages(48);
    m1.setIssueNumber(1);
    m2.setTitle("Absolute Batman");
    m2.setAuthor("Scott Snyder");
    m2.setPages(48);
    m2.setIssueNumber(1);
    //
    if (m1 == m2) {
        cout << "m1 is the same as m2\n";
    } else {
        cout << "m1 is NOT the same as m2\n";
    }
    //
    return 0;
}
