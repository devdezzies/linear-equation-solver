#include "./header/global.h"
#include "./header/recursive.h"


int main() {
    using namespace std::chrono;
    int n, m, choice, limit;
    vector<vector<float>> matrix, matrix2;
    cout << "Manual (0) OR Rapid fire Test? (1) ";
    cin >> choice;



    if (choice == 0) {
        cout << "Enter the number of rows and columns: ";
        cin >> n >> m;
        cout << "==============ENTER AUGMENTED MATRIX===============" << endl;
        cout << "a11 a12 ... a1m = b1" << endl;
        inputMatrix(matrix, n, m);
        matrix2.assign(matrix.begin(), matrix.end()); // copy matrix to matrix2

        //Profile iterative function
        auto start_iterative = high_resolution_clock::now();
        findReducedRowEchelonForm(matrix);
        auto end_iterative = high_resolution_clock::now();
        duration<double> elapsed_iterative = end_iterative - start_iterative;
        cout << "\n";
        cout << "Iterative function execution time: " << elapsed_iterative.count() << " seconds" << endl;
        cout << "\n";
        cout << "Reduced Row Echelon Form (Iterative): " << endl;
        printMatrix(matrix);
        printSolvedLinearSystem(matrix);

        //Profile recursive function
        auto start_recursive = high_resolution_clock::now();
        findReducedRowEchelonFormRec(matrix2, 0, 0);
        auto end_recursive = high_resolution_clock::now();
        duration<double> elapsed_recursive = end_recursive - start_recursive;
        cout << "\n";
        cout << "Recursive function execution time: " << elapsed_recursive.count() << " seconds" << endl;
        cout << "\n";
        cout << "Reduced Row Echelon Form (Recursive): " << endl;
        printMatrix(matrix2);
        printSolvedLinearSystem(matrix2);

    } else if (choice == 1) {
        vector<double> iterative_times;
        vector<double> recursive_times;
        cout << "Enter limit for rapid fire test: ";
        cin >> limit;
        cout << endl;
        // Run tests multiple times
        for (int i = 5; i <= limit; i++) {
            
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

    
    // vector<double> iterative_times;
    // vector<double> recursive_times;
    
    // // Run tests multiple times
    // for (int i = 5; i <= 100; i++) {
    //     vector<vector<float>> matrix2;
    //     vector<vector<float>> matrix = createDummyMatrix(i, i+1);
    //     matrix2.assign(matrix.begin(), matrix.end());

    //     auto start_iterative = high_resolution_clock::now();
    //     findReducedRowEchelonForm(matrix);
    //     auto end_iterative = high_resolution_clock::now();
    //     iterative_times.push_back(duration<double>(end_iterative - start_iterative).count());

    //     auto start_recursive = high_resolution_clock::now();
    //     findReducedRowEchelonFormRec(matrix2, 0, 0);
    //     auto end_recursive = high_resolution_clock::now();
    //     recursive_times.push_back(duration<double>(end_recursive - start_recursive).count());
    // }

    // saveDataToFile(iterative_times, recursive_times);
    // plotData();

    // return 0;
}

