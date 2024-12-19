#include "./header/global.h"

void inputMatrix(vector<vector<int>> &matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        vector<int> row;
        int constantValue;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        cin >> constantValue;
        row.push_back(constantValue);
        matrix.push_back(row);
    }
}

void printMatrix(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size() - 1; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << matrix[i][matrix[i].size() - 1];
        cout << endl;
    }
} 

// Meenukar 2 baris
void swapRows(vector<vector<int>> &matrix, int row1, int row2) {
    swap(matrix[row1], matrix[row2]);
}

// Membagi baris dengan divisor
void divideRow(vector<vector<int>> &matrix, int row, int divisor) {
    int m = matrix[0].size();
    for (int j = 0; j < m; j++) {
        matrix[row][j] /= divisor;
    }
}

// Mengurangkan baris dengan leadRow (leadRow * val) dari baris
void subtractRows(vector<vector<int>> &matrix, int row, int leadRow, int lead) {
    int m = matrix[0].size();
    int val = matrix[row][lead];
    for (int j = 0; j < m; j++) {
        matrix[row][j] -= val * matrix[leadRow][j];
    }
}

// Mencari bentuk eselon baris tereduksi
void findReducedRowEchelonForm(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int lead = 0;
    for (int r = 0; r < n; r++) {
        if (lead >= m) break; // base case

        int i = r;
        while (matrix[i][lead] == 0) {
            i++;
            if (i == n) {
                i = r;
                lead++;
                if (lead == m) break; // base case
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

void findReducedRowEchelonFormRecursive(vector<vector<int>> &matrix, int r, int lead) {
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
    int val = matrix[r][lead];
    for (int j = 0; j < m; j++) matrix[r][j] /= val;

    for (int i = 0; i < n; i++) {
        if (i != r) {
            int val = matrix[i][lead];
            for (int j = 0; j < m; j++) matrix[i][j] -= val * matrix[r][j];
        }
    }

    findReducedRowEchelonFormRecursive(matrix, r + 1, lead + 1); // recursive case
}

void printSolvedLinearSystem(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
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
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << matrix[i][m - 1] << endl;
    }
}