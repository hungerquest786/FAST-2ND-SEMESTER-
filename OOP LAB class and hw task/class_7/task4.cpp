#include<iostream>
using namespace std;

class person {
    public : 
        string name;
        int id;
        string address;
        int phone_number;
        string email;
        virtual void displayinfo() = 0;
        virtual void updateinfo() {
            cout << "Enter Name, ID, Address, Phone Number, Email: ";
            cin >> name >> id >> address >> phone_number >> email;
        }
};

class student : public person {
    protected:
        float gpa;
        int enrollmentyear;
    public:
        student(float g, int year) : gpa(g), enrollmentyear(year) {}
        void updateinfo() override {
            person::updateinfo();
            cout << "Enter GPA and Enrollment Year: ";
            cin >> gpa >> enrollmentyear;
        }
        void displayinfo() override {
            cout << "Name : " << name << endl;
            cout << "ID : " << id << endl;
            cout << "Address : " << address << endl;
            cout << "Phone number : " << phone_number << endl;
            cout << "Email : " << email << endl;
            cout << "GPA : " << gpa << endl;
            cout << "Enrollment year : " << enrollmentyear << endl;
        }
};

class professor : public person {
    protected:
        float salary;
        string coursetaught;
    public:
        professor(float sal, string course) : salary(sal), coursetaught(course) {}
        void updateinfo() override {
            person::updateinfo();
            cout << "Enter Salary and Course Taught: ";
            cin >> salary >> coursetaught;
        }
        void displayinfo() override {
            cout << "Name : " << name << endl;
            cout << "ID : " << id << endl;
            cout << "Address : " << address << endl;
            cout << "Phone number : " << phone_number << endl;
            cout << "Email : " << email << endl;
            cout << "Salary : " << salary << endl;
            cout << "Course taught : " << coursetaught << endl;
        }
};

class staff : public person {
    protected:
        string position;
        int salary;
    public:
        staff(string pos, int sal) : position(pos), salary(sal) {}
        void updateinfo() override {
            person::updateinfo();
            cout << "Enter Position and Salary: ";
            cin >> position >> salary;
        }
        void displayinfo() override {
            cout << "Name : " << name << endl;
            cout << "ID : " << id << endl;
            cout << "Address : " << address << endl;
            cout << "Phone number : " << phone_number << endl;
            cout << "Email : " << email << endl;
            cout << "Position : " << position << endl;
            cout << "Salary : " << salary << endl;
        }
};

int main() {
    student s(3.8, 2022);
    professor p(75000, "Physics");
    staff st("Admin", 50000);
    
    cout << "Update student info: " << endl;
    s.updateinfo();
    cout << "Update professor info: " << endl;
    p.updateinfo();
    cout << "Update staff info: " << endl;
    st.updateinfo();
    
    cout << "---------------------------------" << endl;
    s.displayinfo();
    cout << "---------------------------------" << endl;
    p.displayinfo();
    cout << "---------------------------------" << endl;
    st.displayinfo();
    
    return 0;
}
