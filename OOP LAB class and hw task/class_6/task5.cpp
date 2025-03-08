#include <iostream>
using namespace std;

class device {
public:
    int deviceID;
    bool status;

    void displaydetail() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "ON" : "OFF") << endl;
    }
};

class smartphone : public device {
public:  
    float screenSize;

    void displaydetail() {
        cout << "Smartphone Details: " << endl;
        device::displaydetail();  
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class smartWatch : public device {
public:  
    bool heartRateMonitor;

    void displaydetail() {
        cout << "Smartwatch Details: " << endl;
        device::displaydetail();  
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "ON" : "OFF") << endl;
    }
};

class smartWearable : public smartWatch {
public:  
    int stepCounter;

    void displaydetail() {
        cout << "Smart Wearable Details: " << endl;
        smartWatch::displaydetail();  
        cout << "Step Counter: " << stepCounter << " steps" << endl;
    }
};

int main() {
   
    smartphone sp;
    cout << "Enter Smartphone Details:\n";
    cout << "Enter Device ID: ";
    cin >> sp.deviceID;
    cout << "Enter Status (1 for ON, 0 for OFF): ";
    cin >> sp.status;
    cout << "Enter Screen Size: ";
    cin >> sp.screenSize;
    cout << "\n";
    sp.displaydetail();

   
    smartWatch sw;
    cout << "\nEnter Smartwatch Details:\n";
    cout << "Enter Device ID: ";
    cin >> sw.deviceID;
    cout << "Enter Status (1 for ON, 0 for OFF): ";
    cin >> sw.status;
    cout << "Heart Rate Monitor (1 for ON, 0 for OFF): ";
    cin >> sw.heartRateMonitor;
    cout << "\n";
    sw.displaydetail();

 
    smartWearable swr;
    cout << "\nEnter Smart Wearable Details:\n";
    cout << "Enter Device ID: ";
    cin >> swr.deviceID;
    cout << "Enter Status (1 for ON, 0 for OFF): ";
    cin >> swr.status;
    cout << "Heart Rate Monitor (1 for ON, 0 for OFF): ";
    cin >> swr.heartRateMonitor;
    cout << "Enter Step Counter: ";
    cin >> swr.stepCounter;
    cout << "\n";
    swr.displaydetail();

    return 0;
}
