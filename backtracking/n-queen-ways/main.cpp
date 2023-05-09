#include <iostream>

using namespace std;

#define BOARD_LENGTH 20

void print_board(int n, int board[][BOARD_LENGTH]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

bool can_place(int n, int board[][BOARD_LENGTH], int x, int y) {
  for (int k = 0; k < x; k++)
    if (board[k][y])
      return false;

  int i = x - 1;
  int j = y - 1;

  while (i >= 0 and j >= 0) {
    if (board[i][j])
      return false;
    i--;
    j--;
  }
  i = x - 1;
  j = y + 1;
  while (i >= 0 and j < n) {
    if (board[i][j])
      return false;
    i--;
    j++;
  }
  return true;
}

int solve_n_queen(int n, int board[][BOARD_LENGTH], int i) {
  if (n == i) {
    print_board(n, board);
    return 1;
  }

  int ways = 0;

  for (int j = 0; j < n; j++) {
    if (can_place(n, board, i, j)) {
      board[i][j] = 1;
      ways += solve_n_queen(n, board, i + 1);
      board[i][j] = 0;
    }
  }
  return ways;
}

int main() {
  int board[BOARD_LENGTH][BOARD_LENGTH] = {0};
  int n = 8;

  cout << solve_n_queen(n, board, 0) << endl;
  return 0;
}
