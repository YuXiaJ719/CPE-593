#include <iostream>
using namespace std;

class magicSqure{
private:
    int* s;
    int n;
    
    void print(){
        int c = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < n; j++, c++)
                cout << s[c] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    
    void generate(int N){
        if(N == 0)
            print();

        for(int i = 0; i < N; i++){
            generate(N - 1);
            swap(N % 2 != 0 ? s[0] : s[i], s[N]);
        }
    }
    
public:
    magicSqure(int n) : n(n){
        s = new int[n * n];
        
        for(int i = 0; i < n * n; i++){
            s[i] = i + 1;
        }
        generate(n * n - 1);
    }
};


int main(){
    magicSqure m(4);
}
