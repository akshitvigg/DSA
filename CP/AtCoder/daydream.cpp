#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s; 
  cin >>s ;

  string words[] = {"dream" , "dreamer" , "erase" , "eraser"};

  while(!s.empty()){
    bool found = false;

    for(string word : words){
      if(s.size() >= word.size() && s.substr(s.size() - word.size()) == word ){
        s.erase(s.size() - word.size());
        found = true;
        break;
      }
    }
    if(!found ){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  
   
  return 0;
}
