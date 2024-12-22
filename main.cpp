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

    int x = 10; // number of rows
    int y = 10; // number of columns

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