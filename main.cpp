#include "./header/global.h"
#include "./header/recursive.h"
#include <chrono>

vector<vector<float>> createDummyMatrix(int x, int y) {
    vector<vector<float>> matrix;
    for (int i = 0; i < x; i++) {
        vector<float> row;
        for (int j = 0; j < y; j++) {
            row.push_back(rand() % 10);
        }
        matrix.push_back(row);
    }
    return matrix;
}

int main() {
    using namespace std::chrono;
    int n, m;
// number of columns
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    vector<vector<float>> matrix2;
    // cout << "==============ENTER AUGMENTED MATRIX (iterative)===============" << endl;
    // cout << "a11 a12 ... a1m = b1" << endl;
    // inputMatrix(matrix, n, m);
    // matrix2.assign(matrix.begin(), matrix.end()); // copy matrix to matrix2

    vector<vector<float>> matrix = createDummyMatrix(n, m+1);
    matrix2.assign(matrix.begin(), matrix.end()); // copy matrix to matrix2

    // cout << "==============DUMMY MATRIX 1===============" << endl;
    // printMatrix(matrix);
    // cout << endl; 
    // cout << "==============DUMMY MATRIX 2===============" << endl;
    // printMatrix(matrix2);
    // cout << endl;

    // Profile iterative function
    auto start_iterative = high_resolution_clock::now();
    cout << "Reduced Row Echelon Form (Iterative): " << endl;
    findReducedRowEchelonForm(matrix);
    auto end_iterative = high_resolution_clock::now();
    duration<double> elapsed_iterative = end_iterative - start_iterative;
    cout << "Iterative function execution time: " << elapsed_iterative.count() << " seconds" << endl;
    // cout << endl;
    // printMatrix(matrix);
    // cout << endl;

    // Profile recursive function
    auto start_recursive = high_resolution_clock::now();
    cout << "Reduced Row Echelon Form (Recursive): " << endl;
    findReducedRowEchelonFormRec(matrix2, 0, 0);
    auto end_recursive = high_resolution_clock::now();
    duration<double> elapsed_recursive = end_recursive - start_recursive;
    cout << "Recursive function execution time: " << elapsed_recursive.count() << " seconds" << endl;
    // cout << endl;
    // printMatrix(matrix2);
    // cout << endl;

    // cout << "SOLVED LINEAR SYSTEM (Iteratif): " << endl;
    // printSolvedLinearSystem(matrix);
    // cout << endl;

    // cout << "SOLVED LINEAR SYSTEM (Recursive): " << endl;
    // printSolvedLinearSystem(matrix2);
    // cout << endl;
    cout << "BERES" << endl;

    return 0;
}

