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

public:
  
    Book() {
        title = "Unknown";
        price = new float(0.00); 
        stocks = new int(30);
        r = new int(0);  
        cost = new float(0.00);
    }

    
    Book(const string title, int stocks, float price) {
        this->title = title;
        this->price = new float(price);
        this->stocks = new int(stocks);
        r = new int(0);  
        cost = new float(0.00);
    }

   
    Book(const Book& a) {
        title = a.title;  // Deep copy (due to std::string's behavior)
        price = new float(*a.price);
        stocks = new int(*a.stocks);
        r = new int(*a.r);
        cost = new float(*a.cost);
    }


    
    ~Book() { 
        delete price;
        delete stocks;
        delete cost;
        delete r;
        cout << "Data deleted" << endl;
    }

 
    void update();
    void buy();
    void display();
    float discount(int n);
};

void Book::display() {
    cout << "Title: " << title << endl;
    cout << "Price: $" << *price << endl;
    cout << "Stocks: " << *stocks << endl;

    if (*stocks <= 5) {
        cout << "Stocks are too low" << endl;
    }
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

// Main Function
int main() {
    Book myBook;
    myBook.display();

    Book mybook1("Diddy Party", 3, 6.99);
    mybook1.display();

    Book mybook2(mybook1); 

    myBook.update();
    myBook.display();

    myBook.buy();
    myBook.display();

    return 0;
}
