#include <iostream>
using namespace std;

int gcd(int a, int b){
	int temp;
	while(b!=0){
		temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

int main(){
	int a = gcd(65, 87);
	cout << a << endl;
	return 0;
}