//
//  experimental-testing.cpp
//
//  Functions used to find the experimental cross-over point for Strassen's
//

#ifndef experimental_testing_hpp
#define experimental_testing_hpp

#include <stdio.h>
#include <vector>
#include <cmath>
#include <time.h>
#include <fstream>
#include "strassens-algorithm.hpp"

/*
 * Tests for the optimal cross-over value by tracking time, reads output to file
 * @param file : reference to output file
 * @param n : pre-padded matrix dimension
 * @param num_trials : # of trials to run strassens algorithm
 * @param pow_2 : whether to increment testing cross_over points by a power of 2 or to test all points
 * @param algo : takes value 1, 2, 3. Flag to run algo 1, 2, or 3
 */
void test_cross_over_strassens(ofstream &file, int n, int num_trials, bool pow_2, int algo);

/*
 * Finds the optimal cross-over value for matrices from range start_dim to
 * end_dim (inclusive), reads output to file
 * @param start_dim : starting matrix dimension to test from
 * @param end_dim : end matrix dimension to test to
 * @param num_trials : # of trials to run in test_cross_over_strassens
 * @param pow_2 : whether to increment testing cross_over points by a power of 2 or to test all points
 * @param algo : takes value 1, 2, 3. Flag to run algo 1, 2, or 3
 */
void test_cross_over_all_matrices(int start_dim, int end_dim, int num_trials, bool pow_2, int algo);

#endif /* experimental_testing_hpp */
