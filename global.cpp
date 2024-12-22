#include "./header/global.h"

// INPUT MATRIX (AUGMENTED MATRIX) => n x (m + 1)
void inputMatrix(vector<vector<float>> &matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        vector<float> row;
        float constantValue;
        for (int j = 0; j < m; j++) {
            float x;
            cin >> x;
            row.push_back(x);
        }
        cin >> constantValue;
        row.push_back(constantValue);
        matrix.push_back(row);
    }
}

// PRINT MATRIX (AUGMENTED MATRIX) => n x (m + 1)
void printMatrix(vector<vector<float>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size() - 1; j++) {
            cout << matrix[i][j] << " "; // basic operation
        }
        cout << matrix[i][matrix[i].size() - 1];
        cout << endl;
    }
}

// swap rows
void swapRows(vector<vector<float>> &matrix, int row1, int row2) {
    int m = matrix[0].size();
    for (int j = 0; j < m; j++) {
        float temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

// divide row by divisor to do basic row operation (row operation) => row = row / divisor
void divideRow(vector<vector<float>> &matrix, int row, float divisor) {
    int m = matrix[0].size();
    for (int j = 0; j < m; j++) {
        matrix[row][j] /= divisor;
    }
}

// substraction of two rows
void subtractRows(vector<vector<float>> &matrix, int row, int leadRow, int lead) {
    int m = matrix[0].size();
    float val = matrix[row][lead];
    for (int j = 0; j < m; j++) {
        matrix[row][j] -= val * matrix[leadRow][j];
    }
}

// find the reduced row echelon form of the matrix
void findReducedRowEchelonForm(vector<vector<float>> &matrix) {
    int n = matrix.size(); // n is the number of rows
    int m = matrix[0].size(); // m is the number of columns
    int lead = 0; // start from the first column
    // r = row, lead = column, i = iterator
    for (int r = 0; r < n; r++) {
        if (lead >= m) break; // to ensure that the lead is within the column
        int i = r;
        // find the first non-zero element in the column
        while (matrix[i][lead] == 0) {
            i++;
            if (i == n) { // if the lead is zero, move to the next column
                i = r;
                lead++;
                if (lead == m) break; // to ensure that the lead is within the column
            }
        }

        if (lead < m) {
            swapRows(matrix, i, r);
            divideRow(matrix, r, matrix[r][lead]);

            for (int i = 0; i < n; i++) {
                if (i != r) {
                    subtractRows(matrix, i, r, lead);
                }
            }
            lead++;
        }
    }
}

void findReducedRowEchelonFormRecursive(vector<vector<float>> &matrix, int r, int lead) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (r >= n || lead >= m) return; // base case

    int i = r;
    while (matrix[i][lead] == 0) {
        i++;
        if (i == n) {
            findReducedRowEchelonFormRecursive(matrix, r, lead + 1); // recursive case
            return;
        }
    }

    swap(matrix[i], matrix[r]);
    float val = matrix[r][lead];
    for (int j = 0; j < m; j++) matrix[r][j] /= val;

    for (int i = 0; i < n; i++) {
        if (i != r) {
            float val = matrix[i][lead];
            for (int j = 0; j < m; j++) matrix[i][j] -= val * matrix[r][j]; // TODO: REFACTOR
        }
    }

    findReducedRowEchelonFormRecursive(matrix, r + 1, lead + 1); // recursive case
}

void printSolvedLinearSystem(vector<vector<float>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    // check if the row is all zeros except the last element
    for (int i = 0; i < n; i++) {
        bool isZero = true;
        for (int j = 0; j < m - 1; j++) {
            if (matrix[i][j] != 0) {
                isZero = false;
                break;
            }
        }
        if (isZero && matrix[i][m - 1] != 0) {
            cout << "NO SOLUTION" << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        bool isZero = true;
        // check if the row is all zeros
        for (int j = 0; j < m - 1; j++) {
            if (matrix[i][j] != 0) {
                isZero = false;
                break;
            }
        }
        if (isZero && matrix[i][m - 1] == 0) {
            cout << "INFINITE SOLUTION" << endl;
            return;
        }
    }
    // print the solution
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << matrix[i][m - 1] << endl;
    }
}