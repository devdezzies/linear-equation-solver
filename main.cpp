#include "./header/global.h"
#include "./header/recursive.h"

int main() {
    vector<vector<float>> matrix, matrix2;
    int n, m;

    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    cout << "==============ENTER AUGMENTED MATRIX===============" << endl;
    cout << "a11 a12 ... a1m = b1" << endl;
    inputMatrix(matrix, n, m);
    inputMatrix(matrix2, n, m);

    cout << "Matrix (Iterative): " << endl; 
    printMatrix(matrix);
    cout << endl;

    cout << "Matrix (Recursive): " << endl;
    printMatrix(matrix2);
    cout << endl;

    cout << "Reduced Row Echelon Form (Iterative): " << endl;
    findReducedRowEchelonForm(matrix);
    cout << endl;
    printMatrix(matrix);
    cout << endl;

    cout << "Reduced Row Echelon Form (Recursive): " << endl;
    findReducedRowEchelonFormRec(matrix2, 0, 0);
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