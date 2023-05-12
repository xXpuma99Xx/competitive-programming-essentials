#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

int fibonacci(int n) {
  if (n == 1 || n == 0)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int dynamic_fibonacci(int n, vector<int> &dp) {
  if (n == 1 || n == 0)
    return n;
  if (dp[n] != 0)
    return dp[n];
  return dp[n] = dynamic_fibonacci(n - 1, dp) + dynamic_fibonacci(n - 2, dp);
}

void normal(int n) {
  auto start = high_resolution_clock::now();
  int r = fibonacci(n);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << r << endl;
  cout << duration.count() << "ms" << endl;
}

void dynamic(int n) {
  vector<int> dp(n + 1, 0);
  auto start = high_resolution_clock::now();
  int r = dynamic_fibonacci(n, dp);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << r << endl;
  cout << duration.count() << "ms" << endl;
}

int main() {
  int n = 20;

  dynamic(n);
  normal(n);
  return 0;
}
