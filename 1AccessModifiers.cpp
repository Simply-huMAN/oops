//Access Modifiers are special keywords in C++ that are used to restrict the access of a class member.
//There are 3 types of access modifiers in C++:
//1. Private
//2. Public
//3. Protected
//Private members of a class are accessible only inside the class.
//Public members of a class are accessible outside the class.
//Protected members of a class are accessible inside the class and in the derived class.
//By default, all the members of a class are private.
//Access modifiers are used to implement encapsulation in C++.

#include <iostream>
using namespace std;

class Employee{
    private: // All the things below this are private
        int salary;
        int employeeId;
    
    public: // All the things below this are public
        string employeeName;
        string employeeCompany;
        int age;
    
    void IntroduceYourself(){
        cout << "Name - " << employeeName << endl;
        cout << "Company - " << employeeCompany << endl;
        cout << "Age - " << age << endl;
    }

};

int main(){
    Employee employee1;
    employee1.employeeName = "Maloth Aditya";  // This is how we assign values to the variables of a class.
    employee1.employeeCompany = "myCompany";   // This is how we assign values to the variables of a class.
    employee1.age = 95;                        // This is how we assign values to the variables of a class.
    employee1.IntroduceYourself();            // This is how we call a function of a class.

    // If you are asked to write code for 10 such employees, you will have to write the same code 10 times.
    // This is where constructors come into play.
    // Constructors explained in next file.
    return 0;
}