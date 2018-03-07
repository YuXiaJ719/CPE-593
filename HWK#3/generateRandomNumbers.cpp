#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


int main(int argc, char* argv[]){
	int n = atoi(argv[1]);
	int count = 0;

	ofstream File;
	File.open("numbers.txt");
	srand(18);

	File << n << '\n';
	while(count <= n){
		File << rand() % 10000 - 4000 << ' ';
		count++;
	}
	
	cout << "Done!\n";
	File.close();
	return 0;
}