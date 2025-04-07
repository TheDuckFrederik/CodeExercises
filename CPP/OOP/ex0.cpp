#include <iostream>
//
using namespace std;
//
class Person {
    public:
        string Name;
        int Age;
};
//
int main() {
    Person p1;
    //
    p1.Name = "Bob";
    p1.Age = 31;
    //
    cout << "Name: " << p1.Name << "\nAge: " << p1.Age;
    //
    return 0;
}
