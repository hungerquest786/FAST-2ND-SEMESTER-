#include"iostream"
using namespace std;

class vehicle{
    protected:
    string model;
    double rate;

    public:
    vehicle (string r ) : model(r){};
    virtual void getdailyrate(int rate)=0;
    virtual void dsiplaydetail()=0;
};

class car : public vehicle {
public:
car (string r): vehicle(r){};
void getdailyrate (int r){
    rate = r;
};
void dsiplaydetail (){
    cout << rate<< endl;
}
};

class bike : public vehicle {
public:
bike (string r): vehicle(r){};
void getdailyrate (int r){
    rate = r;
};
void dsiplaydetail (){
    cout << rate<< endl;
}
};


int main (){

    car c("volks");
    bike b("yamaha");

    c.getdailyrate(3.0);
    b.getdailyrate(4.0);

    c.dsiplaydetail();
    b.dsiplaydetail();


}