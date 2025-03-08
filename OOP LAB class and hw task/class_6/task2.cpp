#include<iostream>
using namespace std;

class vehicle {
    private:
    string name ;
    float speed;

    public :
    vehicle(string n, float s){
        name = n;
        speed = s;
    }

    void dispay (){
        cout << "Vehicle Name : " << name << endl;
        cout << "Vehicle Speed : " << speed << " km/h" << endl;
    }
};

class car : public vehicle {
    private:
    int seats;

    public :
    car(string n, float s, int seats) : vehicle(n, s){
        this->seats = seats;
    }

    void displayCarDetails(){
        dispay();
        cout << "Number of Seats : " << seats << endl;
    }
};

class Electtric_car : public vehicle{
    private:
    int battery_life;
    public :
    Electtric_car(string n, float s, int battery_life) : vehicle(n, s){
        this->battery_life = battery_life;
    }
    void displayElectricCarDetails(){
        dispay();
        cout << "Battery Life : " << battery_life << " hours" << endl;
    }
};

int main (){
    car c("honda",180.00,4) ;

    c.displayCarDetails();

    Electtric_car ec("Tesla", 240.00, 24);
    ec.displayElectricCarDetails();

}