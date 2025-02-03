#include <iostream>
using namespace std;

typedef struct book
{
    string title;
    char isavalible;
    int bookid;
    string author;
} Book;

void enter(int n, Book *A)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter title of book " << i + 1 << ": ";
        cin >> A[i].title;
        cout << "Enter author of book " << i + 1 << ": ";
        cin >> A[i].author;
        cout << "Enter book ID of book " << i + 1 << ": ";
        cin >> A[i].bookid;
        cout << "Enter availability (y/n) of book " << i + 1 << ": ";
        cin >> A[i].isavalible;
    }
}

void add(int &n, Book *A)
{
    n += 1;
    Book *temp = new Book[n];
    for (int i = 0; i < n - 1; i++)
    {
        temp[i] = A[i];
    }

    cout << "Enter title of new book: ";
    cin >> temp[n - 1].title;
    cout << "Enter author of new book: ";
    cin >> temp[n - 1].author;
    cout << "Enter book ID of new book: ";
    cin >> temp[n - 1].bookid;
    cout << "Enter availability (y/n) of new book: ";
    cin >> temp[n - 1].isavalible;

    delete[] A;
    A = temp;
}

void remove(int &n, Book *A)
{
    int r;
    cout << "Enter the book ID you want to remove: ";
    cin >> r;
    int index = -1;

    for (size_t i = 0; i < n; i++)
    {
        if (A[i].bookid == r)
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
        cout << "Book removed successfully." << endl;
    }
    else
    {
        cout << "Book ID not found!" << endl;
    }
}

void search(int n, Book *A)
{
    int r;
    cout << "Enter the book ID you want to search: ";
    cin >> r;

    bool found = false;
    for (size_t i = 0; i < n; i++)
    {
        if (A[i].bookid == r)
        {
            cout << "Book found!" << endl;
            cout << "Title: " << A[i].title << endl;
            cout << "Author: " << A[i].author << endl;
            cout << "Book ID: " << A[i].bookid << endl;
            cout << "Availability: " << (A[i].isavalible == 'y' ? "Available" : "Not Available") << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Book not found!" << endl;
    }
}

void display(int n, Book *A)
{
    cout << "\nDisplaying all books:\n";
    for (size_t i = 0; i < n; i++)
    {
        cout << "Book " << i + 1 << ":" << endl;
        cout << "Title: " << A[i].title << endl;
        cout << "Author: " << A[i].author << endl;
        cout << "Book ID: " << A[i].bookid << endl;
        cout << "Availability: " << (A[i].isavalible == 'y' ? "Available" : "Not Available") << endl;
    }
}

int main()
{
    Book *A;
    int n;
    int choice;

    cout << "Enter number of books: ";
    cin >> n;

    A = new Book[n];

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Enter Books Data\n";
        cout << "2. Add a New Book\n";
        cout << "3. Remove a Book\n";
        cout << "4. Search for a Book\n";
        cout << "5. Display All Books\n";
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
