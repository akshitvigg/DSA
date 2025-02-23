#include <iostream>
#include <vector>
using namespace std;

int main() {

  string s; 
  cin >> s;

   for(char c : s){
     if (c == '2'){
       cout << 2;
     }
   }
  return 0;
}
