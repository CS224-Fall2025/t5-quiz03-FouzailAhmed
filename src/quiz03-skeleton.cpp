#include <iostream>
#include <string>
using namespace std;


class Employee {

protected:

    string name;
    double salary;
    static int employeeCount;
    
public:

    Employee(string n, double s) {

        name = n;
        salary = s;
        employeeCount++; 

    }


    virtual void displayInfo() {
        cout << "Name: " << name << ", Salary: " << salary;

    }


    static void showTotalEmployees() {
        cout << "Total Employees Created: " << employeeCount << endl;

    }


    virtual ~Employee() {
        employeeCount--; 

    }


};


int Employee::employeeCount = 0;


class Staff : public Employee { //-

private:

    string department;

public:

    Staff(string n, double s, string d) : Employee(n, s), department(d) {}


    void displayInfo() override {

        cout << "Name: " << name << " (Staff), Salary: " << salary << endl; //------------ overide

    }


};


class Faculty : public Employee {


private:

    string department;

public:

    Faculty(string n, double s, string d) : Employee(n, s), department(d) {}


    void displayInfo() override {

        cout << "Name: " << name << " (Faculty), Salary: " << salary << endl; //------------ overide

    }


};




int main() {

    int n;
    cin >> n; 



    Employee* employees[n]; 


    for (int i = 0; i < n; ++i) {


        string type; 
        string name; 
        string department;
        double salary;



        cin >> type >> name >> salary;

        if (type == "Staff") {

            cin >> department;
            employees[i] = new Staff(name, salary, department); 

        } else if (type == "Faculty") {


            cin >> department;
            employees[i] = new Faculty(name, salary, department); 

        }


    }


    for (int i = 0; i < n; ++i) {

        employees[i]->displayInfo();

    }


    Employee::showTotalEmployees();


    for (int i = 0; i < n; ++i) {

        delete employees[i];

    }


    return 0;


}




