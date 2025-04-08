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
        string getName() {
            return Name;
        }
        //
        int getAge() {
            return Age;
        }
};
//
int main() {
    Person p1;
    //
    p1.setName("Bob");
    p1.setAge(31);
    //
    cout << "Name: " << p1.getName() << "\n";
    cout << "Age: " << p1.getAge() << "\n";
    //
    return 0;
}
