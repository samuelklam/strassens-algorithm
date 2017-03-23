//
//  matrix-functions.cpp
//
//

#include "matrix-functions.hpp"

void matrix_print(vector< vector<int> > &matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << left << matrix[i][j];
        }
        cout << endl;
    }
}

void matrix_add(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int r3, int c3, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i + r3][j + c3] = A[i + r1][j + c1] + B[i + r2][j + c2];
        }
    }
}

void matrix_subtract(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int r3, int c3, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i + r3][j + c3] = A[i + r1][j + c1] - B[i + r2][j + c2];
        }
    }
}

void matrix_mult_reg(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int r3, int c3, int n) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C[i + r3][j + c3] += A[i + r1][k + c1] * B[k + r2][j + c2];
            }
        }
    }
}

void matrix_print_diag(vector< vector<int> > &A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i][i] << endl;
    }
}

void fill_matrix_rand(vector< vector<int> > &A, vector< vector<int> > &B, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 2;
            B[i][j] = rand() % 2;
        }
    }
}
