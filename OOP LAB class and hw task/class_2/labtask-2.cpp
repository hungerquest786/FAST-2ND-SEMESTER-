#include <iostream>
using namespace std;

void inputmatrix(int** matrix, int n, int y) {
    matrix = new int*[n];  
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[y];
    }

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < y; j++) {
            cin >> matrix[i][j];
        }
    }
}

void matrix_addition(int** matrix, int a, int b) {
    int** matrix2 = new int*[a];
    for (int i = 0; i < a; i++) {
        matrix2[i] = new int[b];
    }

    int x, r;
    do {
        cout << "Enter parameters for second matrix: ";
        cin >> x >> r;
    } while (x != a || r != b);

    inputmatrix(matrix2, x, r);

    cout << "Result of Addition:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < r; j++) {
            matrix2[i][j] += matrix[i][j];
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < x; i++) {
        delete[] matrix2[i];
    }
    delete[] matrix2;
}

void matrix_subtraction(int** matrix, int a, int b) {
    int** matrix2 = new int*[a];
    for (int i = 0; i < a; i++) {
        matrix2[i] = new int[b];
    }

    int x, r;
    do {
        cout << "Enter parameters for second matrix: ";
        cin >> x >> r;
    } while (x != a || r != b);

    inputmatrix(matrix2, x, r);

    cout << "Result of Subtraction:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < r; j++) {
            matrix2[i][j] -= matrix[i][j];
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < x; i++) {
        delete[] matrix2[i];
    }
    delete[] matrix2;
}

void multiplyMatrices(int** A, int a, int b) {
    int x, r;
    do {
        cout << "Enter parameters for second matrix: ";
        cin >> x >> r;
    } while (b != x);

    int** B ;
    inputmatrix(B, x, r);

    int** result = new int*[a];
    for (int i = 0; i < a; i++) {
        result[i] = new int[r]();
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < b; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Result of Multiplication:\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < r; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < x; i++) {
        delete[] B[i];
    }
    delete[] B;

    for (int i = 0; i < a; i++) {
        delete[] result[i];
    }
    delete[] result;
}

int main() {
    int** matrix;
    int n, y;

    cout << "Enter parameters for matrix: ";
    cin >> n >> y;

    matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[y];
    }

    inputmatrix(matrix, n, y);

    int choice;
    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Matrix Addition\n";
        cout << "2. Matrix Subtraction\n";
        cout << "3. Matrix Multiplication\n";
        cout << "4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                matrix_addition(matrix, n, y);
                break;
            case 2:
                matrix_subtraction(matrix, n, y);
                break;
            case 3:
                multiplyMatrices(matrix, n, y);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 4);

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
