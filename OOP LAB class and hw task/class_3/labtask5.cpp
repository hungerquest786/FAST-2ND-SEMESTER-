#include <iostream>
using namespace std;

class Shop {
private:
    float* price;
    string* item;
    int n;
    int* buylist;
    int r;

public:
    Shop() : price(nullptr), item(nullptr), buylist(nullptr), n(0), r(0) {} // Constructor

    void enter();
    void display();
    void add();
    void update();
    void buy();
    void receipt();
    
    ~Shop() { 
        delete[] price;
        delete[] item;
        delete[] buylist;
    }
};

void Shop::enter() {
    cout << "Enter number of items to add: ";
    cin >> n;
    
    price = new float[n];
    item = new string[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Enter price and name of item " << i + 1 << ": ";
        cin >> price[i] >> item[i];
    }
}

void Shop::add() {
    cout << "Enter price and name of the new item: ";
    
    float newPrice;
    string newItem;
    cin >> newPrice >> newItem;

    float* temp1 = new float[n + 1];
    string* temp2 = new string[n + 1];

    for (int i = 0; i < n; i++) { 
        temp1[i] = price[i];
        temp2[i] = item[i];
    }

    temp1[n] = newPrice;  
    temp2[n] = newItem;
    
    delete[] price; 
    delete[] item;


    // allocates new memory by changing memory 
    price = temp1;  
    item = temp2;
    
    n++; 
}

void Shop::update() {
    string r;
    bool found = false;
    
    do {
        cout << "Enter name of item to update price: ";
        cin >> r;

        for (int i = 0; i < n; i++) {
            if (item[i] == r) {
                cout << "Enter new price: ";
                cin >> price[i];
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Item not found, try again.\n";
        }

    } while (!found);
}

void Shop::display() {
    cout << "\n--- Items in Shop ---\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << item[i] << " - $" << price[i] << endl;
    }
}

void Shop::buy() {
    display();

    cout << "Enter the number of items you want to buy: ";
    cin >> r;

    buylist = new int[r];

    cout << "Enter the indices of the items you want to buy (1 to " << n << "): ";
    for (int i = 0; i < r; i++) {
        int index;
        do {
            cin >> index;
            if (index < 1 || index > n) {
                cout << "Invalid index! Enter a valid index (1 to " << n << "): ";
            }
        } while (index < 1 || index > n);
        buylist[i] = index - 1; 
    }
}

void Shop::receipt() {
    cout << "\n--- Receipt ---\n";
    float total = 0;
    for (int i = 0; i < r; i++) {
        cout << item[buylist[i]] << " - $" << price[buylist[i]] << endl;
        total += price[buylist[i]];
    }
    cout << "Total: $" << total << endl;
}


int main() {
    Shop shop;
    int choice;

    do {
        cout << "\n--- Shop Menu ---\n";
        cout << "1. Enter items\n2. Display items\n3. Add new item\n4. Update item price\n";
        cout << "5. Buy items\n6. Generate receipt\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: shop.enter(); break;
            case 2: shop.display(); break;
            case 3: shop.add(); break;
            case 4: shop.update(); break;
            case 5: shop.buy(); break;
            case 6: shop.receipt(); break;
            case 7: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
