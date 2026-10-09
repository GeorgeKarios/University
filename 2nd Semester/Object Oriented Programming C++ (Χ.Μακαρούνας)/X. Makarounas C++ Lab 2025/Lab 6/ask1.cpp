#include <iostream>
using namespace std;
#define L 12

class magicSquare {
public:
    magicSquare(){
        while (N > 10) {
            cout << "input size N (10 and under): ";
            cin >> N;
        }
        cout << "give magic square numbers" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
                while (check[matrix[i][j]] != 0 || matrix[i][j] > (N * N)) {
                    cout << "error give this number again" << endl;
                    cin >> matrix[i][j];
                }
                check[matrix[i][j]]++;
            }
        }
    }

    void calc() {
        bool ans = true;
        // Use mgcSUM for the magic-sum variable
        int mgcSUM = N * (N*N + 1) / 2;

        // Accumulate partial sums row by row, stopping if any sum goes above mgcSUM
        for (int i = 0; i < N && ans; i++) {
            for (int j = 0; j < N && ans; j++) {
                sumoflines[i] += matrix[i][j];
                sumofcols[j]  += matrix[i][j];
                
                if (i == j) {
                    sumD1 += matrix[i][j];
                }
                if (i == N - 1 - j) {
                    sumD2 += matrix[i][j];
                }

                // If any partial sum exceeds mgcSUM, remember (i,j) and stop
                if (sumoflines[i] > mgcSUM ||
                    sumofcols[j]   > mgcSUM ||
                    (i == j && sumD1       > mgcSUM) ||
                    (i == N - 1 - j && sumD2 > mgcSUM))
                {
                    ans  = false;
                    Ni = i;
                    Nj = j;
                }
            }
        }

        // If a partial sum exceeded mgcSUM, report and return
        if (!ans) {
            cout << "IS NOT MAGIC SQUARE, FIRST ERROR FOUND IN ROW "
                 << Ni << " COLUMN " << Nj << endl;
            return;
        }

        // Otherwise, check final sums == mgcSUM
        if (sumD1 != mgcSUM || sumD2 != mgcSUM) {
            ans = false;
        }
        for (int i = 0; i < N && ans; i++) {
            if (sumoflines[i] != mgcSUM) {
                ans = false;
            }
            if (sumofcols[i]  != mgcSUM) {
                ans = false;
            }
        }

        if (ans) {
            cout << "IS MAGIC SQUARE" << endl;
        } else {
            cout << "IS NOT MAGIC SQUARE, FINAL SUMS DONT MATCH" << endl;
        }
    }

    void prnt() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << matrix[i][j] << " ";
            
            cout << endl;
        }
    }

private:
    int N = 11;
    int matrix[L][L], check[L*L] = {0};
    int sumD1 = 0, sumD2 = 0;
    int sumofcols[L]   = {0};
    int sumoflines[L]  = {0};
    int Ni, Nj;
};

void calculate_sums(int diag1, int diag2, int sumoflines[], int sumofcols[]) {
    // not used in this snippet
}

int main() {
    // IMPORTANT: parentheses would declare a function!
    magicSquare try1;  
    try1.calc();
    prnt();
    return 0;
}
