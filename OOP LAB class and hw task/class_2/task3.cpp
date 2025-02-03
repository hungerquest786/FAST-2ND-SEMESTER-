#include <iostream>
using namespace std;

typedef struct employee
{
    int employeeid;
    string name;
    string department;
    float salary;
} Employee;

void enterdata(struct employee *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter employee ID: ";
        cin >> A[i].employeeid;
        cout << "Enter name: ";
        cin >> A[i].name;
        cout << "Enter department: ";
        cin >> A[i].department;
        cout << "Enter salary: ";
        cin >> A[i].salary;
    }
}

void display(struct employee *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Employee ID: " << A[i].employeeid << ", ";
        cout << "Name: " << A[i].name << ", ";
        cout << "Department: " << A[i].department << ", ";
        cout << "Salary: " << A[i].salary << endl;
    }
}

void search(struct employee *A, int n)
{
    int r;
    cout << "Enter employee ID to search: ";
    cin >> r;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (A[i].employeeid == r)
        {
            cout << "Employee found: " << endl;
            cout << "Employee ID: " << A[i].employeeid << ", ";
            cout << "Name: " << A[i].name << ", ";
            cout << "Department: " << A[i].department << ", ";
            cout << "Salary: " << A[i].salary << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Employee not found!" << endl;
    }
}

int main()
{
    Employee *A;
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    A = new Employee[n];

    int choice;
    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Enter Employee Data" << endl;
        cout << "2. Display All Employees" << endl;
        cout << "3. Search Employee by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enterdata(A, n);
            break;
        case 2:
            display(A, n);
            break;
        case 3:
            search(A, n);
            break;
        case 4:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice, please try again!" << endl;
        }
    } while (choice != 4);

    delete[] A;
    return 0;
}
