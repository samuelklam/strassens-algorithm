//
//  strassens-algorithm.cpp
//
//  Created by Samuel K. Lam on 3/20/17.
//  Copyright © 2017 Samuel K. Lam. All rights reserved.
//

#include "strassens-algorithm.hpp"

void matrix_print(vector< vector<int> > &matrix) {
    unsigned long n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << left << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void matrix_add(vector< vector<int> > &M1, vector< vector<int> > &M2, vector< vector<int> > &M3, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M3[i][j] = M1[i][j] + M2[i][j];
        }
    }
}

void matrix_subtract(vector< vector<int> > &M1, vector< vector<int> > &M2, vector< vector<int> > &M3, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M3[i][j] = M1[i][j] - M2[i][j];
        }
    }
}

void matrix_mult_conv(vector< vector<int> > &M1, vector< vector<int> > &M2, vector< vector<int> > &M3, int n) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                M3[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}
