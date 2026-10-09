#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void generateRandomArray(int N, int nums[][50]) {
    int tmp[N][N];
    for (int i = 0; i < N * N; ++i){
        nums[i] = i;
    }
    srand(time(NULL));
    for (int i = 0; i < N * N; ++i) {
        int randIndex = rand() % (N * N);
        int temp = nums[randIndex];
        nums[randIndex] = nums[i];
        nums[i] = temp;
    }
    int index = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tmp[i][j] = nums[index++];
    }
}

void displayPuzzle(int N, int nums[][50]){ 
    cout << "Puzzle Grid:\n";
    for (int i = 0; i < N; i++ ) {
        for (int j = 0; j < N; j++)
        if (nums[i][j] == 0)
            cout << "  "; //blank
        else
            cout << nums[i][j] << " ";
        cout << endl;
    }
}

bool isSolved(int N, int nums[][50]) {
    int expected = 1; 
    for (int i = 0; i < N * N - 1; i++) {
        if (nums[i / N][i % N] != expected++) 
            return false;
    }
    return nums[N - 1][N - 1] == 0;
}

void play(int N, int nums[][50]) {
    int x, y;
    
    // Find the blank (0) position
    for (int i = 0; i < N * N; i++) {
        if (nums[i / N][i % N] == 0) {
            x = i / N, y = i % N;
            break;
        }
    }

    while (!isSolved(N, nums)) {
        displayPuzzle(N, nums);

        cout << "Move (U/D/L/R): ";
        char move;
        cout<< "Move> ";
        cin >> move;
        while (move != 'u' && move != 'd' && move != 'r' && move != 'l' &&
            move != 'U' && move != 'D' && move != 'R' && move != 'L') {
            cout<< "This is not a valid move\n";
            cin>> move;
            }

        int nx = x, ny = y;
        if (move == 'U' || move == 'u') nx--;
        else if (move == 'D' || move == 'd') nx++;
        else if (move == 'L' || move == 'l') ny--;
        else if (move == 'R' || move == 'r') ny++;
        else continue; // Ignore invalid input

        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            swap(nums[x][y], nums[nx][ny]);
            x = nx, y = ny;
        }
    }

    cout << "Congratulations! You solved the puzzle!\n";
}


int main() {
    int N, nums[50][50];
    cout << "Enter N: ";
    cin >> N;
    generateRandomArray(N, nums);
    displayPuzzle(N, nums);
    return 0;
}
