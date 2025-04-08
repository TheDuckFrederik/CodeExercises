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
            Title = title;
            Author = author;
            Pages = pages;
        }
        //
        void printDetails() { cout << "Title: " << Title << "\nAuthor: " << Author << "\nNumber of pages: " << Pages << "\n"; }
};
//
class Magazine : public Item {
    private:
        int IssueNumber;
    //
    public:
        Magazine(string title, string author, int issueNumber) {
            Title = title;
            Author = author;
            IssueNumber = issueNumber;
        }
        //
        void printDetails() { cout << "Title: " << Title << "\nAuthor: " << Author << "\nIssue Number: " << IssueNumber << "\n"; }
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
            Name = name;
            Id = id;
            GradeLevel = gradeLevel;
        }
        //
        void printMemberDetails() { cout << "Name: " << Name << "\nId: " << Id << "\nGrade Level: " << GradeLevel << "\n"; }
};
//
int main() {
    return 0;
}
