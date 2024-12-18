#ifndef GLOBAL_H
#define GLOBAL_H
#include <bits/stdc++.h>
using namespace std;

void inputMatrix(vector<vector<int>> &matrix, int n, int m);
void printMatrix(vector<vector<int>> &matrix);
void findReducedRowEchelonForm(vector<vector<int>> &matrix);
void findReducedRowEchelonFormRecursive(vector<vector<int>> &matrix, int r, int lead);

#endif // GLOBAL_H
