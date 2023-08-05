//Abstraction is the process of hiding the implementation details and showing only the functionality to the user.
//Abstraction is used to achieve security, reusability, extensibility, maintainability, testability, loose coupling, low complexity and high cohesion.
//Abstraction and encapsulation are not the same.
//Abstraction is used to hide the implementation details and show only the functionality to the user.
//Encapsulation is used to hide the data and information.

//Encapsulation is the process of wrapping up of data and information under a single unit.
//Encapsulation is also known as data hiding.
//Encapsulation is done using access modifiers.
//Encapsulation is used to achieve abstraction.
//Encapsulation is used to make the code more flexible and maintainable.
//Encapsulation is used to achieve security, reusability, extensibility, maintainability, testability, loose coupling, low complexity and high cohesion.
//Setter and getter functions are used to access private variables.
//Setter and getter functions are used to set and get the values of private variables.

#include <iostream>
using namespace std;

class AbstractEmployee{ // This is an abstract class
    virtual void AskForPromotion() = 0; // This is a pure virtual function
    //Any class that inherits this class must implement this function.
    //This function is not defined here.
    //This function is defined in the derived class.
    //This function is defined in the derived class because it is a pure virtual function.
};

class Employee:AbstractEmployee{
    private: // All the things below this are private
        string employeeName;
        string employeeCompany;
        int age;
        int salary;
        int employeeId;
        // To access these private variables, we need to use setter and getter functions.
        Employee(){ // This is a private constructor
            employeeName = "";
            employeeCompany = "";
            age = 0;
            salary = 0;
            employeeId = 0;
        }
    public: // All the things below this are public
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
        void setName(string name){ // This is a setter function 
            employeeName = name;
        }
        string getName(){ // This is a getter function
            return employeeName;
        }
        void setCompany(string company){ // This is a setter function 
            employeeCompany = company;
        }
        string getCompany(){ // This is a getter function
            return employeeCompany;
        }
        void setAge(int age){ // This is a setter function 
            if(age >= 18){
                this->age = age;
            }
        }
        int getAge(){ // This is a getter function
            return age;
        }

        void AskForPromotion(){
            if(age > 30){
                cout << employeeName << " got promoted!" << endl;
            }
            else{
                cout << employeeName << ", sorry NO promotion for you!" << endl;
            }
        }
};

int main(){
    Employee employee1 = Employee("Maloth Aditya", "myCompany", 95); // This is how we call a parameterized constructor.
    Employee employee2 = Employee("Rohith", "Amazon", 25); // This is how we call a parameterized constructor.   

    employee1.AskForPromotion();
    employee2.AskForPromotion();
    return 0;
}