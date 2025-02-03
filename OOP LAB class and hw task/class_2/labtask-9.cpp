#include <iostream>
using namespace std;

typedef struct student
{
    string name;
    int rollnumber;
    int totalmarks;
} Student;

void enter(int n, Student *A)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> A[i].name;
        cout << "Enter roll number of student " << i + 1 << ": ";
        cin >> A[i].rollnumber;
        cout << "Enter total marks of student " << i + 1 << ": ";
        cin >> A[i].totalmarks;
    }
}

void display(int n, Student *A)
{
    cout << "\nDisplaying all students:\n";
    for (size_t i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Name: " << A[i].name << endl;
        cout << "Roll Number: " << A[i].rollnumber << endl;
        cout << "Total Marks: " << A[i].totalmarks << endl;
    }

    studenthighestmarks(n ,A);
}


void studenthighestmarks (int n , Student*A){
    int max ;
    int index;

    max = A[0].totalmarks;
    index = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (max < A[i].totalmarks){
            max = A[i].totalmarks;
            index = i ;
        }
    }

    cout<<"student with highest marks is"<<A[index].totalmarks<<"with marks:"<<max<<endl;
    
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
        cout << "\nMenu:\n";
        cout << "1. Enter Students Data\n";
        cout << "2. Add a New Student\n";
        cout << "3. Remove a Student\n";
        cout << "4. Search for a Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enter(n, A);
            break;

        case 2:
            display(n, A);
            break;
        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice, please try again!" << endl;
        }
    } while (choice != 6);

    delete[] A;
    return 0;
}
