#include <iostream>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pDate, string uID, string pub)
        : title(t), publicationDate(pDate), uniqueID(uID), publisher(pub) {}
    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << endl;
    }
};

class Book : public Media {
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pDate, string uID, string pub, string a, string isbn, int pages)
        : Media(t, pDate, uID, pub), author(a), ISBN(isbn), numberOfPages(pages) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
    string director;
    int duration;
    float rating;
public:
    DVD(string t, string pDate, string uID, string pub, string d, int dur, float r)
        : Media(t, pDate, uID, pub), director(d), duration(dur), rating(r) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " mins\nRating: " << rating << endl;
    }
};

class CD : public Media {
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pDate, string uID, string pub, string a, int tracks, string g)
        : Media(t, pDate, uID, pub), artist(a), numberOfTracks(tracks), genre(g) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }
};

int main() {
    Book book("C++ Programming", "2022", "B001", "Tech Publishers", "John Doe", "123456789", 500);
    DVD dvd("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD cd("Thriller", "1982", "C001", "Epic Records", "Michael Jackson", 9, "Pop");

    cout << "\nBook Details:\n";
    book.displayInfo();
    cout << "\nDVD Details:\n";
    dvd.displayInfo();
    cout << "\nCD Details:\n";
    cd.displayInfo();
    
    return 0;
}
