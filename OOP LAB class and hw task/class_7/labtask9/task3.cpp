#include <iostream>
#include "book.h"
using namespace std;


int main (){
book b("diddy party", "diddy ", 2020);
cout << b.gettitle() <<endl;
cout << b.getauthor() <<endl;
cout << b.getisbn() <<endl;
};
// g++ task3.cpp -o task3.exe