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
        ~Person() {
            cout << "Nooooooooooo, you monster.\nYOU DESTROYED " << Name << "\n";
        }
        //
        void printPerson() {
            cout << "Name: " << Name << "\nAge: " << Age << "\n";
        }
};
//
int main() {
    Person p1("Bob", 31);
    //
    p1.printPerson();
    //
    return 0;
}
