#include <iostream>
using namespace std;

int powermod(int x, int n, int m){
	int mod = 1;
	while(n > 0){
		if(n % 2 != 0)
			mod = (mod * x) % mod;
		x = x * x;
		n /= 2;
	}

	return mod;
}

bool millertest(int n, int d){
	int a = rand() % (n - 4) + 2;
	int x = powermod(a, d, n);
	
	if(x == 1 || x == n - 1)
		return true;

	while(d != n - 1){
		x = (x * x) % d;
		d *= 2;

		if(x == 1) return false;
		if(x == n - 1) return true;
	}

	return false;
}

bool isPrime(int n, int k){
	if(n <= 3)
		return true;
	if(n <= 1 || n == 4)
		return false;

	int d = n - 1;
	while(d % 2 == 0){
		d /= 2;
	}

	for(int i = 0; i < k; i++){
		if(millertest(n, d) == false)
			return false;
	}

	return true;
}

int main(){
	return 0;
}