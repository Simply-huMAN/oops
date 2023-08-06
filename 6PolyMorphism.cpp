//Polymorphism is the ability of an object to take on many forms.
//The most common use of polymorphism in OOP occurs when a parent class reference is used to refer to a child class object.
//Poly means many and morphism means forms.
//There are two types of polymorphism in C++:
//1. Compile time polymorphism
//2. Run time polymorphism
//Compile time polymorphism is achieved using function overloading and operator overloading.
//Run time polymorphism is achieved using virtual functions.

#include <iostream>
using namespace std;

class AbstractEmployee{ // This is an abstract class
    virtual void AskForPromotion() = 0; // This is a pure virtual function
    //Any class that inherits this class must implement this function.
    //This function is not defined here.
    //This function is defined in the derived class.
    //This function is defined in the derived class because it is a pure virtual function.
};

class Employee:AbstractEmployee{ //Employee is a derived class of AbstractEmployee
    private: // All the things below this are private
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
    protected:
        string employeeName;
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
        virtual void Work(){ // This is a virtual function
            //This function is virtual because it is defined in the base class and it is overridden in the derived class.
            cout << employeeName << " is checking email, task backlog, performing tasks..." << endl;
        }
};

class Developer:public Employee{ // Developer is a derived class of Employee
    public: // All the things below this are public
        string favProgrammingLanguage;
        Developer(string name, string company, int age, string favProgrammingLanguage):Employee(name, company, age){ // This is a parameterized constructor
        //Since the Employee already has a constructor, we need to call that constructor using the Employee(name, company, age) syntax.
            this->favProgrammingLanguage = favProgrammingLanguage;
        }
        void FixBug(){
            cout << getName() << " fixed bug using " << favProgrammingLanguage << endl;
        }
        void Work(){
            cout << employeeName << " is writing " << favProgrammingLanguage << " code." << endl;
        }
};

class Teacher:public Employee{ // Teacher is a derived class of Employee
    public: // All the things below this are public
        string subject;
        Teacher(string name, string company, int age, string subject):Employee(name, company, age){ // This is a parameterized constructor
        //Since the Employee already has a constructor, we need to call that constructor using the Employee(name, company, age) syntax.
            this->subject = subject;
        }
        void PrepareLesson(){
            cout << employeeName << " is preparing " << subject << " lesson." << endl;
        }
        void Work(){
            cout << employeeName << " is teaching " << subject << "." << endl;
        }
};

int main(){
    Developer dev = Developer("Maloth Aditya", "Google", 19, "C++");
    dev.FixBug();
    Teacher teacher = Teacher("Jack", "Cool School", 35, "History");
    dev.Work();
    teacher.Work();
    Employee *e1 = &dev;
    Employee *e2 = &teacher;
    e1->Work(); // If Work function of Developer class is not virtual, then this will print "Maloth Aditya is checking email, task backlog, performing tasks..."
    e2->Work();
    return 0;
}