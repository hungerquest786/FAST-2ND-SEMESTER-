#include <iostream>
#include <string>

using namespace std;

class Laptop {
private:
    string brand;
    string model;
    string processor;
    int ram;
    int storage;
    bool ison;

public:
    // Constructor to initialize the laptop as turned off
    Laptop() : ison(false) {}

    void setBrand(const string &b) { brand = b; }
    void setModel(const string &m) { model = m; }
    void setProcessor(const string &p) { processor = p; }
    void setRam(int r) { ram = r; }
    void setStorage(int s) { storage = s; }

    void turnon() {
        ison = true;
        cout << "Laptop Turned on" << endl;
    }

    void turnoff() {
        ison = false;
        cout << "Laptop Turned off" << endl;
    }

    void runProgram() {
        if (ison) {
            cout << "Started Program Successfully" << endl;
        } else {
            cout << "Laptop is powered off. Cannot start the Program" << endl;
        }
    }

    void printSpecs() {
        cout << "Brand = " << brand << endl;
        cout << "Model = " << model << endl;
        cout << "Processor = " << processor << endl;
        cout << "RAM = " << ram << "GB" << endl;
        cout << "Storage = " << storage << "GB" << endl;
    }
};

void enterSpecs(Laptop &l, const string &name) {
    string s;
    int i;
    cout << name << ", Enter your Specs" << endl;

    cout << "Brand: ";
    cin.ignore(); // Ignore leftover newline from previous input
    getline(cin, s);
    l.setBrand(s);

    cout << "Model: ";
    getline(cin, s);
    l.setModel(s);

    cout << "Processor: ";
    getline(cin, s);
    l.setProcessor(s);

    cout << "RAM (in GB): ";
    cin >> i;
    l.setRam(i);

    cout << "Storage (in GB): ";
    cin >> i;
    l.setStorage(i);
}

int main() {
    Laptop Bilal;
    Laptop Ayesha;

    enterSpecs(Bilal, "Bilal");
    enterSpecs(Ayesha, "Ayesha");

    Bilal.printSpecs();
    Ayesha.printSpecs();

    return 0;
}
