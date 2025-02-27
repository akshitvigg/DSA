#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N , prev_t = 0 , prev_x =0 , prev_y=0;
  cin >> N;

  while (N--){
    int t ,x ,y;
    cin >> t >> x >> y;

    int dist = abs(x - prev_x) + abs(y - prev_y);
    int time_available = t - prev_t;

    if(dist > time_available || (time_available - dist ) % 2 !=0){
      cout << "No" << endl;
      return 0;
    }

    prev_t = t , prev_x = x, prev_y = y;
  }
  cout << "Yes" << endl;
  return 0;
}
