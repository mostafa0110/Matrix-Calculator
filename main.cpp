#include <iostream>
#include <cmath>

using namespace std;

void Multi(long double A[10][10], long double B[10][10], int Ar, int Ac, int Br, int Bc) {
    long double product = 0;
    for (int i = 0; i < Ar; i++)
    {
        for (int j = 0; j < Bc; j++)
        {   product = 0;
            for (int p = 0; p < Ac; p++)
             { product = product + (A[i][p] * B[p][j]); }
            if (round(product) == -0) {cout << 0 << " ";}
            else {cout << round(product) << " ";}
        }
        cout << endl;
    }
}

void Addition(long double A[10][10], long double B[10][10], int Ar, int Bc) {
    for (int i = 0; i < Ar; i++)
    {
        for (int j = 0; j < Bc; j++)
        {
            cout <<round(A[i][j] + B[i][j]) << " ";
        }
        cout << endl;
    }

}

void Subtraction(long double A[10][10], long double B[10][10], int Ar, int Bc) {
    for (int i = 0; i < Ar; i++) {
        for (int j = 0; j < Bc; j++) {
            cout << round(A[i][j] - B[i][j]) << " ";
        }
        cout << endl;
    }

}

long double Minor(long double A[10][10], long double X[10][10], int i, int j, int n) {
    int d = 0, r = 0;
    for (int p = 0; p < n; p++) {
        if (p != i) {
            for (int k = 0; k < n; k++) {
                if (k != j) {
                    X[r][d] = A[p][k];
                    d++;
                }

                if (d == n - 1) {
                    d = 0;
                    r++;
                }
            }
        }
    }

}

long long Determinant(long double A[10][10], int n) {
    long long det = 0;
    int sign = 1;
    long double X[10][10];
    if (n == 1) { return (A[0][0]); }
    if (n == 2) { return ((A[0][0] * A[1][1]) - (A[1][0] * A[0][1])); }

    for (int j = 0; j < n; j++) {
        Minor(A, X, 0, j, n);

        det = det + (A[0][j] * sign * Determinant(X, n - 1));
        sign = -sign;
    }
    return det;
}

void Division(long double A[10][10], long double B[10][10], int n, int Ar, int Ac) {
    long double M[10][10], Z = 0;
    long double X[10][10];
    Z = Determinant(B, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Minor(B, X, i, j, n);
            M[j][i] = (pow(-1, i + j) * Determinant(X, n - 1) / Z);

        }
    }
    Multi(A, M, Ar, Ac, n, n);
}

int main() {
    long double A[10][10], B[10][10];
    int Ar, Ac, Br, Bc;
    cout << "Please enter dimensions of Matrix A:" << endl;
    cin >> Ar >> Ac;
    cout << "Please enter dimensions of Matrix B:" << endl;
    cin >> Br >> Bc;
    cout << "Please enter values of Matrix A:" << endl;
    for (int i = 0; i < Ar; i++)
        for (int j = 0; j < Ac; j++) { cin >> A[i][j]; }
    cout << "Please enter values of Matrix B:" << endl;
    for (int i = 0; i < Br; i++)
        for (int j = 0; j < Bc; j++) { cin >> B[i][j]; }

    do {
        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"
             << endl;
        int ch;
        cin >> ch;
        switch (ch) {
            case 1:
                if (Ar != Br || Ac != Bc) {
                    cout << "The operation you chose is invalid for the given matrices." << endl;
                }
                else
                    Addition(A, B, Ar, Bc);
                break;
            case 2:
                if (Ar != Br || Ac != Bc) {
                    cout << "The operation you chose is invalid for the given matrices." << endl;
                }
                else
                    Subtraction(A, B, Ar, Bc);
                break;
            case 3:
                if (Ac != Br) { cout << "The operation you chose is invalid for the given matrices." << endl; }
                else
                    Multi(A, B, Ar, Ac, Br, Bc);
                break;
            case 4:
                if (Determinant(B, Br) == 0 || Ac != Br || Bc != Br) {
                    cout << "The operation you chose is invalid for the given matrices." << endl;
                }
                else
                    Division(A, B, Br, Ar, Ac);
                break;
            case 5:
                if (Ar != Ac) { cout << "The operation you chose is invalid for the given matrices." << endl; }
                else { cout << Determinant(A, Ar) << endl; }
                break;
            case 6:
                if (Br != Bc) { cout << "The operation you chose is invalid for the given matrices." << endl; }
                else { cout << Determinant(B, Br) << endl; }
                break;
            case 7:
                cout << "Thank you!" << endl;
                return (0);
                break;
        }
    } while (1);
    return 0;
}
