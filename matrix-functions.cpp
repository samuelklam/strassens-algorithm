//
//  matrix-functions.cpp
//
//  Created by Samuel K. Lam on 3/20/17.
//  Copyright © 2017 Samuel K. Lam. All rights reserved.
//

#include "matrix-functions.hpp"

void matrix_print(vector< vector<int> > &matrix) {
    unsigned long n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << left << matrix[i][j];
        }
        cout << endl;
    }
}

void matrix_add(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i + r1][j + c1] + B[i + r2][j + c2];
        }
    }
}

void matrix_subtract(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i + r1][j + c1] - B[i + r2][j + c2];
        }
    }
}

void matrix_mult_reg(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int n) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += A[i + r1][k + c1] * B[k + r2][j + c2];
            }
        }
    }
}
