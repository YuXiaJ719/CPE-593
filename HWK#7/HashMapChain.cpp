#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#define A 39751 /* a prime */
#define B 895932 /* another prime */
#define SEED 97 /* also prime */

class HashMapChain{
private:
	class Bucket{
	public:
		string key;
		double v;
		bool present;
		Bucket(const string& str, int value) : key(str), v(value), present(true){}
		Bucket(const string& str) : key(str), present(true){}
		Bucket():present(false){}
	};

	vector<Bucket*>* table;

	uint32_t size;
	uint32_t used;

	uint32_t hash(const string& str){
		uint32_t ret = SEED;
		size_t len = str.length();

		for(size_t i = 0; i < len; i++)
			ret = ((ret * A) ^ (str[i] * B)) >> 13;
   		return ret % size;
	}

public:
	HashMapChain(uint32_t initialized_size=5000):size(initialized_size), used(0){
		table = new vector<Bucket*>[size];
	}

	~HashMapChain(){
		delete [] table;
	}

	void grow(){
		vector<Bucket*>* temp = table;
		table = new vector<Bucket*>[2 * size];

		for(uint32_t i = 0; i < size; i++){
			size_t len = temp[i].size();
			if(len != 0){
				for(size_t j = 0; j < len; j++){
					Bucket* t = temp[i][j];
					uint32_t id = hash(t->key);
					Bucket* newBucket = new Bucket(t->key);
					table[id].push_back(newBucket);
				}
			}
		}

		size *= 2;
		delete [] temp;
	}

	void add(const string& str){
		if(size < used * 1.4)
			grow();

		uint32_t id = hash(str);
		Bucket* newBucket = new Bucket(str);
		table[id].push_back(newBucket);

		used++;
	}

	bool find(const string& str){
		uint32_t id = hash(str);
		vector<Bucket*> v = table[id];

		for(size_t i = 0; i < v.size(); i++){
			if(v[i]->key == str)
				return true;
		}

		return false;

	}
	
	uint32_t getSize(){
		return size;
	}

	void printHist(){
		int arr[60] = {0};

		for(uint32_t i = 0; i < size; i++){
			size_t len = table[i].size();
			arr[len]++;
		}

		for(int i = 0; i <= 50; i++)
			cout << "Size of " << i << ": " << arr[i] << endl;
	}

	void printKey(){
		for(uint32_t i = 0; i < size; i++){
			vector<Bucket*> v = table[i];

			for(int i = 0; i < v.size(); i++)
				cout << v[i]->key << endl;
		}
	}
};



int main(){
	HashMapChain m;
	ifstream f("dict.txt");

	string temp;
	while(!f.eof()){
		getline(f, temp);
		m.add(temp);
	}
	
	m.printHist();
}