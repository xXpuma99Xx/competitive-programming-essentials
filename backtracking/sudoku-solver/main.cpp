#include <iostream>

#define SUDOKU_SIZE 9

using namespace std;

void print_mat(int mat[][SUDOKU_SIZE]) {
  for (int i = 0; i < SUDOKU_SIZE; i++) {
    for (int j = 0; j < SUDOKU_SIZE; j++)
      cout << mat[i][j] << " ";
    cout << endl;
  }
}

bool can_place(int mat[][SUDOKU_SIZE], int i, int j, int no) {
  int sx = (i / 3) * 3;
  int sy = (j / 3) * 3;

  for (int x = sx; x < sx + 3; x++)
    for (int y = sy; y < sy + 3; y++)
      if (mat[x][y] == no)
        return false;
  for (int k = 0; k < SUDOKU_SIZE; k++)
    if (mat[k][j] == no || mat[i][k] == no)
      return false;
  return true;
}

bool solve_sudoku(int mat[][SUDOKU_SIZE], int i, int j) {
  if (i == SUDOKU_SIZE) {
    print_mat(mat);
    return true;
  }
  if (j == SUDOKU_SIZE)
    return solve_sudoku(mat, i + 1, 0);
  if (mat[i][j] != 0)
    return solve_sudoku(mat, i, j + 1);
  for (int no = 1; no <= SUDOKU_SIZE; no++) {
    if (can_place(mat, i, j, no)) {
      mat[i][j] = no;
      if (solve_sudoku(mat, i, j + 1))
        return true;
      mat[i][j] = 0;
    }
  }
  return false;
}

int main() {
  int mat[SUDOKU_SIZE][SUDOKU_SIZE] = {
      {5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0},
      {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3},
      {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
      {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5},
      {0, 0, 0, 0, 8, 0, 0, 7, 9}};

  solve_sudoku(mat, 0, 0);
  return 0;
}
