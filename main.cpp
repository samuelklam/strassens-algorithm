//
//  main.cpp
//
//  Created on 3/18/17.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "strassens-algorithm.hpp"

using namespace std;

/*
 * Function reads in 2D matrix values into a vector of vectors
 * @param infile : reference to the input file
 * @param M1 : reference to Matrix 1
 * @param M2 : reference to Matrix 2
 * @param n : # of matrix values to read in per matrix
 */
void read_file(ifstream &infile, vector< vector<int> > &M1, vector< vector<int> > &M2, int n) {
    int val;
    
    // iterate over which matrix
    for (int m = 0; m < 2; m++) {
        // iterate over dimensions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                infile >> val;
                if (m == 0) {
                    M1[i][j] = val;
                }
                else {
                    M2[i][j] = val;
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
    
    vector<int> dim(matrix_dim);
    
    // initialize vector of vectors (matrix representation)
    vector< vector<int> > M1(matrix_dim, dim), M2(matrix_dim, dim), M3(matrix_dim, dim);
    
    read_file(infile, M1, M2, matrix_dim);
    infile.close();
    
    return 0;
}
