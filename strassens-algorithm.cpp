//
//  strassens-algorithm.cpp
//
//  Created by Samuel K. Lam on 3/20/17.
//  Copyright © 2017 Samuel K. Lam. All rights reserved.
//

#include "strassens-algorithm.hpp"

using namespace std;

void print_matrix(vector< vector<int> > &matrix) {
    unsigned long n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << endl;
        }
    }
}
