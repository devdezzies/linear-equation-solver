#include "./header/global.h"

void inputMatrix(vector<vector<int>> &matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }
}

void printMatrix(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
} 

void findReducedRowEchelonForm(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int lead = 0;
    for (int r = 0; r < n; r++) {
        if (m <= lead) {
            return;
        }
        int i = r;
        while (matrix[i][lead] == 0) {
            i++;
            if (n == i) {
                i = r;
                lead++;
                if (m == lead) {
                    return;
                }
            }
        }
        swap(matrix[i], matrix[r]);
        int val = matrix[r][lead];
        for (int j = 0; j < m; j++) {
            matrix[r][j] /= val;
        }
        for (int i = 0; i < n; i++) {
            if (i != r) {
                int val = matrix[i][lead];
                for (int j = 0; j < m; j++) {
                    matrix[i][j] -= val * matrix[r][j];
                }
            }
        }
        lead++;
    }
}

void findReducedRowEchelonFormRecursive(vector<vector<int>> &matrix, int r, int lead) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (m <= lead) {
        return;
    }
    int i = r;
    while (matrix[i][lead] == 0) {
        i++;
        if (n == i) {
            i = r;
            lead++;
            if (m == lead) {
                return;
            }
        }
    }
    swap(matrix[i], matrix[r]);
    int val = matrix[r][lead];
    for (int j = 0; j < m; j++) {
        matrix[r][j] /= val;
    }
    for (int i = 0; i < n; i++) {
        if (i != r) {
            int val = matrix[i][lead];
            for (int j = 0; j < m; j++) {
                matrix[i][j] -= val * matrix[r][j];
            }
        }
    }
    findReducedRowEchelonFormRecursive(matrix, r + 1, lead + 1);
}