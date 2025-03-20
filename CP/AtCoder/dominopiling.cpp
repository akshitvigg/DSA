#include <iostream>
using namespace std;

int main() {

  int m, n;
  cin >> m >> n;

  int totsqr = m * n;

  if (totsqr % 2 == 0) {
    cout << totsqr / 2;
  } else {
    totsqr--;
    cout << totsqr / 2;
  }
}
