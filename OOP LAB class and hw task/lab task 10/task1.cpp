#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;



int main (){
    ifstream in("vechicles.txt");//already opened 
  
    if (!in){
        return 1;
    }
    string str ;
    while(getline(in, str)){
        if (str.empty() || str[0] == '#') {
            continue; //skips empty line and comment 
        }
        cout << str << endl;
    }

    in.close();//optional 
    return 0;
}