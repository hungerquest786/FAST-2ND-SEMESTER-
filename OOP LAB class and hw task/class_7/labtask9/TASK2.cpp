#include<iostream>
using namespace std;

class smartdevice{
    protected:
    bool status;
    public:
    virtual void turn_on () =0;
    virtual void turn_of()=0;
    virtual void getstatus () = 0;
};

class lightbulb {
    protected:
    bool isOn;
    int brigthness;
    public:
    lightbulb (int b): brigthness(b), isOn(false){};
    void turn_on(){
        isOn = true;
    };

    void turn_of (){
        isOn = false;
    };

    void getstatus (){
        // cout << (isOn ? "is on : " + temprature : "is off")  << endl;
        if (isOn){
            cout << "is on "<< brigthness << endl;
        }else{
            cout<< " is of";
        }
    };
};

class thermostat {
    protected:
    bool isOn;
    int temprature;
    public:
    thermostat (int b): temprature(b) ,isOn(false){};
    void turn_on(){
        isOn = true;
    };

    void turn_of (){
        isOn = false;
    };

    void getstatus (){
        // cout << (isOn ? "is on : " + temprature : "is off")  << endl;
                if (isOn){
            cout << "is on "<< temprature << endl;
        }else{
            cout<< " is of";
        }
    };
};

int main (){
    lightbulb b(20);
    b.turn_on();
    b.getstatus();

    thermostat c(30);
    c.turn_on();
    c.getstatus();

    


}