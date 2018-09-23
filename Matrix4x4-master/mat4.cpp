#include "mat4.h"

float[][] matrix;

// This constructor initializes the 2d float array with v along
// the diagnal [(0, 0), (1, 1), (2, 2), (3, 3)]. The rest of
// the matrix will be zeros.
mat4::mat4(float v){
    matrix = new float[4][4];
    for (int i = 0; i < 4; i++) {
        matrix[i][i] = v;
    }
}

// Copy Constructor. Initilaizes this matrix with the values of the
// passed in matrix.
mat4::mat4(mat4& m){

    matrix = new matrix[4][4];

    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            matrix[column][row] = m.matrix[column][row];
        }
    }
}

// Adds the values of m to this matrix.
void mat4::add(mat4 m){
    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            matrix[column][row] += m.matrix[column][row];
        }
    }
}

// Subtracts the values of m from this matrix
void mat4::subtract(mat4 m){
    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            matrix[column][row] -= m.matrix[column][row];
        }
    }
}

// Multiplies this matrix and m together.
// If you are unfamiliar with the algorithm of multiplying matrices,
// go to this site for an introduction:
// https://www.mathsisfun.com/algebra/matrix-multiplying.html
void mat4::multiply(mat4 m){
    
    mat4 copy = m;

    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            matrix[column][row] = (copy.matrix[0][row] * m.matrix[column][0]) + (copy.matrix[1][row] * m.matrix[column][1]) + (copy.matrix[2][row] * m.matrix[column][2]) + (copy.matrix[3][row] * m.matrix[column][3]);
        }
    }
}

// Multiplies m1 and m2 and returns the result.
mat4 mat4::multiply(mat4 m1, mat4 m2){

    mat4 returnThis = new mat4();

    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            mat4.matrix[column][row] = (m1.matrix[0][row] * m2.matrix[column][0]) + (m1.matrix[1][row] * m2.matrix[column][1]) + (m1.matrix[2][row] * m2.matrix[column][2]) + (m1.matrix[3][row] * m2.matrix[column][3]);
        }
    }
}

// Adds m1 and m2 and returns the result.
mat4 mat4::add(mat4 m1, mat4 m2){

    mat4 m = new mat4();

    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            m.matrix[column][row] = m1.matrix[column][row] + m2.matrix[column][row];
        }
    }

    return m;
}

// subtracts m2 from m1 and returns the result.
mat4 mat4::subtract(mat4 m1, mat4 m2){
    
    mat4 m = new mat4();

    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            m.matrix[column][row] = m1.matrix[column][row] - m2.matrix[column][row];
        }
    }

    return m;
}