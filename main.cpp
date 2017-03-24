//
//  main.cpp
//
//  Created on 3/18/17.
//

#include <iostream>
#include <fstream>
#include "strassens-algorithm.hpp"
#include "experimental-testing.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    if (argc != 4) {
        cout << "Invalid arguments!" << endl;
        return 1;
    }
    
    int matrix_dim = atoi(argv[2]);
    ifstream infile(argv[3]);
    
//    // optimal pre-determined cross_over point
//    int cross_over = 63;
//    int opt_algo = 1;
//    int read_matrix_vals = 1;
//    int print_bool = 1;
//    strassen(infile, cross_over, matrix_dim, opt_algo, read_matrix_vals, print_bool);

    test_cross_over_all_matrices(64, 64, 25, 0);
    return 0;
}
