//
//  strassens-algorithm.hpp
//
//  Created by Samuel K. Lam on 3/20/17.
//  Copyright © 2017 Samuel K. Lam. All rights reserved.
//

#ifndef strassens_algorithm_hpp
#define strassens_algorithm_hpp

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

void strassen_pow2(vector< vector<int> > &M1, vector< vector<int> > &M2, vector< vector<int> > &M3, int cross_over);

/*
 * Standard matrix addition function
 * @param M1 : reference to matrix 1
 * @param M2 : reference to matrix 2
 * @param M3 : matrix sum of M1 and M2
 * @param n : dimension of the matrices
 */
void matrix_add(vector< vector<int> > &M1, vector< vector<int> > &M2, vector< vector<int> > &M3, int n);

/*
 * Standard matrix subtraction function
 * @param M1 : reference to matrix 1
 * @param M2 : reference to matrix 2
 * @param M3 : matrix difference of M1 and 
 * @param n : dimension of the matrices
 */
void matrix_subtract(vector< vector<int> > &M1, vector< vector<int> > &M2, vector< vector<int> > &M3, int n);

/*
 * Standard matrix multiplication function
 * @param M1 : reference to matrix 1
 * @param M2 : reference to matrix 2
 * @param M3 : the matrix product M1 and M2
 * @param n : dimension of the matrices
 */
void matrix_mult_conv(vector< vector<int> > &M1, vector< vector<int> > &M2, vector< vector<int> > &M3, int n);

#endif /* strassens_algorithm_hpp */

