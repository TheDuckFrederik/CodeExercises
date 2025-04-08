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
        void setData(string personName, int personAge) {
            Name = personName;
            Age = personAge;
        }
        //
        void printPerson() {
            cout << "Name: " << Name << "\nAge: " << Age;
        }
};
//
int main() {
    Person p1;
    //
    p1.setData("Bob", 31);
    p1.printPerson();
    //
    return 0;
}
