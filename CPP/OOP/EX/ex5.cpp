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
        void setName(string name) {
            Name = name;
        }
        //
        void setAge(int age) {
            if (age >= 0) Age = age;
        }
        //
        void printPerson() const {
            cout << "Name: " << Name << "\n" << "Age: " << Age << "\n";
        }
};
//
int main() {
    Person p1;
    //
    p1.setName("Bob");
    p1.setAge(31);
    //
    p1.printPerson();
    //
    return 0;
}
