#include <iostream>
#include <vector>
using namespace std;

class HashMapLinear{
private:
    class Bucket{
    public:
        bool present;
        int key;
        double value;
        
        Bucket(){present=false;}
        Bucket(int key):key(key), present(true){}
        Bucket(int key, int value):key(key), value(value), present(true){}
        
        ~Bucket(){}
    };
    
    uint32_t hash(int key){
        return (key * 97) % capacity;
    }
    
    uint32_t used;
    uint32_t capacity;
    vector<Bucket> table;
    
public:
    HashMapLinear(uint32_t capacity=1) : capacity(capacity), used(0), table(vector<Bucket>(capacity)){}
    
    HashMapLinear(const HashMapLinear& orig):used(orig.used), capacity(orig.capacity){
        for(uint32_t i = 0; i < used; i++){
            if(orig.table[i].present){
                Bucket temp = orig.table[i];
                Bucket* newBucket = new Bucket(temp.key, temp.value);
                table[i] = *newBucket;
            }
        }
    }
    
    HashMapLinear operator =(const HashMapLinear& orig){
        HashMapLinear copy(orig);
        used = orig.used;
        capacity = orig.capacity;
        swap(copy.table, table);
        
        return *this;
    }
    
    ~HashMapLinear(){}
    
    void grow(){
        vector<Bucket> temp = table;
        vector<Bucket> doubleSizeTable(2*capacity);

        for(uint32_t i = 0; i < used; i++){
            if(temp[i].present){
                uint32_t id = hash(temp[i].key);
                Bucket* newBucket= new Bucket(temp[i].key);
                doubleSizeTable[id] = *newBucket;
            }
        }
        table = doubleSizeTable;
        capacity *= 2;
    }
    
    void add(int key){
        if(capacity < 2 * used + 1)
            grow();
        
        uint32_t id = hash(key);

        while(table[id].present){
            id++;
            if(id >= capacity)
                id = 0;
        }
        
        Bucket* newBucket =new Bucket(key);
        table[id] = *newBucket;
        used++;
    }
    
    uint32_t getUsed(){
        return used;
    }
    
    uint32_t getCapacity(){
        return capacity;
    }
    
friend ostream& operator<< (ostream& s, const HashMapLinear& m){
        for(uint32_t i = 0; i < m.used; i++){
            cout << '\n';
            if(m.table[i].present)
                cout << m.table[i].key << endl;
        }
        return s;
    }
};


int main(){
    HashMapLinear m;
    
    for(int i = 0; i < 10; i++)
        m.add(i);
//    cout << m.getUsed() << endl;
//    cout << m.getCapacity() << endl;
    cout << m << endl;
}





