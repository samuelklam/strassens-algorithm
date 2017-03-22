//
//  strassens-algorithm.cpp
//
//  Implementation of Strassen's Algorithm
//

#include "strassens-algorithm.hpp"

void strassen_pow2(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int r3, int c3, int cross_over, int n) {
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
        strassen_pow2(A, r_term, M1, A11_r, A11_c, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M2 = (A11 + A12) * B22
        matrix_add(A, A, l_term, A11_r, A11_c, A12_r, A12_c, 0, 0, new_n);
        strassen_pow2(l_term, B, M2, 0, 0, B22_r, B22_c, 0, 0, cross_over, new_n);
        
        // compute M3 = (A21 + A22) * B11
        matrix_add(A, A, l_term, A21_r, A21_c, A22_r, A22_c, 0, 0, new_n);
        strassen_pow2(l_term, B, M3, 0, 0, B11_r, B11_c, 0, 0, cross_over, new_n);
        
        // compute M4 = A22 * (B21 - B11)
        matrix_subtract(B, B, r_term, B21_r, B21_c, B11_r, B11_c, 0, 0, new_n);
        strassen_pow2(A, r_term, M4, A22_r, A22_c, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M5 = (A11 + A22) * (B11 + B22)
        matrix_add(A, A, l_term, A11_r, A11_c, A22_r, A22_c, 0, 0, new_n);
        matrix_add(B, B, r_term, B11_r, B11_c, B22_r, B22_c, 0, 0, new_n);
        strassen_pow2(l_term, r_term, M5, 0, 0, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M6 = (A12 - A22) * (B21 + B22)
        matrix_subtract(A, A, l_term, A12_r, A12_c, A22_r, A22_c, 0, 0, new_n);
        matrix_add(B, B, r_term, B21_r, B21_c, B22_r, B22_c, 0, 0, new_n);
        strassen_pow2(l_term, r_term, M6, 0, 0, 0, 0, 0, 0, cross_over, new_n);
        
        // compute M7 = (A11 - A21) * (B11 + B12)
        matrix_subtract(A, A, l_term, A11_r, A11_c, A21_r, A21_c, 0, 0, new_n);
        matrix_add(B, B, r_term, B11_r, B11_c, B12_r, B12_c, 0, 0, new_n);
        strassen_pow2(l_term, r_term, M7, 0, 0, 0, 0, 0, 0, cross_over, new_n);
        
        
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

int find_optimal_matrix_padding(int cross_over, int n) {
    
    int k = 0;
    int r_term;
    
    // padding is not necessary
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

void fill_matrix_rand(vector< vector<int> > &A, vector< vector<int> > &B, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 2;
            B[i][j] = rand() % 2;
        }
    }
}

void test_cross_over_strassens(ofstream &file, int n, int num_trials, bool pow_2) {
    
    double min_time_cross_over = INT_MAX;
    int min_cross_over = 0;
    int end_cross = n;
    int optimal_padding = 0;
    int padding = 0;
    
    clock_t start, end;
    srand((unsigned)time(NULL));
    
    vector<int> cross_over_vec;
    if (pow_2) {
        // test cross_overs by interval powers of 2
        int i = 64;
        while (i <= 64) {
            cross_over_vec.push_back(i);
            i *= 2;
        }
    }
    else {
        // start testing cross-over val from 15 to determined end_cross
        for (int i = 15; i <= end_cross; i++) {
            cross_over_vec.push_back(i);
        }
    }
    
    for (int i = 0; i < cross_over_vec.size(); i++) {
        
        int cross_over = cross_over_vec[i];
        
        padding = find_optimal_matrix_padding(cross_over, n);
        
        // initialize new matrix dimensions with determined padding
        int new_matrix_dim = n + padding;
        vector<int> vector_dim(new_matrix_dim);
        
        // initialize vector of vectors (matrix representation)
        vector< vector<int> > A(new_matrix_dim, vector_dim), B(new_matrix_dim, vector_dim), C(new_matrix_dim, vector_dim);
        
        fill_matrix_rand(A, B, n);
        
        start = clock();
        
        // run for # of trials to find average strassen computation time
        for (int j = 0; j < num_trials; j++) {
            strassen_pow2(A, B, C, 0, 0, 0, 0, 0, 0, cross_over, new_matrix_dim);
        }
        
        end = clock() - start;
        
        if (end < min_time_cross_over) {
            min_time_cross_over = end;
            min_cross_over = cross_over;
            optimal_padding = padding;
        }
    }
    
    cout << "matrix dimension: " << n << ", time: " << min_time_cross_over / num_trials << ", cross-over: " << min_cross_over << ", padding: " << optimal_padding << ", num_trials: " << num_trials << endl;
    file << "matrix dimension: " << n << ", time: " << min_time_cross_over / num_trials << ", cross-over: " << min_cross_over << ", padding: " << optimal_padding << ", num_trials: " << num_trials << endl;
}

void test_cross_over_all_matrices(int start_dim, int end_dim, int num_trials, bool pow_2) {
    ofstream myfile;
    myfile.open("output.txt");

    // tests matrices up to dim 64
    for (int i = start_dim; i <= end_dim; i++) {
        test_cross_over_strassens(myfile, i, num_trials, pow_2);
    }
    myfile.close();
}

void pad_matrix(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int cross_over, int n){
    // determines the next dimension where Strassen can run
    if(cross_over < n){
        while(n > cross_over){
            cross_over = cross_over*2;
        }
        // if next largest dimension is same as n, nothing to be done
        if(cross_over != n){
            // determines pad amount
            int pad_amount = cross_over - n;
            
             // add pad_amount of 0's to each row
            for(int i = 0; i < n; i++){
                for(int j = 0; j < pad_amount; j++){
                    A.at(i).push_back(0);
                    B.at(i).push_back(0);
                    C.at(i).push_back(0);
                }
            }
            // then adds pad_amount rows of length
            for(int j = 0; j < pad_amount; j++){
                vector<int> pad_rows (cross_over, 0);
                A.push_back(pad_rows);
                B.push_back(pad_rows);
                C.push_back(pad_rows);
            }
        }
    }
}



