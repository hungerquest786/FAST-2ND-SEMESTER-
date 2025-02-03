#include <iostream>
#include <string>
using namespace std;

void enter_participent(string arr2[5], int x) {
    cout << "Enter participants' names:" << endl;
    for (int j = 0; j < x; j++) {
        cin >> arr2[j];
    }
}

void enter_donation(int arr2[5], int x) {
    for (int j = 0; j < x; j++) {
        do {
            cout << "Enter donation amount for student " << j + 1 << " (minimum $10): ";
            cin >> arr2[j];
            if (arr2[j] < 10) {
                cout << "Cannot register for less than $10." << endl;
            }
        } while (arr2[j] < 10);
    }
}

void attendence_checker(string name[5], string name1[5], int x, int y) {
    string r;
    cout << "Enter the name you want to check:" << endl;
    cin >> r;

    bool found = false;
    for (int j = 0; j < x; j++) {
        if (name[j] == r) {
            cout << r << " is present in Event 1." << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << r << " is not present in Event 1." << endl;

    found = false;
    for (int j = 0; j < y; j++) {
        if (name1[j] == r) {
            cout << r << " is present in Event 2." << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << r << " is not present in Event 2." << endl;
}

void total_donation(int arr1[5], int arr2[5], int x, int y) {
    int total = 0;
    for (int i = 0; i < x; i++) {
        total += arr1[i];
    }
    for (int j = 0; j < y; j++) {
        total += arr2[j];
    }
    cout << "Total amount submitted by the two teams is: $" << total << endl;
}

void display(string arr1[5], string arr2[5], int x, int y) {
    cout << "Names of participants for Event 1 (in reverse order):" << endl;
    for (int j = x - 1; j >= 0; j--) { 
        cout << arr1[j] << endl;
    }
    cout << "Names of participants for Event 2 (in reverse order):" << endl;
    for (int j = y - 1; j >= 0; j--) { 
        cout << arr2[j] << endl;
    }
}

void display_pattern(int x, int y) {
    cout << "Bar graph for Event 1 participants:" << endl;
    for (int j = 0; j < x; j++) {
        cout << "*";
    }
    cout << endl;

    cout << "Bar graph for Event 2 participants:" << endl;
    for (int j = 0; j < y; j++) {
        cout << "*";
    }
    cout << endl;
}

int main() {
    cout << "Enter details for Event 1:" << endl;
    int x = 0;
    do {
        cout << "Enter number of participants (max 5): ";
        cin >> x;
        if (x > 5) {
            cout << "Error: Too many participants. Enter again." << endl;
        }
    } while (x > 5);

    string name1[5];
    char attendence1[5]; 
    int donation1[5];

    enter_participent(name1, x);
    enter_donation(donation1, x);

    cout << "\nEnter details for Event 2:" << endl;
    int y = 0;
    do {
        cout << "Enter number of participants (max 5): ";
        cin >> y;
        if (y > 5) {
            cout << "Error: Too many participants. Enter again." << endl;
        }
    } while (y > 5);

    string name2[5];
    char attendence2[5];  
    int donation2[5];

    enter_participent(name2, y);
    enter_donation(donation2, y);

    cout << "\n--- Event Information ---" << endl;
    display(name1, name2, x, y);
    display_pattern(x, y);
    total_donation(donation1, donation2, x, y);

    cout << "\n--- Attendance Checker ---" << endl;
    attendence_checker(name1, name2, x, y);

    return 0;
}
