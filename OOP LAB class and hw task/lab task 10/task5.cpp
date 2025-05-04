#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;



int main() {
    ifstream in("vehicle3.txt"); // note: spelling corrected

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
        string type,rest;

        // Parse each field using comma as delimiter
        // if written in txt like this 
        //Car,101,Toyota,2015,Hybrid,Yes
        getline(ss, type, ','); // read from ss until next comma 
        getline (ss,rest);

        // Output parsed fields
        if (type =="AutonomousCar")
        {
            string sub = rest.substr(rest.find(":")+1, rest.find(",")-1);
            cout << "auto car version:"<<sub << endl;
        }else if (type =="Electric Vehicle")
        {
            string sub = rest.substr(rest.find(":")+1, rest.find(",")-1);
            cout << "electric car battery:"<<sub<<endl;
        }else if (type == "HybridTruck") {
            size_t colon1 = rest.find(":");
            size_t pipe = rest.find("|");
            string sub1 = rest.substr(colon1 + 1, pipe - colon1 - 1);
        
            size_t colon2 = rest.find(":", pipe); // to , from 
            size_t comma2 = rest.find(",", colon2); 
            string sub2 = rest.substr(colon2 + 1, comma2 - (colon2 + 1)); 
        
            int r1 = stoi(sub1);
            int r2 = stoi(sub2);
            cout << "cargo:" << r1 << "|";
            cout << " battery:" << r2 << endl;
        }else {
            cout << "error"<<endl;
        }
        
        
    }

    in.close();
    return 0;
}
