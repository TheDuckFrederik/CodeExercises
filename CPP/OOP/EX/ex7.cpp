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
        virtual void printDetails() { cout << "Title: " << getTitle() << "\nAuthor: " << getAuthor() << "\nNumber of Pages: " << Pages << "\n"; }
};
//
class Magazine : public Item {
    private:
        int Pages;
        int IssueNumber;
    //
    public:
        void setPages(int pages) { Pages = pages; }
        //
        void setIssueNumber(int issueNumber) { IssueNumber = issueNumber; }
        //
        int getPages() { return Pages; }
        //
        int getIssueNumber() { return IssueNumber; }
        //
        void printDetails() { cout << "Title: " << getTitle() << "\nAuthor: " << getAuthor() << "\nNumber of Pages: " << Pages << "\nIssue Number: " << IssueNumber << "\n"; }
};
//
int main() {
    Book b1;
    b1.setTitle("El Paciente");
    b1.setAuthor("Juan Gomez Jurado");
    b1.setPages(416);
    //
    Magazine m1;
    m1.setTitle("Absolute Batman");
    m1.setAuthor("Scott Snyder");
    m1.setPages(48);
    m1.setIssueNumber(1);
    //
    Item* itemPtr;
    //
    itemPtr = &b1;
    itemPtr -> printDetails();
    //
    cout << "\n";
    //
    itemPtr = &m1;
    itemPtr -> printDetails();
    //
    return 0;
}
