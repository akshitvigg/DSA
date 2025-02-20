#include <iostream>
#include <vector>
using namespace std;

int sum_of_digits(int n) {
  int sum = 0;

  while (n != 0) {
    int last = n % 10;

    sum += last;

    n /= 10;
  }
  return sum;
}

int main() {

  int n, a, b;
  cin >> n >> a >> b;

  int sum = 0;

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    sum = sum_of_digits(i);
    if (sum >= a && sum <= b) {
      ans.push_back(i);
    }
  }
  int ans_sum = 0;
  for (size_t i = 0; i < ans.size(); i++) {
    ans_sum += ans[i];
  }
  cout << ans_sum;
  return 0;
}
