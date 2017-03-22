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
    
    // optimal pre-determined cross_over point
    int cross_over = 2;

    strassen(infile, cross_over, matrix_dim);
    
//    test_cross_over_all_matrices(2048, 2048, 1, 1);
    
    return 0;
}
