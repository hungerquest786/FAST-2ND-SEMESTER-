#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;



int main() {
    ifstream in("vehicle2.txt"); // note: spelling corrected

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
        }
        
        
    }

    in.close();
    return 0;
}
