#ifndef BOOK
#define BOOK
#include <iostream>
#include <string>
using namespace std;
class book {
    protected:
    string title;
    string author ;
    int isbn;
    public:
    book (string a, string b , int c): title (a), author (b), isbn (c){};
    string gettitle(){
        return title;
    };
    string getauthor (){
        return author;
    };
    int getisbn (){
        return isbn;
    };
};

#endif