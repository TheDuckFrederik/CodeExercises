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
        void printPerson() {
            cout << "Name: " << Name << "\n" << "Age: " << Age << "\n";
        }
};
//
class Employee: public Person {
    private:
        double Salary;
    //
    public:
        void setSalary(double salary) {
            Salary = salary;
        }
        //
        void printEmployee() {
            printPerson();
            cout << "Salary: " << Salary << "\n";
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
    Employee p2;
    //
    p2.setName("Unai");
    p2.setAge(18);
    p2.setSalary(347.80);
    //
    p2.printEmployee();
    //
    return 0;
}
