#include <iostream>
using namespace std;

int main() {

  char s[100];

  cin >> s;

  int cnt = 0;

  for (char c : s) {
    if (c == '1') {
      cnt++;
    }
  }
  cout << cnt << endl;

  return 0;
}
