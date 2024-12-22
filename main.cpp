#include "./header/global.h"
#include "./header/recursive.h"
#include <fstream>
#include <iostream>

void saveDataToFile(const vector<double>& iterative_times, 
                   const vector<double>& recursive_times) {
    ofstream dataFile("execution_times.txt");
    for (size_t i = 0; i < iterative_times.size(); i++) {
        dataFile << i << " " << iterative_times[i] 
                << " " << recursive_times[i] << endl;
    }
    dataFile.close();
}

void plotData() {
    // Create gnuplot script
    ofstream scriptFile("plot_script.plt");
    scriptFile << "set title 'Execution Time Comparison'\n"
               << "set xlabel 'Test Number'\n"
               << "set ylabel 'Time (seconds)'\n"
               << "plot 'execution_times.txt' using 1:2 title 'Iterative' with lines,\\\n"
               << "     'execution_times.txt' using 1:3 title 'Recursive' with lines\n"
               << "pause -1\n";
    scriptFile.close();

    // Execute gnuplot
    system("gnuplot plot_script.plt");
}

vector<vector<float>> createDummyMatrix(int x, int y) {
    vector<vector<float>> matrix;
    for (int i = 0; i < x; i++) {
        vector<float> row;
        for (int j = 0; j < y; j++) {
            row.push_back(rand() % 10);
        }
        matrix.push_back(row);
    }
    return matrix;
}

int main() {
    using namespace std::chrono;
    int n, m;
// number of columns
    // cout << "Enter the number of rows and columns: ";
    // cin >> n >> m;
    // vector<vector<float>> matrix2;
    // vector<vector<float>> matrix = createDummyMatrix(n, m+1);
    // matrix2.assign(matrix.begin(), matrix.end()); // copy matrix to matrix2


    // // Profile iterative function
    // auto start_iterative = high_resolution_clock::now();
    // cout << "Reduced Row Echelon Form (Iterative): " << endl;
    // findReducedRowEchelonForm(matrix);
    // auto end_iterative = high_resolution_clock::now();
    // duration<double> elapsed_iterative = end_iterative - start_iterative;
    // cout << "Iterative function execution time: " << elapsed_iterative.count() << " seconds" << endl;

    // // Profile recursive function
    // auto start_recursive = high_resolution_clock::now();
    // cout << "Reduced Row Echelon Form (Recursive): " << endl;
    // findReducedRowEchelonFormRec(matrix2, 0, 0);
    // auto end_recursive = high_resolution_clock::now();
    // duration<double> elapsed_recursive = end_recursive - start_recursive;
    // cout << "Recursive function execution time: " << elapsed_recursive.count() << " seconds" << endl;


    vector<double> iterative_times;
    vector<double> recursive_times;
    
    // Run tests multiple times
    for (int i = 5; i <= 100; i++) {
        vector<vector<float>> matrix2;
        vector<vector<float>> matrix = createDummyMatrix(i, i+1);
        matrix2.assign(matrix.begin(), matrix.end());

        auto start_iterative = high_resolution_clock::now();
        findReducedRowEchelonForm(matrix);
        auto end_iterative = high_resolution_clock::now();
        iterative_times.push_back(duration<double>(end_iterative - start_iterative).count());

        auto start_recursive = high_resolution_clock::now();
        findReducedRowEchelonFormRec(matrix2, 0, 0);
        auto end_recursive = high_resolution_clock::now();
        recursive_times.push_back(duration<double>(end_recursive - start_recursive).count());
    }

    saveDataToFile(iterative_times, recursive_times);
    plotData();

    return 0;
}

