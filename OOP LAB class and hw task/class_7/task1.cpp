#include <iostream>
using namespace std;

class currency {
protected:
    float amount;
    int currencycode;
    char currencysymbol;  
    float exchangerate;
public:
    void enter() {
        cin >> amount >> currencysymbol >> currencycode >> exchangerate;
    }
    
    virtual void converttobase() {
        cout << "Sets exchange rate" << endl;
    }
    
    void convertto(char targetcurrency) { 
        if (targetcurrency == 'd') {
            amount = exchangerate * 2.25;
        } else if (targetcurrency == 'e') {
            amount = exchangerate * 1.25;
        } else if (targetcurrency == 'r') {
            amount = exchangerate * 0.25;
        }
    }
    
    virtual void displaycurrency() {
        cout << "Displays amount: " << amount << endl;
    }
};

class dollar : public currency {
public:
    void converttobase() override { 
        exchangerate = 3;
    }
    
    void displaycurrency() override {
        cout << "Dollar Amount: " << amount << endl;
    }
};

class euro : public currency {
public:
    void converttobase() override { 
        exchangerate = 2;
    }
    
    void displaycurrency() override {
        cout << "Euro Amount: " << amount << endl;
    }
};

class rupee : public currency {
public:
    void converttobase() override { 
        exchangerate = 1;
    }
    
    void displaycurrency() override {
        cout << "Rupee Amount: " << amount << endl;
    }
};

int main() {
    dollar d;
    euro e;
    rupee r;

    cout << "Enter currency details (amount, symbol, code, exchange rate): ";
    d.enter();
    d.converttobase();
    d.convertto('e'); 
    d.displaycurrency();

    cout << "Enter currency details (amount, symbol, code, exchange rate): ";
    e.enter();
    e.converttobase();
    e.convertto('r'); 
    e.displaycurrency();

    cout << "Enter currency details (amount, symbol, code, exchange rate): ";
    r.enter();
    r.converttobase();
    r.convertto('d'); 
    r.displaycurrency();

    return 0;
}
