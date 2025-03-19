#include <iostream>
#include <string>
using namespace std;
 
int main() {
 
	int n, x= 0;
	cin >> n;
 
	while ( n--){
		string statement; 
		cin >> statement;
 
		if(statement.find("+") != string::npos){
			x++;
		}else{
			x--;
		}
	}
	cout << x;
