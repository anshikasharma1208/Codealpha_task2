#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
const int N = 9;

void printGrid(vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {  
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }
  
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Using backtracking
bool sudokusolver(vector<vector<int>>& grid) {
    int row = -1;
    int col = -1;
    bool isEmpty = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    if (isEmpty) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (sudokusolver(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }

    return false;
}
// User input for Sudoku puzzle
void takeInput(vector<vector<int>>& grid) {
    cout << "Enter the Sudoku puzzle (use 0 to represent empty cells and put space in between):\n";
    for (int i = 0; i < N; i++) {
        cout << "Row " << i + 1 << ": ";
        string line;
        getline(cin, line);
        istringstream iss(line);
        for (int j = 0; j < N; j++) {
            iss >> grid[i][j];
        }
    }
}
int main() {
    vector<vector<int>> grid(N, vector<int>(N, 0));
    takeInput(grid);

    cout << "\n || Enter Sudoku puzzle to solve: ||\n";
    printGrid(grid);

    if (sudokusolver(grid)) {
        cout << "\n Sudoku solved : \n";
        printGrid(grid);
    } else {
        cout << "\n No solution exists :( \n";
    }

    return 0;
}
