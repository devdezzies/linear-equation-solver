#include "./header/global.h"

int main() {
    vector<vector<int>> matrix;
    int n, m;

    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    cout << "==============ENTER AUGMENTED MATRIX===============" << endl;
    cout << "a11 a12 ... a1m = b1" << endl;
    inputMatrix(matrix, n, m);

    cout << "Matrix: " << endl; 
    printMatrix(matrix);

    cout << "Reduced Row Echelon Form: " << endl;
    findReducedRowEchelonForm(matrix);
    printMatrix(matrix);

    cout << "RESOLVED LINEAR SYSTEM: " << endl;
    printSolvedLinearSystem(matrix);

    return 0;
}