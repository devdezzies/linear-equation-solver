#ifndef GLOBAL_H
#define GLOBAL_H
#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;
using namespace chrono;

void inputMatrix(vector<vector<float>> &matrix, int n, int m);
void printMatrix(vector<vector<float>> &matrix);
void findReducedRowEchelonForm(vector<vector<float>> &matrix);
void findReducedRowEchelonFormRecursive(vector<vector<float>> &matrix, int r, int lead);
void swapRows(vector<vector<float>> &matrix, int i, int j);
void divideRow(vector<vector<float>> &matrix, int i, float val);
void subtractRows(vector<vector<float>> &matrix, int i, int j, int lead);
void printSolvedLinearSystem(vector<vector<float>> &matrix);
vector<vector<float>> createDummyMatrix(int x, int y);
void plotData();
void saveDataToFile(const vector<double>& iterative_times, const vector<double>& recursive_times);
#endif // GLOBAL_H
