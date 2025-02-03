#include <iostream>
using namespace std;

typedef struct student
{
    string name;
    int roll_number;
    float marks[5];
    float avg;
    char grade;
} Student;

void enterdata(int n, Student *A)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter name: ";
        cin >> A[i].name;
        cout << "Enter roll number: ";
        cin >> A[i].roll_number;
        cout << "Enter marks for 5 subjects: ";
        for (int j = 0; j < 5; j++)
        {
            cin >> A[i].marks[j];
        }
    }
}

void calculateavg(int n, Student *A)
{
    float r;
    for (int i = 0; i < n; i++)
    {
        r = 0;
        for (int j = 0; j < 5; j++)
        {
            r += A[i].marks[j];
        }
        r = r / 5;
        A[i].avg = r;
    }
}

void grade(int n, Student *A)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i].avg > 90)
        {
            A[i].grade = 'A';
        }
        else if (A[i].avg > 80)
        {
            A[i].grade = 'B';
        }
        else if (A[i].avg > 70)
        {
            A[i].grade = 'C';
        }
        else if (A[i].avg > 60)
        {
            A[i].grade = 'D';
        }
        else if (A[i].avg > 50)
        {
            A[i].grade = 'E';
        }
        else
        {
            A[i].grade = 'F';
        }
    }
}

void display(int n, Student *A)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << " Details: \n";
        cout << "Name: " << A[i].name << endl;
        cout << "Roll Number: " << A[i].roll_number << endl;
        cout << "Marks: ";
        for (int j = 0; j < 5; j++)
        {
            cout << A[i].marks[j] << " ";
        }
        cout << "\nAverage: " << A[i].avg << endl;
        cout << "Grade: " << A[i].grade << endl;
    }
}

int main()
{
    Student *A;
    int n;
    int choice;

    cout << "Enter number of students: ";
    cin >> n;

    A = new Student[n];

    do
    {
        // Display the menu
        cout << "\nMenu:\n";
        cout << "1. Enter Student Data\n";
        cout << "2. Calculate Averages\n";
        cout << "3. Assign Grades\n";
        cout << "4. Display Student Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enterdata(n, A);
            break;
        case 2:
            calculateavg(n, A);
            break;
        case 3:
            grade(n, A);
            break;
        case 4:
            display(n, A);
            break;
        case 5:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    delete[] A;

    return 0;
}
