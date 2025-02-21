#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, Y;
  
  cin >> n >> Y; 

  for (int x = 0; x <= n; x++ ){
    for (int y = 0; x + y <=n; y++){
      int z = n - x - y;

      if(10000* x + 5000 * y + 1000 * z == Y){
        cout << x << " " << y << " " << z << endl;
        return 0;      
      }
    }
    
  }

  cout << "-1 -1 -1" << endl;
  
  
  return 0;
}
