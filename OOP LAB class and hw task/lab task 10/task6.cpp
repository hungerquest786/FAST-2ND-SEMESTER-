#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

class inventoryItem
{
    public:
    static int itemID;
    char itemName[20];

    
    inventoryItem (string x)
    {
        this->itemID++;
        strncpy(itemName, x.c_str(), 19);
        itemName[19] = '\0';  
    }
};

 int inventoryItem :: itemID = 0;

void writetofile (inventoryItem &a)
{
    ofstream file;
    if(!file)
    {
        cerr << "error"<<endl;
    }
    file.open("inventory.dat", ios :: binary);
    file.write(reinterpret_cast<char*>(&a.itemID),sizeof(a.itemID));
    file.write(a.itemName,20);
    file.close();
}

void readfromfile()
{
    ifstream file;
    if(!file)
    {
        cerr << "error"<<endl;
    }

    int x;
    char y[20];
    file.open("inventory.dat", ios :: binary);
    file.read(reinterpret_cast<char*>(&x),sizeof(x));
    file.read(y,20);

    cout << x << endl;
    cout << y << endl;
    file.close();
}


int main() {
    // Create and write
    inventoryItem item1("Wrench");
    writetofile(item1);

    // Read into a different object

    readfromfile();

    // Output
    cout << "Loaded Item ID: " << item1.itemID << endl;
    cout << "Loaded Item Name: " << item1.itemName << endl;

    return 0;
}