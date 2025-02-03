#include <iostream>
using namespace std;

void average(int arr[4][7], int arr1[4][4], int count) {
    int total;

    for (int i = 0; i < 4; i++) {
        total = 0; 
        for (int j = 0; j < 7; j++) {
            total += arr[i][j];
        }
        total = total / 7; 
        arr1[count][i] = total;
        cout << "Avg of that week " << count + 1 << " is " << total << endl;
    }
}

void critical_polution_day(int* crit, int arr[4][7]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            if (arr[i][j] >= 150) {
                cout << "The city " << i + 1 << " had a critical pollution day on day " << j + 1 << endl;
            }
        }
    }
}

void lowest_aqi(int city[4][7]) {
    int worst = city[0][0];
    int r = 1; 

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            if (worst > city[i][j]) { 
                worst = city[i][j];
                r = i + 1;
            }
        }
    }

    cout << "City with worst air quality is " << r << endl;
}

void highest_aqi(int city[4][7]) {
    int best = city[0][0];
    int r = 1; 

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            if (best < city[i][j]) {
                best = city[i][j];
                r = i + 1;
            }
        }
    }

    cout << "City with best air quality is " << r << " whose quality is " << best << endl;
}

void display(int city[4][7]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            cout << "For city " << i + 1 << " AQI is " << city[i][j] << endl;
        }
    }
}

void enter(int city[4][7]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            cout << "Enter AQI for city " << i + 1 << " day " << j + 1 << ": ";
            cin >> city[i][j];
        }
    }
}

void monthly_avg(int avg[4][4]) {
    int total = 0; 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            total += avg[i][j];
        }
    }
    cout << "Monthly avg is " << total / 16 << endl; 
}

void display_pattern(int city [4][7]){
        for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            cout<< "for city"<<i+1<<" and day"<<j+1<<endl;
            if(city[i][j]>= 150){
                int n = city[i][j]/50;
                for (int k = 0 ; k<n ; k++){
                    cout << "*";
                }
                cout<<endl;
            }
        }
    }
}

int main() {
    int city[4][7];
    int avg[4][4] = {0}; 

    cout << "Enter for week 1" << endl;
    enter(city);
    display(city);
    lowest_aqi(city);
    highest_aqi(city);
    critical_polution_day(nullptr, city);
    average(city, avg, 0);
    display_pattern(city);

    cout << "Enter for week 2" << endl;
    enter(city);
    display(city);
    lowest_aqi(city);
    highest_aqi(city);
    critical_polution_day(nullptr, city);
    average(city, avg, 1);
    display_pattern(city);

    cout << "Enter for week 3" << endl; 
    enter(city);
    display(city);
    lowest_aqi(city);
    highest_aqi(city);
    critical_polution_day(nullptr, city);
    average(city, avg, 2);
    display_pattern(city);

    cout << "Enter for week 4" << endl;
    enter(city);
    display(city);
    lowest_aqi(city);
    highest_aqi(city);
    critical_polution_day(nullptr, city);
    average(city, avg, 3);
    display_pattern(city);

    monthly_avg(avg); 

    return 0;
}
