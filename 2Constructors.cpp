//Constructors are special functions that are called when an object is created.
//Constructors have the same name as the class.
//Constructors do not have any return type.
//Constructors can be private, mostly public.
//Constructors can be overloaded.
//Constructors can have default arguments, default values.
//Constructors can be parameterized.
//Constructors can be used to initialize class variables, class variables with dynamic memory allocation and static memory allocation.
//Constructors can be used to initialize class variables with dynamic memory allocation//Constructors can be used to initialize class variables with static memory allocation and dynamic memory allocation.
//When you create your own constructor, the default constructor is becomes unavailable.

#include <iostream>
using namespace std;

class Employee{
    private: // All the things below this are private
        int salary;
        int employeeId;
        Employee(){ // This is a private constructor
            salary = 0;
            employeeId = 0;
        }
    public: // All the things below this are public
        string employeeName;
        string employeeCompany;
        int age;

        Employee(string name, string company, int age){ // This is a parameterized constructor
            employeeName = name;
            employeeCompany = company;
            this->age = age; // THIS is a pointer to the current object
        }
    
    void IntroduceYourself(){
        cout << "Name - " << employeeName << endl;
        cout << "Company - " << employeeCompany << endl;
        cout << "Age - " << age << endl;
    }
};

int main(){
    Employee employee1 = Employee("Maloth Aditya", "myCompany", 95); // This is how we call a parameterized constructor.
    employee1.IntroduceYourself(); // This is how we call a function of a class.

    Employee employee2 = Employee("Rohith", "Amazon", 25); // This is how we call a parameterized constructor.   
    employee2.IntroduceYourself(); // This is how we call a function of a class.

    return 0;
}