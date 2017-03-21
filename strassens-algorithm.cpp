//
//  strassens-algorithm.cpp
//
//  Created by Samuel K. Lam on 3/20/17.
//  Copyright © 2017 Samuel K. Lam. All rights reserved.
//

#include "strassens-algorithm.hpp"

void strassen_pow2(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int cross_over, int n) {
    if (n <= cross_over) {
        matrix_mult_reg(A, B, C, r1, c1, r2, c2, n);
    }
    else {
        int new_n = n / 2;
        vector<int> vector_dim(new_n);
        
        vector< vector<int> > M1(new_n, vector_dim), M2(new_n, vector_dim), M3(new_n, vector_dim), M4(new_n, vector_dim), M5(new_n, vector_dim), M6(new_n, vector_dim), M7(new_n, vector_dim), C11(new_n, vector_dim), C12(new_n, vector_dim), C21(new_n, vector_dim), C22(new_n, vector_dim), l_term(new_n, vector_dim), r_term(new_n, vector_dim);
        
        // start and end indexes for matrix A
        int A11_r = r1;
        int A11_c = c1;
        
        int A12_r = r1;
        int A12_c = c1 + new_n;
        
        int A21_r = r1 + new_n;
        int A21_c = c1;
        
        int A22_r = r1 + new_n;
        int A22_c = c1 + new_n;
        
        // start and end indexes for matrix B
        int B11_r = r2;
        int B11_c = c2;
        
        int B12_r = r2;
        int B12_c = c2 + new_n;
        
        int B21_r = r2 + new_n;
        int B21_c = c2;
        
        int B22_r = r2 + new_n;
        int B22_c = c2 + new_n;
        
        
        // compute M1 = A11 * (B12 - B22)
        matrix_subtract(B, B, r_term, B12_r, B12_c, B22_r, B22_c, new_n);
        strassen_pow2(A, r_term, M1, A11_r, A11_c, 0, 0, cross_over, new_n);
        
        // compute M2 = (A11 + A12) * B22
        matrix_add(A, A, l_term, A11_r, A11_c, A12_r, A12_c, new_n);
        strassen_pow2(l_term, B, M2, 0, 0, B22_r, B22_c, cross_over, new_n);
        
        // compute M3 = (A21 + A22) * B11
        matrix_add(A, A, l_term, A21_r, A21_c, A22_r, A22_c, new_n);
        strassen_pow2(l_term, B, M3, 0, 0, B11_r, B11_c, cross_over, new_n);
        
        // compute M4 = A22 * (B21 - B11)
        matrix_subtract(B, B, r_term, B21_r, B21_c, B11_r, B11_c, new_n);
        strassen_pow2(A, r_term, M4, A22_r, A22_c, 0, 0, cross_over, new_n);
        
        // compute M5 = (A11 + A22) * (B11 + B22)
        matrix_add(A, A, l_term, A11_r, A11_c, A22_r, A22_c, new_n);
        matrix_add(B, B, r_term, B11_r, B11_c, B22_r, B22_c, new_n);
        strassen_pow2(l_term, r_term, M5, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M6 = (A12 - A22) * (B21 + B22)
        matrix_subtract(A, A, l_term, A12_r, A12_c, A22_r, A22_c, new_n);
        matrix_add(B, B, r_term, B21_r, B21_c, B22_r, B22_c, new_n);
        strassen_pow2(l_term, r_term, M6, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M7 = (A11 - A21) * (B11 + B12)
        matrix_subtract(A, A, l_term, A11_r, A11_c, A21_r, A21_c, new_n);
        matrix_add(B, B, r_term, B11_r, B11_c, B12_r, B12_c, new_n);
        strassen_pow2(l_term, r_term, M7, 0, 0, 0, 0, cross_over, new_n);
        
        
        // compute C11 = M5 + M4 - M2 + M6
        matrix_add(M5, M4, l_term, 0, 0, 0, 0, new_n);
        matrix_subtract(l_term, M2, r_term, 0, 0, 0, 0, new_n);
        matrix_add(r_term, M6, C11, 0, 0, 0, 0, new_n);
        
        // compute C12 = M1 + M2
        matrix_add(M1, M2, C12, 0, 0, 0, 0, new_n);
        
        // compute C21 = M3 + M4
        matrix_add(M3, M4, C21, 0, 0, 0, 0, new_n);
        
        // compute C22 = M5 + M1 - M3 - M7
        matrix_add(M5, M1, l_term, 0, 0, 0, 0, new_n);
        matrix_subtract(l_term, M3, r_term, 0, 0, 0, 0, new_n);
        matrix_subtract(r_term, M7, C22, 0, 0, 0, 0, new_n);
        
        
        // update the final matrix product C
        for (int i = 0; i < new_n; i++) {
            for (int j = 0; j < new_n ; j++) {
                C[i][j] = C11[i][j];
                C[i][j + new_n] = C12[i][j];
                C[i + new_n][j] = C21[i][j];
                C[i + new_n][j + new_n] = C22[i][j];
            }
        }
    }
}
