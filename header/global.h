#ifndef GLOBAL_H
#define GLOBAL_H
#include <bits/stdc++.h>
using namespace std;

void inputMatrix(vector<vector<float>> &matrix, int n, int m);
void printMatrix(vector<vector<float>> &matrix);
void findReducedRowEchelonForm(vector<vector<float>> &matrix);
void findReducedRowEchelonFormRecursive(vector<vector<float>> &matrix, int r, int lead);
void swapRows(vector<vector<float>> &matrix, int i, int j);
void divideRow(vector<vector<float>> &matrix, int i, float val);
void subtractRows(vector<vector<float>> &matrix, int i, int j, int lead);
void printSolvedLinearSystem(vector<vector<float>> &matrix);

#endif // GLOBAL_H
