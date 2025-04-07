#include <iostream>
//
using namespace std;
//
class Person {
    private:
        string Name;
        int Age;
    //
    public:
        Person(string defName = "Unknown", int defAge = 0) : Name(defName), Age(defAge) {}
        //
        void printPerson() {
            cout << "Name: " << Name << "\nAge: " << Age << "\n";
        }
};
//
int main() {
    Person p1;
    Person p2("Bob", 31);
    //
    p1.printPerson();
    p2.printPerson();
    //
    return 0;
}
