#include <iostream>
using namespace std;

class GrowArray{
private:
    int* data;
    int capacity;
    int used;

public:
    GrowArray() : data(new int[1]), capacity(1), used(0){}
    GrowArray(int initializedSize) : data(new int[initializedSize]), capacity(initializedSize), used(0){}
    
    void addEnd(int val){
        if(capacity == used){
            int* temp = data;
            capacity *= 2;
            data = new int[capacity];
            copy(temp, temp+used, data);
            delete [] temp;
        }
        data[used] = val;
        used++;
    }
    
    void addStart(int val){
        int* temp = data; // 创建临时array
        
        if(capacity == used){
            capacity *= 2;
            data = new int[capacity];
        }else{
            data = new int[capacity];
        } // 创建新的array
        
        for(int i = 1; i < used + 1; i++){
            data[i] = temp[i - 1];
        } // 将临时array里的值赋给新的data array
        
        data[0] = val; // 将val放入array的第一个值
        used++;
        delete []  temp;
    }
    
    void insert(int val, int pos){
        int* temp = data;
        
        if(capacity == used){
            capacity *= 2;
            data = new int[capacity];
        }else{
            data = new int [capacity];
        }
        
        data[pos] = val;
        used++;
        
        for(int i = 0; i < pos; i++)
            data[i] = temp[i];
        for(int i = pos + 1; i < used; i++)
            data[i] = temp[i - 1];
        
        delete [] temp;
    }
    
    void print(){
        for(int i = 0; i < used; i++){
            cout << data[i] << " ";
        }
        cout << '\n';
    }
};

int main(){
    GrowArray g;
    g.addEnd(1);
    g.addStart(3);
    for(int i = 0; i < 10; i++)
        g.addStart(i);
    g.insert(100, 6);
    g.print();
}
