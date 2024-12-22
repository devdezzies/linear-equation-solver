#include "./header/global.h"
#include "./header/recursive.h"
#include <chrono>

vector<vector<float>> createDummyMatrix(int rows, int cols) {
    vector<vector<float>> matrix(rows, vector<float>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = static_cast<float>(i + j);
        }
    }
    return matrix;
}

int main() {
    using namespace std::chrono;

<<<<<<< HEAD
    int x = 10; // number of rows
    int y = 10; // number of columns
=======
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    cout << "==============ENTER AUGMENTED MATRIX (iterative)===============" << endl;
    cout << "a11 a12 ... a1m = b1" << endl;
    inputMatrix(matrix, n, m);
    matrix2.assign(matrix.begin(), matrix.end()); // copy matrix to matrix2
>>>>>>> 653f62a145c03073937cea4de5dd5e1f4e8ebb6e

    vector<vector<float>> matrix = createDummyMatrix(x, y+1);
    vector<vector<float>> matrix2 = createDummyMatrix(x, y+1);

    // Profile iterative function
    auto start_iterative = high_resolution_clock::now();
    cout << "Reduced Row Echelon Form (Iterative): " << endl;
    findReducedRowEchelonForm(matrix);
    auto end_iterative = high_resolution_clock::now();
    duration<double> elapsed_iterative = end_iterative - start_iterative;
    cout << "Iterative function execution time: " << elapsed_iterative.count() << " seconds" << endl;
    cout << endl;
    printMatrix(matrix);
    cout << endl;

    // Profile recursive function
    auto start_recursive = high_resolution_clock::now();
    cout << "Reduced Row Echelon Form (Recursive): " << endl;
    findReducedRowEchelonFormRec(matrix2, 0, 0);
    auto end_recursive = high_resolution_clock::now();
    duration<double> elapsed_recursive = end_recursive - start_recursive;
    cout << "Recursive function execution time: " << elapsed_recursive.count() << " seconds" << endl;
    cout << endl;
    printMatrix(matrix2);
    cout << endl;

    cout << "SOLVED LINEAR SYSTEM (Iteratif): " << endl;
    printSolvedLinearSystem(matrix);
    cout << endl;

    cout << "SOLVED LINEAR SYSTEM (Recursive): " << endl;
    printSolvedLinearSystem(matrix2);
    cout << endl;

    return 0;
}

