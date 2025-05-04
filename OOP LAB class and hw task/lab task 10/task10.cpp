#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    // Step 2: Open file for reading
    ifstream file("record.txt", ios::in);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    
    
    // "Record 1\n" -> 9 bytes
    // "Record 2\n" -> 9 bytes
    // So, start of Record 3 = byte offset 18
    // file.seekg(20, ios::beg);

    // can do like this 
    string s;
    getline(file, s);
    cout << file.tellg()<<endl;
    cout << s << endl;
    int r = file.tellg();
    file.seekg(ios :: beg);
    file.seekg(22 , ios :: beg);

    // Step 4: Read only the third record
    string record;
    getline(file, record);

    // Step 5: Output
    cout << "Third record:" << record << endl;

    file.close();
    return 0;
}
