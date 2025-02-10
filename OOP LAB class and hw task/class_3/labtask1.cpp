#include<iostream>
using namespace std;

class Marker {

    private:
    string marker;
    string brand;
    char color;
    float inklevel;
    char refelibility;
    int marker_num;

    public:
    
    void markertally(int i) {
        marker_num = i;
    }
    void enter(void);
    void status(void);
    void write(void);
    void refill(void);
    void info(void);
};

void Marker::enter() {
    cout << "Enter marker name, brand, color, and ink level: " << endl;
    cin >> marker >> brand >> color >> inklevel;
}

void Marker::write() {
    cout << "How much has the ink level decreased?" << endl;
int time;
    for (size_t i = 0; i < time; i++)
    {
        inklevel--;
        status();
        if (refelibility == 'Z'){
            refill();
        }
    }
}

void Marker::refill() {
    if (inklevel >= 0 && inklevel < 50) {
        inklevel = 100;
    }
}

void Marker::status() {
    if (inklevel >= 90) {
        refelibility = 'S';
    } else if (inklevel >= 80) {
        refelibility = 'R';
    } else if (inklevel >= 70) {
        refelibility = 'X';
    } else if (inklevel >= 50) {
        refelibility = 'U';
    } else {
        refelibility = 'Z';
    }
}

void Marker::info() {
    cout << "Data about the marker " << marker_num << ":\n";
    cout << "Marker: " << marker << "\nBrand: " << brand << "\nColor: " << color << "\nInk Level: " << inklevel << "\nRefill Status: " << refelibility << endl;
    
    if (refelibility == 'Z') {
        refill();
        cout << "Marker refilled! New ink level: " << inklevel << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of markers: " << endl;
    cin >> n;

    Marker* pens = new Marker[n];

    for (int i = 0; i < n; i++) {
        pens[i].markertally(i + 1);
        pens[i].enter();
    }

    int choice, marker_index;
    do {
        cout << "\nMenu:\n1. Write\n2. Refill\n3. Check Status\n4. Display Info\n5. Exit\nChoose an option: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter marker number (1 to " << n << "): ";
            cin >> marker_index;
            if (marker_index < 1 || marker_index > n) {
                cout << "Invalid marker number!" << endl;
                continue;
            }
        }

        switch (choice) {
            case 1:
                pens[marker_index - 1].write();
                break;
            case 2:
                pens[marker_index - 1].refill();
                break;
            case 3:
                pens[marker_index - 1].status();
                break;
            case 4:
                pens[marker_index - 1].info();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    delete[] pens; // Free allocated memory
    return 0;
}
