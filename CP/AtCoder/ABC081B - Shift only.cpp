#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int main() {

  int n;

  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int min_cnt = INT_MAX;

  for (int i = 0; i < n; i++) {
    int cnt = 0;
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      cnt++;
    }
    min_cnt = min(cnt, min_cnt);
  }
  cout << min_cnt;

  return 0;
}
