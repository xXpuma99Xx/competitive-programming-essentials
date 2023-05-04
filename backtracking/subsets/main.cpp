#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

void findSubset(char *input, char *output, int i, int j) {
  if (input[i] == '\0') {
    output[j] = '\0';
    if (output[0] == '\0')
      cout << "null" << endl;
    cout << output << endl;
    return;
  }
  output[j] = input[i];
  findSubset(input, output, i + 1, j + 1);
  findSubset(input, output, i + 1, j);
}

int main() {
  char input[] = "abcd";
  char output[1000];

  findSubset(input, output, 0, 0);
  return 0;
}
