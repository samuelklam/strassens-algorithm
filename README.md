# Strassen's Algorithm

We implement Strassen’s algorithm to improve the standard matrix multiplication algorithm, Θ(n<sup>3</sup>), for reasonably sized matrices to Θ(n<sup>log7</sup>). For sufficiently large values of n, Strassen’s algorithm will run faster than the conventional algorithm. For small values of n, however, the conventional algorithm may be faster. We can define the cross-over point between the two algorithms to be the value of n for which we want to stop using Strassens algorithm and switch to conventional matrix multiplication. We seek to analytically and experimentally determine the cross-over point.

We define Strassen's algorithm as follows. Given matrices A and B of size n, we split each into 4 sub-matrices of size n/2. We denote A<sub>1, 1</sub>, A<sub>1, 2</sub>, A<sub>2, 1</sub>, A<sub>2, 2</sub> as the sub-matrices of matrix A and B<sub>1, 1</sub>, B<sub>1, 2</sub>, B<sub>2, 1</sub>, B<sub>2, 2</sub> as the sub-matrices of matrix B, where A<sub>1, 2</sub> denotes the sub-matrix on the top right of A. We compute the following seven products:

- M<sub>1</sub> = A<sub>1, 1</sub>(B<sub>1, 2</sub> - B<sub>2, 2</sub>)
- M<sub>2</sub> = (A<sub>1, 1</sub> + A<sub>1, 2</sub>)B<sub>2, 2</sub>
- M<sub>3</sub> = (A<sub>2, 1</sub> + A<sub>2, 2</sub>)B<sub>1, 1</sub>
- M<sub>4</sub> = A<sub>2, 2</sub>(B<sub>2, 1</sub> - B<sub>1, 1</sub>)
- M<sub>5</sub> = (A<sub>1, 1</sub> + A<sub>2, 2</sub>)(B<sub>1, 1</sub> + B<sub>2, 2</sub>)
- M<sub>6</sub> = (A<sub>1, 2</sub> - A<sub>2, 2</sub>)(B<sub>2, 1</sub> + B<sub>2, 2</sub>)
- M<sub>7</sub> = (A<sub>1, 1</sub> - A<sub>2, 1</sub>)(B<sub>1, 1</sub> + B<sub>1, 2</sub>)

Then we can find the appropriate terms of the product by addition, such that C = AB and C<sub>1, 2</sub> denotes the top right section of C:

- C<sub>1, 1</sub> = M<sub>5</sub> + M<sub>4</sub> - M<sub>2</sub> + M<sub>6</sub>
- C<sub>1, 2</sub> = M<sub>1</sub> + M<sub>2</sub>
- C<sub>2, 1</sub> = M<sub>3</sub> + M<sub>4</sub>
- C<sub>2, 2</sub> = M<sub>5</sub> + M<sub>1</sub> - M<sub>3</sub> - M<sub>7</sub>

For a full write-up refer to: `strassens-writeup.pdf`.

## Usage

In the command line:
```
$ make
$ ./strassen 0 dimension inputfile
```

The flag 0 can be used for testing, debugging, or extensions. The `dimension` d, is the dimension of the matrix being multiplied; e.g. 32 denotes multiplying two 32 x 32 matrices together. The `inputfile` is an ASCII file with 2d<sup>2</sup> integer numbers, one per line, representing two matrices A and B. The first integer number is matrix entry a<sub>0,0</sub>, followed by a<sub>0,1</sub>, a<sub>0,2</sub>, ..., a<sub>0,d-1</sub>; next comes a<sub>1,0</sub>, a<sub>1,1</sub>, and so on, for the first d<sup>2</sup> numbers. The next d<sup>2</sup> numbers are similar for matrix B.

The output is a list of values of the diagonal entries of C = AB; i.e. c<sub>0,0</sub>, c<sub>1,1</sub>, ..., c<sub>d-1,d-1</sub>, one per line, followed by a trailing newline.

There are four Strassen-Variant algorithms. To run each one, set `strassen_algo_flag` in `main.cpp` to [1, 4] accordingly.
