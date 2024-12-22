#ifndef RECURSIVE_H
#define RECURSIVE_H
#include <bits/stdc++.h>    
using namespace std;

void findReducedRowEchelonFormRec(vector<vector<float>> &matrix, int r, int lead);
void swapRowsRec(vector<vector<float>> &matrix, int i, int j);
void divideRowRec(vector<vector<float>> &matrix, int i, float val);
void subtractRowsRec(vector<vector<float>> &matrix, int i, int j, int lead);

#endif // RECURSIVE_H