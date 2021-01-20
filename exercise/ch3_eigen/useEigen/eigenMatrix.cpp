/*
This example demonstrates teh basic operations of Eigen matrix.
*/
#include <iostream>

using namespace std;

#include <ctime>

// Eigen core
#include <Eigen/Core>
// Eigen dense matrix (inverse, eigenvalues, etc.)
#include <Eigen/Dense>
using namespace Eigen;

#define MATRIX_SIZE 50

int main(int argc, char **argv) {
    // Eigen::Matrix, it is a template class.  Parameters: datatype, row, col
    // declare a 2 * 3 float matrix
    Matrix<float, 2, 3> matrix_23;

    // vectord3d is indeed Eigen::Matrix<double, 3, 1>
    Vector3d v_3d;
    // equals to 
    Matrix<float, 3, 1> vd_3d;

    // Matrix3d is indeed Eigen::Matrix<double, 3, 3>
    Matrix3d matrix_33 = Matrix3d::Zero();  // initialize as zeros
    // if not sure about the size, use dynamic matrix
    Matrix<double, Dynamic, Dynamic> matrix_dynamic;
    // or even simpler
    MatrixXd matrix_x;

    // The following is the operation on Eigen matrix
    // input data (initialize)
    matrix_23 << 1, 2, 3, 4, 5, 6;
    cout << "matrix 2x3 from 1 to 6 is \n" << matrix_23 << endl;

    // Use () to get access of the element
    cout << "print matrix 2x3: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix_23(i, j) << "\t";
        }
        cout << endl;
    }

    // assign values to vectors 
    v_3d << 3, 2, 1;
    vd_3d << 4, 5, 6;

    // But it is not abllowd to mixe two types of matrix, such as:
    // Matrix<double, 2, 1> result_wrong_type = matrix_23 * v_3d;
    // We should convert the data type explicitly
    Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    cout << "[1,2,3;4,5,6]*[3,2,1]=" << result.transpose() << endl;

    Matrix<float, 2, 1> result2 = matrix_23 * vd_3d;
    cout << "[1,2,3;4,5,6]*[4,5,6]: " << result2.transpose() << endl;

    // Likewise, you cannot mess up with the dimension
    // for example:
    // Eigen::Matrix<double, 2, 3> result_wrong_dimension = matrix_23.cast<double>() * v_3d;

    // Some matrix operations
    matrix_33 = Matrix3d::Random();  // random matrix
    cout << "random matrix: \n" << matrix_33 << endl;
    cout << "transpose: \n" << matrix_33.transpose() << endl;      // transpose
    cout << "sum: " << matrix_33.sum() << endl;            // sum
    cout << "trace: " << matrix_33.trace() << endl;          // trace
    cout << "times 10: \n" << 10 * matrix_33 << endl;               // multiply by a value
    cout << "inverse: \n" << matrix_33.inverse() << endl;        // inverse
    cout << "det: " << matrix_33.determinant() << endl;    // determinant

    // Eigenvalue
    // 实对称矩阵可以保证对角化成功
    SelfAdjointEigenSolver<Matrix3d> eigen_solver(matrix_33.transpose() * matrix_33);
    cout << "Eigen values = \n" << eigen_solver.eigenvalues() << endl;
    cout << "Eigen vectors = \n" << eigen_solver.eigenvectors() << endl;

    // Solve Equation
    // solve for matrix_NN * x = v_Nd
    // N is defined as a global variable
    // Solving directly is doable, but the compuational cost is huge
     Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN
      = MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    matrix_NN = matrix_NN * matrix_NN.transpose();  // 保证半正定
    Matrix<double, MATRIX_SIZE, 1> v_Nd = MatrixXd::Random(MATRIX_SIZE, 1);

    clock_t time_stt = clock(); // timer
    // sovle inverse directly
    Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse() * v_Nd;
    cout << "time of normal inverse is "
       << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << endl;
    // cout << "x = " << x.transpose() << endl;

    // 通常用矩阵分解来求，例如QR分解，速度会快很多
    time_stt = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout << "time of Qr decomposition is "
        << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << endl;
    // cout << "x = " << x.transpose() << endl;

    // 对于正定矩阵，还可以用cholesky分解来解方程
    time_stt = clock();
    x = matrix_NN.ldlt().solve(v_Nd);
    cout << "time of ldlt decomposition is "
        << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << endl;
    // cout << "x = " << x.transpose() << endl;

    return 0;

}

