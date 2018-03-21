#include <iostream>
using namespace std;

int main(){
    bool* isPrime = new bool[100];
    for(int i = 1; i < 100; i+=2)
        isPrime[i] = 1;
    cout << isPrime[9] << endl;
    cout << isPrime[8] << endl;
    cout << isPrime[7] << endl;
    cout << isPrime[6] << endl;
    cout << isPrime[5] << endl;
    delete [] isPrime;
}
