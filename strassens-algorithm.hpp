//
//  strassens-algorithm.hpp
//
//  File contains an implementation of Strassen's Algorithm for Faster Matrix Multiplication
//

#ifndef strassens_algorithm_hpp
#define strassens_algorithm_hpp

#include <stdio.h>
#include <vector>
#include <fstream>
#include <cmath>
#include "matrix-functions.hpp"

/*
 * Strassen's matrix multiplication algorithm post-padded
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
void strassen_pad(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int r3, int c3, int cross_over, int n);

void strassen_odd_pad(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int r3, int c3, int cross_over, int n);

/*
 * Strassen's matrix multiplication pre-padded, finds optimal padding based on given cross_over point
 * extracts matrix diagonal
 * @param cross_over : matrix dimension to switch to regular matrix multiplication
 * @param n : dimension of the matrices
 */
void strassen(ifstream &file, int cross_over, int n);

void strassen_odd_padding(ifstream &file, int cross_over, int n);

/*
 * Function reads in 2D matrix values into a vector of vectors
 * @param infile : reference to the input file
 * @param A : reference to Matrix to read in values
 * @param n : # of matrix values to read in per matrix
 */
void read_file(ifstream &infile, vector< vector<int> > &A, int n);

/*
 * Finds the number of rows/columns to pad based on the cross_over value
 * @param cross_over : given cross_over value (optimal or not)
 * @param n : pre-padded matrix dimension
 */
int find_pow2_matrix_padding(int cross_over, int n);

/*
 * Finds the optimal number of rows/columns to pad based on the cross_over value
 * @param cross_over : given cross_over value (optimal or not)
 * @param n : pre-padded matrix dimension
 */
int find_opt_matrix_padding(int cross_over, int n);

#endif /* strassens_algorithm_hpp */

