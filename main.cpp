//
//  main.cpp
//
//  Created on 3/18/17.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void read_file(ifstream &infile, vector< vector<int> > &M1, vector< vector<int> > &M2, int n) {
    int val;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            infile >> val;
            M1[i][j] = val;
        }
    }
    
    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
            infile >> val;
            M2[k][l] = val;
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
