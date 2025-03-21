#include <iostream>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  for (char &c : s1) {
    c = tolower(c);
  }
  for (char &c : s2) {
    c = tolower(c);
  }

  if (s1 < s2)
    cout << -1 << endl;
  else if (s1 > s2)
    cout << 1 << endl;
  else
    cout << 0 << endl;
}
