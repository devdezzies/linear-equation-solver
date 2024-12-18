#ifndef GLOBAL_H
#define GLOBAL_H
#include <bits/stdc++.h>
using namespace std;

void inputMatrix(vector<vector<int>> &matrix, int n, int m);
void printMatrix(vector<vector<int>> &matrix);
void findReducedRowEchelonForm(vector<vector<int>> &matrix);
void findReducedRowEchelonFormRecursive(vector<vector<int>> &matrix, int r, int lead);
void swapRows(vector<vector<int>> &matrix, int i, int j);
void divideRow(vector<vector<int>> &matrix, int i, int val);
void subtractRows(vector<vector<int>> &matrix, int i, int j, int lead);
void printSolvedLinearSystem(vector<vector<int>> &matrix);

#endif // GLOBAL_H
