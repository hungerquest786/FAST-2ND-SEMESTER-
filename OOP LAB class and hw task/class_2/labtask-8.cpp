#include <iostream>
using namespace std;

typedef struct product
{
    string name;
    int productid;
    int quantity;
    double price;
} Product;

void enter(int n, Product *A)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter name of product " << i + 1 << ": ";
        cin >> A[i].name;
        cout << "Enter product ID of product " << i + 1 << ": ";
        cin >> A[i].productid;
        cout << "Enter quantity of product " << i + 1 << ": ";
        cin >> A[i].quantity;
        cout << "Enter price of product " << i + 1 << ": ";
        cin >> A[i].price;
    }
}

void add(int &n, Product *A)
{
    n += 1;
    Product *temp = new Product[n]; 
    for (int i = 0; i < n - 1; i++)
    {
        temp[i] = A[i];
    }

    cout << "Enter name of new product: ";
    cin >> temp[n - 1].name;
    cout << "Enter product ID of new product: ";
    cin >> temp[n - 1].productid;
    cout << "Enter quantity of new product: ";
    cin >> temp[n - 1].quantity;
    cout << "Enter price of new product: ";
    cin >> temp[n - 1].price;

    delete[] A;
    A = temp;
}

void remove(int &n, Product *A)
{
    int r;
    cout << "Enter the product ID you want to remove: ";
    cin >> r;
    int index = -1;

    for (size_t i = 0; i < n; i++)
    {
        if (A[i].productid == r)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (size_t i = index; i < n - 1; i++)
        {
            A[i] = A[i + 1];
        }
        n -= 1;
        cout << "Product removed successfully." << endl;
    }
    else
    {
        cout << "Product ID not found!" << endl;
    }

    A = (Product*)realloc(A,n*sizeof(Product));
}

void search(int n, Product *A)
{
    int r;
    cout << "Enter the product ID you want to search: ";
    cin >> r;

    bool found = false;
    for (size_t i = 0; i < n; i++)
    {
        if (A[i].productid == r)
        {
            cout << "Product found!" << endl;
            cout << "Name: " << A[i].name << endl;
            cout << "Product ID: " << A[i].productid << endl;
            cout << "Quantity: " << A[i].quantity << endl;
            cout << "Price: " << A[i].price << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Product not found!" << endl;
    }
}

float total(int n , Product*A){
    int total = 0;
    for (size_t i = 0; i < n; i++)
    {
        total += A[i].price*A[i].quantity;
    }

    return total;
}

void display(int n, Product *A)
{
    cout << "\nDisplaying all products:\n";
    for (size_t i = 0; i < n; i++)
    {
        cout << "Product " << i + 1 << ":" << endl;
        cout << "Name: " << A[i].name << endl;
        cout << "Product ID: " << A[i].productid << endl;
        cout << "Quantity: " << A[i].quantity << endl;
        cout << "Price: " << A[i].price << endl;
    }

    cout<<"total value of the inventory is :"<<total(n,A) <<endl;
}

int main()
{
    Product *A;
    int n;
    int choice;

    cout << "Enter number of products: ";
    cin >> n;

    A = new Product[n];

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Enter Products Data\n";
        cout << "2. Add a New Product\n";
        cout << "3. Remove a Product\n";
        cout << "4. Search for a Product\n";
        cout << "5. Display All Products\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enter(n, A);
            break;
        case 2:
            add(n, A);
            break;
        case 3:
            remove(n, A);
            break;
        case 4:
            search(n, A);
            break;
        case 5:
            display(n, A);
            break;
        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice, please try again!" << endl;
        }
    } while (choice != 6);

    delete[] A;
    return 0;
}
