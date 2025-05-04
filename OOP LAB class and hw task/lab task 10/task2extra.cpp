#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream in("vehicles.txt"); // note: spelling corrected

    if (!in) {
        cerr << "Error: Could not open file 'vehicles.txt'" << endl;
        return 1;
    }

    string str;
    while (getline(in, str)) {
        if (str.empty() || str[0] == '#') {
            continue;
        }

        istringstream ss(str);
        string type, id, name, year, extraData, certification;

        // Parse each field using comma as delimiter
        // if written in txt like this 
        //Car,101,Toyota,2015,Hybrid,Yes
        getline(ss, type, ','); // read from ss until next comma 
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, year, ',');
        getline(ss, extraData, ',');
        getline(ss, certification, ',');

        // Output parsed fields
        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "ExtraData: " << extraData << endl;
        cout << "Certification: " << certification << endl;
        cout << "-----------------------------" << endl;
    }

    in.close();
    return 0;
}
