#include<iostream>
#include<ctime>
#include <unistd.h>
using namespace std;

class TeamCup {

    private:
    string brand;
    float teaLevel;
    float mugCapacity;
    char refelibility;
    int targetHour, targetMinute, targetSecond;

    public:
    
    void enter(void);
    void status(void);
    void drink(void);
    void refill(void);
    void info(void);
    void tea_reminder (void);
};

void TeamCup::enter() {
    cout << "Enter brand, mug capacity, and tea level: " << endl;
    cin >> brand >> mugCapacity >> teaLevel;
    if (teaLevel > mugCapacity) {
        teaLevel = mugCapacity; 
    }
}

void TeamCup::drink() {
    cout << "How much time tea consuming?" << endl;
    int time;
    for (size_t i = 0; i < time; i++)
    {
        teaLevel--;
        status();
        if (refelibility == 'Z'){
            refill();
        }
    }
    
}

void TeamCup::refill() {
    if (teaLevel == 0) {
        teaLevel = mugCapacity;
    }
}

void TeamCup::status() {
    if (teaLevel >= 90) {
        refelibility = 'S';
    } else if (teaLevel >= 80) {
        refelibility = 'R';
    } else if (teaLevel >= 70) {
        refelibility = 'X';
    } else if (teaLevel >= 20) {
        refelibility = 'U';
    } else {
        refelibility = 'Z';
    }
}

void TeamCup::info() {
    cout << "Data about the tea mug:\n";
    cout << "Brand: " << brand << "\nMug Capacity: " << mugCapacity << "\nTea Level: " << teaLevel << "\nRefill Status: " << refelibility << endl;
    
    if (refelibility == 'Z') {
        refill();
        cout << "Tea mug refilled! New tea level: " << teaLevel << endl;
    }
}


void TeamCup::tea_reminder() {
    while (true) {
        // Get the current time
        time_t now = time(NULL);
        tm *current = localtime(&now);

        int currentHour = current->tm_hour;
        int currentMinute = current->tm_min;
        int currentSecond = current->tm_sec;

        
        if (currentHour == targetHour && currentMinute == targetMinute && currentSecond == targetSecond) {
            std::cout << "\n⏰ Reminder: It's time for team! ⏰\n";
            break;
        }

       
        sleep(1);
    }
}

int main() {
    TeamCup cup;
    cup.enter();

    int choice;
    do {
        cout << "\nMenu:\n1. Drink\n2. Refill\n3. Check Status\n4. Display Info\n5. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cup.drink();
                break;
            case 2:
                cup.refill();
                break;
            case 3:
                cup.status();
                break;
            case 4:
                cup.info();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
