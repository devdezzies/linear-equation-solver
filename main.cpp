#include "./header/global.h"

int main() {
    vector<vector<int>> matrix;
    int n, m;

    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    inputMatrix(matrix, n, m);
    
    cout << "Matrix: " << endl; 
    printMatrix(matrix);

    cout << "Reduced Row Echelon Form: " << endl;
    findReducedRowEchelonForm(matrix);
    printMatrix(matrix);

    return 0;
}