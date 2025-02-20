#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A, B, C, X;

  cin >> A >> B >> C >> X;

  int count = 0;

  for (int i = 0; i <= A; i++) {
    for (int j = 0; j <= B; j++) {
      int remaining = X - (i * 500 + j * 100);

      if (remaining >= 0 && remaining % 50 == 0 && remaining / 50 <= C) {
        count++;
      }
    }
  }
  cout << count << endl;

  return 0;
}
