#include "./header/recursive.h"
#include "./header/global.h"

void swapRowsRec(vector<vector<float>> &matrix, int i, int j, int k = 0) {
    int m = matrix[0].size();
    if (k >= m) return; // base case

    float temp = matrix[i][k];
    matrix[i][k] = matrix[j][k];
    matrix[j][k] = temp;

    swapRowsRec(matrix, i, j, k + 1); // recursive case
}  

void divideRowRec(vector<vector<float>> &matrix, int i, float val, int k = 0) {
    int m = matrix[0].size();
    if (k >= m) return;
    matrix[i][k] /= val;
    
    divideRowRec(matrix, i, val, k + 1); // recursive case
}

void subtractRowsRecHelper(vector<vector<float>> &matrix, int i, int j, int lead, float val, int k) {
    int m = matrix[0].size();
    if (k >= m) return; // base case

    matrix[i][k] -= val * matrix[j][k];

    subtractRowsRecHelper(matrix, i, j, lead, val, k + 1); // recursive case
}

void subtractRowsRec(vector<vector<float>> &matrix, int i, int j, int lead, int k = 0) {
    int m = matrix[0].size();
    if (k == 0) {
        float val = matrix[i][lead];
        subtractRowsRecHelper(matrix, i, j, lead, val, k); // recursive case
    }
}

void findReducedRowEchelonFormRec(vector<vector<float>> &matrix, int r, int lead) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (r >= n || lead >= m) return; // base case

    int i = r;
    while (matrix[i][lead] == 0) {
        i++;
        // if (i == n) {
        //     findReducedRowEchelonFormRec(matrix, r, lead + 1); // recursive case
        //     return;
        // }
    }
    if (i == n) {
        findReducedRowEchelonFormRec(matrix, r, lead + 1); // recursive case
        return;
    }
    

    swapRowsRec(matrix, i, r, 0);
    float val = matrix[r][lead];
    divideRowRec(matrix, r, val, 0);

    cout << "After dividing row " << r << " by " << val << ":" << endl;
    printMatrix(matrix);

    for (int i = 0; i < n; i++) {
        if (i != r) {
            //float val = matrix[i][lead];
            subtractRowsRec(matrix, i, r, lead, 0);
        }
    }

    cout << "After subtracting rows using lead " << lead << ":" << endl;
    printMatrix(matrix);

    findReducedRowEchelonFormRec(matrix, r + 1, lead + 1); // recursive case
}
