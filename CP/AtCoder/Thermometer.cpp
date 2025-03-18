#include <iostream>
using namespace std;

int main(){
  float x; 
  cin >> x;

  if (x < 37.5 ){
    cout << 3;
  }else if (x >= 37.5 && x < 38.0){
    cout << 2;
  }else {
    cout << 1;
  }
  
}
