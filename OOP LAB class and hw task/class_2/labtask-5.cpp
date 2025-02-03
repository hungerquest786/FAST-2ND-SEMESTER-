#include <iostream>
using namespace std;

void concatination(string a, string b) {
    cout << a + b << endl;
}

void compression(string a) {
    int arr[127] = {0}; 
    int l = a.length();
    for (size_t i = 0; i < l; i++) {
        if (arr[a.at(i)] == 0) {
            cout << a.at(i);
            arr[a.at(i)]++;
        }
    }
    cout << endl;
}

void length(string a) {
    cout << a.length() << endl;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << "Concatenation: ";
    concatination(a, b);
    
    cout << "Compression of first string: ";
    compression(a);
    
    cout << "Length of first string: ";
    length(a);
    
    cout << "Length of second string: ";
    length(b);

    return 0;
}
