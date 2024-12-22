#include "./header/global.h"
#include "./header/recursive.h"

int main() {
    vector<vector<float>> matrix;
    int n, m;

    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    cout << "==============ENTER AUGMENTED MATRIX===============" << endl;
    cout << "a11 a12 ... a1m = b1" << endl;
    inputMatrix(matrix, n, m);

    cout << "Matrix: " << endl; 
    printMatrix(matrix);

    cout << "Reduced Row Echelon Form: " << endl;
    findReducedRowEchelonFormRec(matrix, 0, 0);
    printMatrix(matrix);

    cout << "SOLVED LINEAR SYSTEM: " << endl;
    printSolvedLinearSystem(matrix);

    return 0;
}

