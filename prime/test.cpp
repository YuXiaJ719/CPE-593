#include <iostream>
using namespace std;

typedef long int lint;
int sumDigits(lint num){
	int sum = 0;
	while(num != 0){
		sum += num % 10;
		num = num / 10;
	}

	return sum;
}

int main(){
	for(lint i = 7; i < 10000000000000000; i+=10){
		cout << i << endl;
	}
}