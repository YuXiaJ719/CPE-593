#include <iostream>
#include <string>
#include <stdio.h>
#include <random>
using namespace std;

typedef unsigned long int lint;
lint powermod(lint x, lint n, lint m){
	lint mod = 1;
	while(n > 0){
		if((n % 2) != 0)
			mod = (mod * x) % m;
		x = (x * x) % m;
		n /= 2;
	}

	return mod;
}

bool millertest(lint d, lint x, lint a){
	lint mod = powermod(a, d, x);
	if(mod == 1 || mod == x - 1)
		return true;

	while(d != x - 1){
		mod = (mod * mod) % x;
		d *= 2;

		if(mod == 1)
			return false;
		if(mod == x - 1)
			return true;
	}
	return false;
}

bool isPrime(lint x, lint k = 128){
	if(x <= 1 || x == 4)
		return false;
	if(x <= 3)
		return true;
	if(x % 2 == 0)
		return false;

	lint d = x - 1;

	while(d % 2 == 0)
		d /= 2;

	for(int i = 0; i < k; i++){
		default_random_engine gen;
		uniform_int_distribution<lint> distribution(2, x - 2);
		lint a = distribution(gen);
		if(millertest(d, x, a) == false)
			return false;
	}
	return true;
}

int sumDigits(lint num){
	int sum = 0;
	while(num != 0){
		sum += num % 10;
		num = num / 10;
	}

	return sum;
}

lint countPrimes(lint start, lint end, int* arr){
	lint count = 0;
	start = (start / 10) * 10 + 7;
	for(lint i = start; i < end; i += 10){
		cout << "count: " << count << endl;
		if(arr[sumDigits(i)] == 0)
			count++;
			continue;
		if(isPrime(i) == false)
			continue;
	}

	return count;
}

inline int* cache(){
	lint size = 150;
	int* arr = new int[size];
	for(int i = 0; i < size; i++)
		arr[i] = 1;

	for(int j = 4; j < size; j+=2)
		arr[j] = 0;

	for(int i = 3; i < size; i++){
		if(arr[i] == 1){
			for(int j = i*i; j < size; j+= 2*i)
					arr[j] = 0;
		}
	}

	return arr;
}

int main(int argc, char* argv[]){
	lint start = stod(argv[1]);
	lint end = stod(argv[2]);
	int* memory = cache();
	cout << "Finish cache!" << endl;
	// lint counts = countPrimes(start, end, memory);
	// cout  << counts << endl;
	delete [] memory;
	return 0;
}


