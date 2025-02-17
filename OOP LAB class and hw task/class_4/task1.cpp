#include <iostream>
using namespace std;

class Book {
private:
    string title;
    float price;
    int* stocks;

public:
    Book() {
        title = "Unknown";
        price = 0.00;
        stocks = new int(30);
    }

    ~Book() { 
        delete stocks;
    }

    void update();
    void buy();
    void display();
};

void Book::display() {
    cout << "Title: " << title << endl;
    cout << "Price: $" << price << endl;
    cout << "Stocks: " << *stocks << endl;

    if (*stocks <= 5) {
        cout << "Stocks are too low" << endl;
    }
}

void Book::update() {
    cout << "Enter book details (Title, Price, Stock):" << endl;
    cin.ignore(); 
    getline(cin, title); 
    cin >> price;
    cin >> *stocks;
}

void Book::buy() {
    cout << "How many copies do you want to buy?" << endl;
    int r;
    cin >> r;

    if (r > *stocks) {
        cout << "Not enough stock available!" << endl;
    } else {
        *stocks -= r; 
        cout << "Copies bought successfully!" << endl;
        display();
    }
}

int main() {
    Book myBook;
    myBook.display();

    myBook.update();
    myBook.display();

    myBook.buy();
    myBook.display();

    return 0;
}
