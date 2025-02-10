#include <iostream>
using namespace std;

class Planar {
private:
    string planar[12][30];

public:
    void add();
    void remove();
    void update();
    void display();

    Planar() {
        for (size_t i = 0; i < 12; i++) {
            for (size_t j = 0; j < 30; j++) {
                planar[i][j] = "00000";
            }
        }
    }
};

void Planar::add() {
    int month, day;
    do {
        cout << "Enter the month (1-12): ";
        cin >> month;
        cout << "Enter the day (1-30): ";
        cin >> day;
    } while (month < 1 || month > 12 || day < 1 || day > 30);

    cout << "Enter the schedule: ";
    cin >> planar[month - 1][day - 1];
}

void Planar::update() {
    int month, day;
    do {
        cout << "Enter the month (1-12) to update: ";
        cin >> month;
        cout << "Enter the day (1-30) to update: ";
        cin >> day;
    } while (month < 1 || month > 12 || day < 1 || day > 30);

    cout << "Enter the updated schedule: ";
    cin >> planar[month - 1][day - 1];
}

void Planar::remove() {
    int month, day;
    do {
        cout << "Enter the month (1-12) to remove: ";
        cin >> month;
        cout << "Enter the day (1-30) to remove: ";
        cin >> day;
    } while (month < 1 || month > 12 || day < 1 || day > 30);

    planar[month - 1][day - 1] = "00000";
    cout << "Schedule removed.\n";
}

void Planar::display() {
    for (size_t i = 0; i < 12; i++) {
        for (size_t j = 0; j < 30; j++) {
            if (planar[i][j] != "00000") {
                cout << "Month " << i + 1 << ", Day " << j + 1 << ": " << planar[i][j] << endl;
            }
        }
    }
}

int main() {
    Planar planner;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add schedule\n";
        cout << "2. Update schedule\n";
        cout << "3. Remove schedule\n";
        cout << "4. Display schedules\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            planner.add();
            break;
        case 2:
            planner.update();
            break;
        case 3:
            planner.remove();
            break;
        case 4:
            planner.display();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
