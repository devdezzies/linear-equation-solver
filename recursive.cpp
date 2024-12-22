#include <vector>
using namespace std;

// Recursive row swapping
void swapRowsRec(vector<vector<float>> &matrix, int row1, int row2, int col = 0) {
    int m = matrix[0].size();
    // Base case: reached end of row
    if (col >= m) return;
    
    // Swap current elements
    float temp = matrix[row1][col];
    matrix[row1][col] = matrix[row2][col];
    matrix[row2][col] = temp;
    
    // Recurse on next column
    swapRowsRec(matrix, row1, row2, col + 1);
}

// Recursive row division
// TODO: RESOLVE BUG
void divideRowRec(vector<vector<float>> &matrix, int row, float divisor, int col = 0) {
    int m = matrix[0].size();
    // Base case: reached end of row
    if (col >= m) return;
    
    // Divide current element
    matrix[row][col] /= divisor;
    
    // Recurse on next column
    divideRowRec(matrix, row, divisor, col + 1);
}

// Recursive row subtraction
// TODO: RESOLVE BUG
void subtractRows(vector<vector<float>> &matrix, int row, int leadRow, int lead, int col = 0) {
    int m = matrix[0].size();
    // Base case: reached end of row
    if (col >= m) return;
    
    float val = matrix[row][lead];
    // Subtract current element
    matrix[row][col] -= val * matrix[leadRow][col];
    
    // Recurse on next column
    subtractRows(matrix, row, leadRow, lead, col + 1);
}

// Helper function for recursive row subtractions
// TODO: RESOLVE BUG
void processRowSubtractions(vector<vector<float>> &matrix, int r, int lead, int currentRow = 0) {
    int n = matrix.size();
    // Base case: processed all rows
    if (currentRow >= n) return;
    
    // Skip the pivot row
    if (currentRow != r) {
        subtractRows(matrix, currentRow, r, lead);
    }
    
    // Recurse on next row
    processRowSubtractions(matrix, r, lead, currentRow + 1);
}

// Helper function to find first non-zero element
bool findNonZeroElement(vector<vector<float>> &matrix, int &i, int &lead, int r, int n, int m) {
    if (lead >= m) return false;
    
    if (matrix[i][lead] != 0) return true;
    
    i++;
    if (i == n) {
        i = r;
        lead++;
        return findNonZeroElement(matrix, i, lead, r, n, m);
    }
    
    return findNonZeroElement(matrix, i, lead, r, n, m);
}

void findReducedRowEchelonFormRec(vector<vector<float>> &matrix, int r, int lead) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (r >= n || lead >= m) return; // base case

    int i = r;
    while (matrix[i][lead] == 0) {
        i++;
        if (i == n) {
            findReducedRowEchelonFormRec(matrix, r, lead + 1); // recursive case
            return;
        }
    }

    swapRowsRec(matrix, i, r);
    float val = matrix[r][lead];
    for (int j = 0; j < m; j++) matrix[r][j] /= val;

    for (int i = 0; i < n; i++) {
        if (i != r) {
            float val = matrix[i][lead];
            for (int j = 0; j < m; j++) matrix[i][j] -= val * matrix[r][j]; // TODO: REFACTOR
        }
    }

    findReducedRowEchelonFormRec(matrix, r + 1, lead + 1); // recursive case
}
