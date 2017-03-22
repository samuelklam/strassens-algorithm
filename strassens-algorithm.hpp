//
//  strassens-algorithm.hpp
//
//  File contains an implementation of Strassen's Algorithm for Faster Matrix Multiplication
//

#ifndef strassens_algorithm_hpp
#define strassens_algorithm_hpp

#include <stdio.h>
#include <vector>
#include <cmath>
#include <time.h>
#include <fstream>
#include "matrix-functions.hpp"

/*
 * Strassen's matrix multiplication algorithm
 * @param A : reference to matrix 1
 * @param B : reference to matrix 2
 * @param C : C = A * B (matrix product)
 * @param r1 : starting row index for A
 * @param c1 : starting column index for A
 * @param r2 : starting row index for B
 * @param c2 : starting column index for B
 * @param r3 : starting row index for C
 * @param c3 : starting column index for C
 * @param cross_over : matrix dimension to switch to regular matrix multiplication
 * @param n : dimension of the matrices
 */
void strassen_pow2(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int r3, int c3, int cross_over, int n);

/*
 * Finds the optimal number of rows/columns to pad based on the cross_over value
 * @param cross_over : given cross_over value (optimal or not)
 * @param n : pre-padded matrix dimension
 */
int find_optimal_matrix_padding(int cross_over, int n);

/*
 * Fills in the matrix with random 0s or 1s
 * @param A : reference to matrix 1
 * @param B : reference to matrix 2
 * @param n : matrix dimensions to fill in up to
 */
void fill_matrix_rand(vector< vector<int> > &A, vector< vector<int> > &B, int n);

/*
 * Tests for the optimal cross-over value by tracking time, reads output to file
 * @param file : reference to output file
 * @param n : pre-padded matrix dimension
 */
void test_cross_over_strassens(ofstream &file, int n);

/*
 * Finds the optimal cross-over value for matrices from range start_dim to end_dim
 * @param start_dim : starting matrix dimension to test from
 * @param end_dim : end matrix dimension to test to
 */
void test_cross_over_all_matrices(int start_dim, int end_dim);

/*
 * Pad matrix with 0's so Strassen's will work
 * @param A : reference to matrix 1
 * @param B : reference to matrix 2
 * @param C : reference to matrix solution
 * @param cross_over : matrix dimension to switch to regular matrix multiplication
 * @param n : dimension of the matrices
 */
void pad_matrix(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> >&C, int cross_over, int n);
#endif /* strassens_algorithm_hpp */

