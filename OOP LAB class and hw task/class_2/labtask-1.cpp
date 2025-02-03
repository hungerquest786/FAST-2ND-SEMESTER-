#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

int main() {
    int x;
    
    
    cout << "Enter the size of the array: ";
    cin >> x;

   
    int* array = new int[x];

    
    cout << "Enter " << x << " elements: ";
    for (int i = 0; i <x; i++) {
        cin >> *(array + i);
    }

 
    int sum = 0, max = *array;
    for (int i = 0; i < x; i++) {
        sum += *(array + i);
        if (*(array + i) > max) {
            max = *(array + i);
        }
    }

    cout << "Sum: " << sum << endl;
    cout << "Average: " << static_cast<double>(sum) / x << endl;
    cout << "Maximum value: " << max << endl;

   
    delete[] array;

    return 0;
}
