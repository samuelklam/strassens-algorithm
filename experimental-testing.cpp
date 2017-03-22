//
//  experimental-testing.cpp
//
//  Functions used to find the experimental cross-over point for Strassen's
//

#include "experimental-testing.hpp"

void test_cross_over_strassens(ofstream &file, int n, int num_trials, bool pow_2) {
    
    double min_time_cross_over = INT_MAX;
    int min_cross_over = 0;
    int end_cross = n;
    int optimal_padding = 0;
    int padding = 0;
    
    clock_t start, end;
    srand((unsigned)time(NULL));
    
    vector<int> cross_over_vec;
    if (pow_2) {
        // test cross_overs by interval powers of 2
        int i = 64;
        while (i <= 64) {
            cross_over_vec.push_back(i);
            i *= 2;
        }
    }
    else {
        // start testing cross-over val from 15 to determined end_cross
        for (int i = 15; i <= end_cross; i++) {
            cross_over_vec.push_back(i);
        }
    }
    
    for (int i = 0; i < cross_over_vec.size(); i++) {
        
        int cross_over = cross_over_vec[i];
        
        padding = find_optimal_matrix_padding(cross_over, n);
        
        // initialize new matrix dimensions with determined padding
        int new_matrix_dim = n + padding;
        vector<int> vector_dim(new_matrix_dim);
        
        // initialize vector of vectors (matrix representation)
        vector< vector<int> > A(new_matrix_dim, vector_dim), B(new_matrix_dim, vector_dim), C(new_matrix_dim, vector_dim);
        
        fill_matrix_rand(A, B, n);
        
        start = clock();
        
        // run for # of trials to find average strassen computation time
        for (int j = 0; j < num_trials; j++) {
            strassen_pad(A, B, C, 0, 0, 0, 0, 0, 0, cross_over, new_matrix_dim);
        }
        
        end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        
        // greedily keep track of the minimum
        if (time_spent < min_time_cross_over) {
            min_time_cross_over = time_spent;
            min_cross_over = cross_over;
            optimal_padding = padding;
        }
    }
    
    cout << "matrix dimension: " << n << ", time: " << min_time_cross_over / num_trials << ", cross-over: " << min_cross_over << ", padding: " << optimal_padding << ", num_trials: " << num_trials << endl;
    file << "matrix dimension: " << n << ", time: " << min_time_cross_over / num_trials << ", cross-over: " << min_cross_over << ", padding: " << optimal_padding << ", num_trials: " << num_trials << endl;
}

void test_cross_over_all_matrices(int start_dim, int end_dim, int num_trials, bool pow_2) {
    ofstream myfile;
    myfile.open("output.txt");
    
    // tests matrices up to dim 64
    for (int i = start_dim; i <= end_dim; i++) {
        test_cross_over_strassens(myfile, i, num_trials, pow_2);
    }
    myfile.close();
}
