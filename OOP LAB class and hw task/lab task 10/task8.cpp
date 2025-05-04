#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
using namespace std;



int main ()
{
    fstream file;
    file.open("config.txt", ios :: in | ios :: out);
    file.seekp(6);
    file <<endl<< "EEEEEE"<<endl;
    file.close();
}