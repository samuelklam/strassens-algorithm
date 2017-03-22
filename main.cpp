//
//  main.cpp
//
//  Created on 3/18/17.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "strassens-algorithm.hpp"
#include <math.h>

using namespace std;

/*
 * Function reads in 2D matrix values into a vector of vectors
 * @param infile : reference to the input file
 * @param A : reference to Matrix 1
 * @param B : reference to Matrix 2
 * @param n : # of matrix values to read in per matrix
 */
void read_file(ifstream &infile, vector< vector<int> > &A, vector< vector<int> > &B, int n) {
    int val;
    
    // iterate over which matrix
    for (int m = 0; m < 2; m++) {
        // iterate over dimensions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                infile >> val;
                if (m == 0) {
                    A[i][j] = val;
                }
                else {
                    B[i][j] = val;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    if (argc != 4) {
        cout << "Invalid arguments!" << endl;
        return 1;
    }
    
    int matrix_dim = atoi(argv[2]);
    ifstream infile(argv[3]);
    
    // raise the dimension to the next, closest power of 2
    int new_matrix_dim = pow(2, int(ceil(log2(matrix_dim))));
    
    vector<int> vector_dim(new_matrix_dim);
    
    // initialize vector of vectors (matrix representation)
    vector< vector<int> > A(new_matrix_dim, vector_dim), B(new_matrix_dim, vector_dim), C(new_matrix_dim, vector_dim);
    
    // store values in matrix A and B
    read_file(infile, A, B, matrix_dim);
    infile.close();
    cout << "Matrix A" << endl;
    matrix_print(A);
    cout << "Matrix B" << endl;
    matrix_print(B);
    int cross_over = 3;
    strassen_pow2(A, B, C, 0, 0, 0, 0, 0, 0, cross_over, new_matrix_dim);
//    matrix_mult_reg(A, B, C, 0, 0, 0, 0, 0, 0, matrix_dim);
    cout << "Matrix C = A*B" << endl;
    matrix_print(C);
    
    pad_matrix(A, B, C, cross_over, matrix_dim);
    cout << "Matrix A padded" << endl;
    matrix_print(A);
    cout << "Matrix B padded" << endl;
    matrix_print(B);
    return 0;
}
