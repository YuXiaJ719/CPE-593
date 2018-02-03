#include <iostream>
#include <string>
using namespace std;

void prt(string a){
	cout << a[0] << endl;
}

int main(){
	string s1("My name is xiayu!");
	for(auto c: s1)
		cout << c;
	cout << endl;
}