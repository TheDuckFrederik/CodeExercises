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
        void printDetails() { cout << "Title: " << Title << "\nAuthor: " << Author << "\n"; }
};
//
class Book : public Item {
    private:
        int Pages;
    //
    public:
        Book(string title, string author, int pages) {
            setTitle(title);
            setAuthor(author);
            Pages = pages;
        }
        //
        void printDetails() { cout << "Title: " << getTitle() << "\nAuthor: " << getAuthor() << "\nNumber of pages: " << Pages << "\n"; }
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
class Member {
    private:
        string Name;
        int Id;
    //
    public:
        void setName(string name) { Name = name; }
        //
        void setId(int id) { Id = id; }
        //
        string getName() { return Name; }
        //
        int getId() { return Id; }
};
//
class Student : public Member {
    private:
        string GradeLevel;
    //
    public:
        Student(string name, int id, string gradeLevel) {
            setName(name);
            setId(id);
            GradeLevel = gradeLevel;
        }
        //
        void printMemberDetails() { cout << "Name: " << getName() << "\nId: " << getId() << "\nGrade Level: " << GradeLevel << "\n"; }
};
//
class Staff : public Member {
    private:
        string Position;
    //
    public:
        Staff(string name, int id, string position) {
            setName(name);
            setId(id);
            Position = position;
        }
        //
        void printMemberDetails() { cout << "Name: " << getName() << "\nId: " << getId() << "\nPosition: " << Position << "\n"; }
};
//
class Library {
    private:

};
//
int main() {
    return 0;
}
