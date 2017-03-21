//
//  matrix-functions.hpp
//
//  File contains an assortment of matrix helper functions
//  Matrix print, add, subtract, and standard multiplication
//

#ifndef matrix_functions_hpp
#define matrix_functions_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
 * Print matrix function for debugging and testing purposes
 * @param matrix : reference to matrix
 */
void matrix_print(vector< vector<int> > &matrix);

/*
 * Standard matrix addition function
 * @param A : reference to matrix 1
 * @param B : reference to matrix 2
 * @param C : C = A + B (matrix addition)
 * @param r1 : starting row index for A
 * @param c1 : starting column index for A
 * @param r2 : starting row index for B
 * @param c2 : starting column index for B
 * @param n : dimension of the matrices
 */
void matrix_add(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int r3, int c3, int n);

/*
 * Standard matrix subtraction function
 * @param A : reference to matrix 1
 * @param B : reference to matrix 2
 * @param C : C = A - B (matrix difference)
 * @param r1 : starting row index for A
 * @param c1 : starting column index for A
 * @param r2 : starting row index for B
 * @param c2 : starting column index for B
 * @param n : dimension of the matrices
 */
void matrix_subtract(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int r3, int c3, int n);

/*
 * Standard matrix multiplication function
 * @param A : reference to matrix 1
 * @param B : reference to matrix 2
 * @param C : C = A * B (matrix product)
 * @param r1 : starting row index for A
 * @param c1 : starting column index for A
 * @param r2 : starting row index for B
 * @param c2 : starting column index for B
 * @param n : dimension of the matrices
 */
void matrix_mult_reg(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int r3, int c3, int n);

#endif /* matrix_functions_hpp */
