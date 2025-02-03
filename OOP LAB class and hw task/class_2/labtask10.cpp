#include <iostream>
using namespace std;

void enterdata(int** array, int row, int column) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < column; j++) {
            cin >> *(*(array + i) + j);
        }
    }
}

void transpose(int** array, int row, int column) {
    int** temp = new int*[column];
    for (size_t i = 0; i < column; i++) {
        *(temp + i) = new int[row];
    }

    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < column; j++) {
            *(*(temp + j) + i) = *(*(array + i) + j);
        }
    }

    for (size_t i = 0; i < row; i++) {
        delete[] *(array + i);
    }
    delete[] array;

    array = new int*[column];
    for (size_t i = 0; i < column; i++) {
        *(array + i) = new int[row];
        for (size_t j = 0; j < row; j++) {
            *(*(array + i) + j) = *(*(temp + i) + j);
        }
    }

    for (size_t i = 0; i < column; i++) {
        for (size_t j = 0; j < row; j++) {
            cout << *(*(array + i) + j) << " ";
        }
        cout << endl;
    }

    for (size_t i = 0; i < column; i++) {
        delete[] *(temp + i);
    }
    delete[] temp;
}

int main() {
    int row, column;
    cin >> row >> column;

    int** array = new int*[row];
    for (size_t i = 0; i < row; i++) {
        *(array + i) = new int[column];
    }

    enterdata(array, row, column);
    transpose(array, row, column);

    for (size_t i = 0; i < column; i++) {
        delete[] *(array + i);
    }
    delete[] array;
    
    return 0;
}
