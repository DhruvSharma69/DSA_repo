#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int n, vector<vector<int>> &chess) {
    // Row check
    for (int i = 0; i < col; i++) {
        if (chess[row][i] == 1)
            return false;
    }

    // Diagonal up-left check
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (chess[i][j] == 1)
            return false;
    }

    // Diagonal down-left check
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (chess[i][j] == 1)
            return false;
    }

    return true;
}

void solve(vector<vector<int>> &chess, int n, int col) {
    if (col == n) {
        // All queens are successfully placed, print the chessboard
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << chess[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, n, chess)) {
            chess[row][col] = 1;
            solve(chess, n, col + 1);
            chess[row][col] = 0; // Backtrack
        }
    }
}

void NQueens(int n) {
    vector<vector<int>> chess(n, vector<int>(n, 0)); // A chess vector with NxN initialized with 0
    solve(chess, n, 0);
}

int main() {
    int n = 4;
    NQueens(n);
    return 0;
}
