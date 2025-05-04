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
        istringstream ss (str);
        string type,
         name,
         id,
         year;
        ss >> type >> name >> id >> year;
        int year2 = stoi(year);
        if (stoi(year)){
            cout << year2<<endl;
        }else {
            cout<< "error";
        }
        
    }

    in.close();//optional 
    return 0;
}