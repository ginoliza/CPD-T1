#include <iostream>
#include <algorithm>
#include <array>
#include <time.h>
#include <stdlib.h>
#include <chrono>

using namespace std;

#define MAX 16000

double A[MAX][MAX], x[MAX], y[MAX];

int main()
{    
    srand(time(NULL));    
    // ASIGNAR A = random
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            int num = rand();
            A[i][j] = num;
        }
    }

    // ASIGNAR X = random
    for (int i = 0; i < MAX; i++) {
        int num = rand();
        x[i] = num;
    }

    // ASIGNAR y = 0
    for (int i = 0; i < MAX; i++) {
        y[i] = 0;
    }

    // IMPRIMIR
    /*
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cout << A[i][j] << endl;
        }
    }
    */

    // i, j
    auto inicio = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    auto fin = std::chrono::high_resolution_clock::now();
    double total = std::chrono::duration<double, std::milli>(fin - inicio).count();
    cout << "i, j: " << total << "\n";

    // ASIGNAR y = 0
    for (int i = 0; i < MAX; i++) {
        y[i] = 0;
    }

    // j, i
    inicio = std::chrono::high_resolution_clock::now();

    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }

    fin = std::chrono::high_resolution_clock::now();
    total = std::chrono::duration<double, std::milli>(fin - inicio).count();
    cout << "j, i: " << total << "\n";

    return 0;
}