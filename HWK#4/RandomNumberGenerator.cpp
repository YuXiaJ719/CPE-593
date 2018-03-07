#include <iostream>
#include <stdlib.h> 
#include <fstream>

using namespace std;

int main(){
	int x, y;
	ofstream f("convexhullpoints.dat");
	for(int i = 0; i < 1000; i++){
		x = rand() % 200 - 100;
		y = rand() % 300 - 150;
		f << x << ' ' << y << '\n';
	}

	return 0;
}