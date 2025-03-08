#include <iostream>
using namespace std;

class Employee 
{
    
    public :
    string name;
    int age;
    float salary;
    Employee(string n, int a, float s){
        name = n;
        age = a;
        salary = s;
    }
};

class Manager : virtual public Employee{
    private:
    float bonus ;
    public:
    Manager(string n, int a, float s, float b) : Employee(n, a, s){
        bonus = b;
    }

    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
    }
};

int main(){
Manager m("diddy", 100, 69.99 , 100);
m.display();
}