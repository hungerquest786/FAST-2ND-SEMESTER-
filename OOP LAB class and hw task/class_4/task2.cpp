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

    Book(char*a,int r, float b) {
        title = a;
        price = b;
        stocks = new int(r);

    }
    

    ~Book() { 
        delete stocks;
    }

    void update();
    void buy();
    void display();
    float discount(int n);
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

float discount (int n ){
    if (n > 5 && n<10){
        return 0.95;
    }else if (n > 10){
        return 0.9;
    }else {
        return 0;
    }
}

void Book::buy() {
    cout << "How many copies do you want to buy?" << endl;
    int r;
    cin >> r;

    if (r > *stocks) {
        cout << "Not enough stock available!" << endl;
    } else {
        *stocks -= r; 
        int dis = discount(r);
        cout << "Copies bought successfully!" << endl;
        cout<<r<<"    "<<price*r*dis<<endl;
    }
}

int main() {
    Book myBook;
    myBook.display();

    Book mybook1("diddy party",3,6.99);
    mybook1.display();

    myBook.update();
    myBook.display();

    myBook.buy();
    myBook.display();

    return 0;
}
