//
//  strassens-algorithm.cpp
//
//  Implementation of Strassen's Algorithm
//

#include "strassens-algorithm.hpp"

void strassen_pad(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int r3, int c3, int cross_over, int n) {
    if (n <= cross_over) {
        matrix_mult_reg(A, B, C, r1, c1, r2, c2, r3, c3, n);
    }
    else {
        int new_n = n / 2;
        vector<int> vector_dim(new_n);
        
        vector< vector<int> > M1(new_n, vector_dim), M2(new_n, vector_dim), M3(new_n, vector_dim), M4(new_n, vector_dim), M5(new_n, vector_dim), M6(new_n, vector_dim), M7(new_n, vector_dim), l_term(new_n, vector_dim), r_term(new_n, vector_dim);
        
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
        matrix_subtract(B, B, r_term, B12_r, B12_c, B22_r, B22_c, 0, 0, new_n);
        strassen_pad(A, r_term, M1, A11_r, A11_c, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M2 = (A11 + A12) * B22
        matrix_add(A, A, l_term, A11_r, A11_c, A12_r, A12_c, 0, 0, new_n);
        strassen_pad(l_term, B, M2, 0, 0, B22_r, B22_c, 0, 0, cross_over, new_n);
        
        // compute M3 = (A21 + A22) * B11
        matrix_add(A, A, l_term, A21_r, A21_c, A22_r, A22_c, 0, 0, new_n);
        strassen_pad(l_term, B, M3, 0, 0, B11_r, B11_c, 0, 0, cross_over, new_n);
        
        // compute M4 = A22 * (B21 - B11)
        matrix_subtract(B, B, r_term, B21_r, B21_c, B11_r, B11_c, 0, 0, new_n);
        strassen_pad(A, r_term, M4, A22_r, A22_c, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M5 = (A11 + A22) * (B11 + B22)
        matrix_add(A, A, l_term, A11_r, A11_c, A22_r, A22_c, 0, 0, new_n);
        matrix_add(B, B, r_term, B11_r, B11_c, B22_r, B22_c, 0, 0, new_n);
        strassen_pad(l_term, r_term, M5, 0, 0, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M6 = (A12 - A22) * (B21 + B22)
        matrix_subtract(A, A, l_term, A12_r, A12_c, A22_r, A22_c, 0, 0, new_n);
        matrix_add(B, B, r_term, B21_r, B21_c, B22_r, B22_c, 0, 0, new_n);
        strassen_pad(l_term, r_term, M6, 0, 0, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M7 = (A11 - A21) * (B11 + B12)
        matrix_subtract(A, A, l_term, A11_r, A11_c, A21_r, A21_c, 0, 0, new_n);
        matrix_add(B, B, r_term, B11_r, B11_c, B12_r, B12_c, 0, 0, new_n);
        strassen_pad(l_term, r_term, M7, 0, 0, 0, 0, 0, 0, cross_over, new_n);
        
        
        // start and end indexes for matrix C
        int C11_r = r3;
        int C11_c = c3;
        
        int C12_r = r3;
        int C12_c = c3 + new_n;
        
        int C21_r = r3 + new_n;
        int C21_c = c3;
        
        int C22_r = r3 + new_n;
        int C22_c = c3 + new_n;
        
        // compute C11 = M5 + M4 - M2 + M6
        matrix_add(M5, M4, l_term, 0, 0, 0, 0, 0, 0, new_n);
        matrix_subtract(l_term, M2, r_term, 0, 0, 0, 0, 0, 0, new_n);
        matrix_add(r_term, M6, C, 0, 0, 0, 0, C11_r, C11_c, new_n);
        
        // compute C12 = M1 + M2
        matrix_add(M1, M2, C, 0, 0, 0, 0, C12_r, C12_c, new_n);
        
        // compute C21 = M3 + M4
        matrix_add(M3, M4, C, 0, 0, 0, 0, C21_r, C21_c, new_n);
        
        // compute C22 = M5 + M1 - M3 - M7
        matrix_add(M5, M1, l_term, 0, 0, 0, 0, 0, 0, new_n);
        matrix_subtract(l_term, M3, r_term, 0, 0, 0, 0, 0, 0, new_n);
        matrix_subtract(r_term, M7, C, 0, 0, 0, 0, C22_r, C22_c, new_n);
    }
}

void strassen_odd_pad(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int r3, int c3, int cross_over, int n) {
    if (n <= cross_over) {
        matrix_mult_reg(A, B, C, r1, c1, r2, c2, r3, c3, n);
    }
    else {
        int new_n = n;
        if (n % 2 != 0){
            for(int i = 0; i < n; i++){
                A.at(i).resize(n+1);
                B.at(i).resize(n+1);
                C.at(i).resize(n+1);
            }
            A.resize(n+1);
            A.at(n).resize(n+1);
            B.resize(n+1);
            B.at(n).resize(n+1);
            C.resize(n+1);
            C.at(n).resize(n+1);
            new_n = (n+1)/2;
        }
        else {
            new_n = n/2;
        }
        vector<int> vector_dim(new_n);
        
        vector< vector<int> > M1(new_n, vector_dim), M2(new_n, vector_dim), M3(new_n, vector_dim), M4(new_n, vector_dim), M5(new_n, vector_dim), M6(new_n, vector_dim), M7(new_n, vector_dim), l_term(new_n, vector_dim), r_term(new_n, vector_dim);
        
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
        matrix_subtract(B, B, r_term, B12_r, B12_c, B22_r, B22_c, 0, 0, new_n);
        strassen_odd_pad(A, r_term, M1, A11_r, A11_c, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M2 = (A11 + A12) * B22
        matrix_add(A, A, l_term, A11_r, A11_c, A12_r, A12_c, 0, 0, new_n);
        strassen_odd_pad(l_term, B, M2, 0, 0, B22_r, B22_c, 0, 0, cross_over, new_n);
        
        // compute M3 = (A21 + A22) * B11
        matrix_add(A, A, l_term, A21_r, A21_c, A22_r, A22_c, 0, 0, new_n);
        strassen_odd_pad(l_term, B, M3, 0, 0, B11_r, B11_c, 0, 0, cross_over, new_n);
        
        // compute M4 = A22 * (B21 - B11)
        matrix_subtract(B, B, r_term, B21_r, B21_c, B11_r, B11_c, 0, 0, new_n);
        strassen_odd_pad(A, r_term, M4, A22_r, A22_c, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M5 = (A11 + A22) * (B11 + B22)
        matrix_add(A, A, l_term, A11_r, A11_c, A22_r, A22_c, 0, 0, new_n);
        matrix_add(B, B, r_term, B11_r, B11_c, B22_r, B22_c, 0, 0, new_n);
        strassen_odd_pad(l_term, r_term, M5, 0, 0, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M6 = (A12 - A22) * (B21 + B22)
        matrix_subtract(A, A, l_term, A12_r, A12_c, A22_r, A22_c, 0, 0, new_n);
        matrix_add(B, B, r_term, B21_r, B21_c, B22_r, B22_c, 0, 0, new_n);
        strassen_odd_pad(l_term, r_term, M6, 0, 0, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M7 = (A11 - A21) * (B11 + B12)
        matrix_subtract(A, A, l_term, A11_r, A11_c, A21_r, A21_c, 0, 0, new_n);
        matrix_add(B, B, r_term, B11_r, B11_c, B12_r, B12_c, 0, 0, new_n);
        strassen_odd_pad(l_term, r_term, M7, 0, 0, 0, 0, 0, 0, cross_over, new_n);
        
        
        // start and end indexes for matrix C
        int C11_r = r3;
        int C11_c = c3;
        
        int C12_r = r3;
        int C12_c = c3 + new_n;
        
        int C21_r = r3 + new_n;
        int C21_c = c3;
        
        int C22_r = r3 + new_n;
        int C22_c = c3 + new_n;
        
        // compute C11 = M5 + M4 - M2 + M6
        matrix_add(M5, M4, l_term, 0, 0, 0, 0, 0, 0, new_n);
        matrix_subtract(l_term, M2, r_term, 0, 0, 0, 0, 0, 0, new_n);
        matrix_add(r_term, M6, C, 0, 0, 0, 0, C11_r, C11_c, new_n);
        
        // compute C12 = M1 + M2
        matrix_add(M1, M2, C, 0, 0, 0, 0, C12_r, C12_c, new_n);
        
        // compute C21 = M3 + M4
        matrix_add(M3, M4, C, 0, 0, 0, 0, C21_r, C21_c, new_n);
        
        // compute C22 = M5 + M1 - M3 - M7
        matrix_add(M5, M1, l_term, 0, 0, 0, 0, 0, 0, new_n);
        matrix_subtract(l_term, M3, r_term, 0, 0, 0, 0, 0, 0, new_n);
        matrix_subtract(r_term, M7, C, 0, 0, 0, 0, C22_r, C22_c, new_n);
    }
}

void strassen_odd_padding(ifstream &file, int cross_over, int n){
    // initialize matrix
    vector<int> vector_dim(n);
    
    // initialize vector of vectors (matrix representation)
    vector< vector<int> > A(n, vector_dim), B(n, vector_dim), C(n, vector_dim);
    
    read_file(file, A, n);
    read_file(file, B, n);
    file.close();
    
    strassen_odd_pad(A, B, C, 0, 0, 0, 0, 0, 0, cross_over, n);
    matrix_print(C, n);
    cout << endl;
}


void strassen(ifstream &file, int cross_over, int n, bool opt) {
    if(opt == 1){
        int padding = find_opt_matrix_padding(cross_over, n);
        
        // initialize new matrix dimensions with determined padding
        int new_matrix_dim = n + padding;
        vector<int> vector_dim(new_matrix_dim);
        
        // initialize vector of vectors (matrix representation)
        vector< vector<int> > A(new_matrix_dim, vector_dim), B(new_matrix_dim, vector_dim), C(new_matrix_dim, vector_dim);
        
        read_file(file, A, n);
        read_file(file, B, n);
        file.close();
        
        strassen_pad(A, B, C, 0, 0, 0, 0, 0, 0, cross_over, new_matrix_dim);
        
        //    matrix_mult_reg(A, B, C, 0, 0, 0, 0, 0, 0, n);
        
        // print matrix
        //    matrix_print(C, n);
        
        // extract diagonal of the matrix
        cout << "Optimal Padding" << endl;
        matrix_print_diag(C, n);
        cout << endl;
    }
    else if(opt == 0){
        int padding = find_pow2_matrix_padding(cross_over, n);
        
        // initialize new matrix dimensions with determined padding
        int new_matrix_dim = n + padding;
        vector<int> vector_dim(new_matrix_dim);
        
        // initialize vector of vectors (matrix representation)
        vector< vector<int> > A(new_matrix_dim, vector_dim), B(new_matrix_dim, vector_dim), C(new_matrix_dim, vector_dim);
        
        read_file(file, A, n);
        read_file(file, B, n);
        file.close();
        
        strassen_pad(A, B, C, 0, 0, 0, 0, 0, 0, cross_over, new_matrix_dim);
        
        //    matrix_mult_reg(A, B, C, 0, 0, 0, 0, 0, 0, n);
        
        // print matrix
        //    matrix_print(C, n);
        
        // extract diagonal of the matrix
        cout << "Power of 2 Padding" << endl;
        matrix_print(C, n);
        cout << endl;
    }
    else{
        cout << "Improper Usage" << endl;
    }
    
}

void read_file(ifstream &infile, vector< vector<int> > &A, int n) {
    int val;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            infile >> val;
            A[i][j] = val;
        }
    }
}


int find_pow2_matrix_padding(int cross_over, int n) {
    
    int k = 0;
    int r_term;
    
    // padding is not necessary, thus return 0
    if (n <= cross_over) {
        return 0;
    }
    
    while (1) {
        r_term = cross_over * pow(2, k);
        if (n <= r_term) {
            return r_term - n;
        }
        k++;
    }
}

bool helper_done(int cross_over, int n){
    while (n > cross_over){
        if (n%2 != 0){
            return false;
        }
        else {
            n = n/2;
            if(n <= cross_over){
                return true;
            }
        }
    }
    return false;
}

int find_opt_matrix_padding(int cross_over, int n){
    int pad = 0;
    while(1){
        if (helper_done(cross_over, n + pad)){
            break;
        }
        else {
            pad++;
        }
    }
    return pad;
}
