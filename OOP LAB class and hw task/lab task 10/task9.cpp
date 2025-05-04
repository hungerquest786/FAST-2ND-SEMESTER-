#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("log.txt", ios::in);

    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    char buffer[11];          // One extra byte for null terminator
    file.read(buffer, 10);    // Read 10 characters
    buffer[10] = '\0';        // Null-terminate for safe printing always add this 
    cout << "Read (10 chars): " << buffer << endl;
    cout << "Current position after read(): " << file.tellg() << endl;

    string s;
    getline(file, s);         // Read next line
    cout << "Next line: " << s << endl;
    cout << "Position after getline(): " << file.tellg() << endl;

    getline(file, s);         // Read one more line
    cout << "Another line: " << s << endl;
    cout << "Position after second getline(): " << file.tellg() << endl;

    file.close();
    return 0;
}
