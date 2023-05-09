#include <iostream>

using namespace std;

void find_subset(char *input, char *output, int i, int j) {
  if (input[i] == '\0') {
    output[j] = '\0';
    if (output[0] == '\0')
      cout << "null" << endl;
    cout << output << endl;
    return;
  }
  output[j] = input[i];
  find_subset(input, output, i + 1, j + 1);
  find_subset(input, output, i + 1, j);
}

int main() {
  char input[] = "abcd";
  char output[1000];

  find_subset(input, output, 0, 0);
  return 0;
}
