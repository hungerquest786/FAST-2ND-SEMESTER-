#include<iostream>
using namespace std;

class currency {
    protected:
    float amount ;
    int currencycode;
    char currecnysymbol;
    float exchangerate;
    public : 
    void enter (){
        cin >> amount >> currecnysymbol >> currencycode >> exchangerate;
    }
    virtual void converttobase(){
        cout <<"sets exchange rate"<<endl;
    };
    void covertto (char targetcurrency){
        if (targetcurrency == 'd')
        {
            amount = exchangerate * 2.25;
        }else if (targetcurrency == 'e'){
            amount = exchangerate * 1.25;
        }else if (targetcurrency == 'r'){
            amount = exchangerate * 0.25;
        }
        
    }
    virtual void displaycurrency (){
        cout << "displays amount"<< amount<<endl;
    }

};

class dollar : public currency{
    void coverttobase(){
      exchangerate = 3;  
    }
    void displaycurrency(){
        cout << amount<<endl;
    }

};
class euro : public currency{
    void coverttobase(){
        exchangerate = 2;  
      }
    void displaycurrency(){
        cout <<  amount<<endl;
    }

};
class rupee : public currency{
    void coverttobase(){
        exchangerate = 1;  
      }
    void displaycurrency(){
        cout <<  amount<<endl;
    }

};

int main (){

}