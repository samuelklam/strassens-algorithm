//
//  matrix-functions.hpp
//
//  Created by Samuel K. Lam on 3/20/17.
//  Copyright © 2017 Samuel K. Lam. All rights reserved.
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
 * @param C : C = A + B (matrix sum)
 * @param r1 : starting row index
 * @param c1 : starting column index
 * @param r2 : ending row index (non-inclusive)
 * @param c2 : ending column index (non-inclusive)
 */
void matrix_add(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int n);

/*
 * Standard matrix subtraction function
 * @param A : reference to matrix 1
 * @param B : reference to matrix 2
 * @param C : C = A - B (matrix difference)
 * @param r1 : starting row index
 * @param c1 : starting column index
 * @param r2 : ending row index (non-inclusive)
 * @param c2 : ending column index (non-inclusive)
 */
void matrix_subtract(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int n);

/*
 * Standard matrix multiplication function
 * @param A : reference to matrix 1
 * @param B : reference to matrix 2
 * @param C : C = A * B (matrix product)
 * @param n : dimension of the matrices
 */
void matrix_mult_reg(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int r1, int c1, int r2, int c2, int n);

#endif /* matrix_functions_hpp */
