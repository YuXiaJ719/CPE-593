#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<double> readVec(string fileName){
	int n;
	double a;
	vector<double> v;

	ifstream f(fileName, ios_base::in);
	f >> n;

	while(!f.eof()){
		f >> a;
		v.push_back(a);
	}

	return v;
}

void swap(vector<double> &vec, int i, int j){
	double temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}

double max(double a, double b){
	return (a > b) ? (a) : (b);
}

void heapify(vector<double> &vec, int n, int i){
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	if(left < n && vec[left] > vec[largest])
		largest = left;
	if(right < n && vec[right] > vec[largest])
		largest = right;

	if(largest != i){
		swap(vec, i, largest);
		heapify(vec, n, largest);
	}
}

void heapsort(vector<double> &vec, int n){
	for(int i = n / 2 - 1; i >= 0; i--){
		heapify(vec, n, i);
	}

	for(int i = n - 1; i >= 0; i-- ){
		swap(vec, 0, i);
		heapify(vec, i, 0);
	}
}

int main(){
	vector<double> vec = readVec("heapsort.txt");
	auto s = vec.size();

	heapsort(vec, s);

	for(double d: vec)
		cout << d << ' ';

	cout << endl;
	return 0;
}