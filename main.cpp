//
//  main.cpp
//
//  Driver function to read in matrices A, B and calculate C = A*B using Strassen-Variant algo
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
    
    // optimal pre-determined cross_over point
    int cross_over = 64;
    int strassen_algo_flag = 1;
    int read_matrix_bool = 1;
    int print_matrix_flag = 1;
    strassen(infile, cross_over, matrix_dim, strassen_algo_flag, read_matrix_bool, print_matrix_flag);

    return 0;
}
