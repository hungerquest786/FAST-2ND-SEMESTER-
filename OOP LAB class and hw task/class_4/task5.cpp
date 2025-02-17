#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    float* price;
    int* stocks;
    int* r;
    float* cost;
    int bookID;  
    static int bookCounter;  

public:
    
    Book() : price(new float(0.00)), stocks(new int(30)), r(new int(0)), cost(new float(0.00)), bookID(++bookCounter) {
        title = "Unknown";
    }

    
    Book(const char* title, int stocks, float price) 
        : title(title), price(new float(price)), stocks(new int(stocks)), r(new int(0)), cost(new float(0.00)), bookID(++bookCounter) {}

   
    Book(const Book& a) 
        : title(a.title), price(new float(*a.price)), stocks(new int(*a.stocks)), r(new int(*a.r)), cost(new float(*a.cost)), bookID(++bookCounter) {}

    ~Book() { 
        delete price;
        delete stocks;
        delete cost;
        delete r;
        cout << "Data deleted for Book ID: " << bookID << endl;
    }

    void update();
    void buy();
    void display();
    float discount(int n);
};


int Book::bookCounter = 0;

void Book::display() {
    cout << "Book ID: " << bookID << endl;
    cout << "Title: " << title << endl;
    cout << "Price: $" << *price << endl;
    cout << "Stocks: " << *stocks << endl;

    if (*stocks <= 5) {
        cout << "Warning: Stocks are too low!" << endl;
    }
    cout << "----------------------------" << endl;
}

void Book::update() {
    cout << "Enter book details (Title, Price, Stock):" << endl;
    cin.ignore();
    getline(cin, title);
    cin >> *price;
    cin >> *stocks;
}

float Book::discount(int n) {
    if (n > 5 && n < 10) {
        return 0.95;
    } else if (n > 10) {
        return 0.9;
    } else {
        return 1.0;
    }
}

void Book::buy() {
    cout << "How many copies do you want to buy?" << endl;
    cin >> *r;

    if (*r > *stocks) {
        cout << "Not enough stock available!" << endl;
    } else {
        *stocks -= *r;
        float dis = discount(*r);
        *cost = (*price) * (*r) * dis;
        cout << "Copies bought successfully!" << endl;
        cout << "Total cost: $" << *cost << endl;
    }
}


int main() {
    Book myBook;
    myBook.display();

    Book mybook1("Diddy Party", 3, 6.99);
    mybook1.display();

    Book mybook2(mybook1);
    mybook2.display();

    myBook.update();
    myBook.display();

    myBook.buy();
    myBook.display();

    return 0;
}
