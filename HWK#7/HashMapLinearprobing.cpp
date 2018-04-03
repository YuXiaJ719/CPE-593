#include <iostream>
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
        return capacity;
    }
    
    uint32_t used;
    uint32_t capacity;
    Bucket *table[];
    
public:
    HashMapLinear(uint32_t capacity=1) : capacity(capacity), used(0), table(new Bucket*[capacity]){
        for(int i = 0; i < capacity; i++){
            table[i] = new Bucket();
        }
    }
    
    HashMapLinear(const HashMapLinear& orig):used(orig.used), capacity(orig.capacity){
        for(uint32_t i = 0; i < used; i++){
            if(orig.table[i]->present){
                Bucket* temp = orig.table[i];
                table[i] = new Bucket(temp->key, temp->value);
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
    
    ~HashMapLinear(){
        delete [] table;
    }
    
    void grow(){
        Bucket** temp = table;
        table = new Bucket*[capacity*2];
        for(uint32_t i = 0; i < used; i++){
            if(temp[i]->present){
                uint32_t id = hash(temp[i]->key);
                Bucket* newBucket= new Bucket(temp[i]->key);
                table[id] = newBucket;
            }
        }
        delete [] temp;
        capacity *= 2;
    }
    
    void add(int key){
        if(capacity < 2 * used + 1)
            grow();
        
        uint32_t id = hash(key);

        while(table[id]->present){
            id++;
            if(id >= capacity)
                id = 0;
        }
        table[id] = new Bucket(key);
        used++;
    }
    
    void add(int key, int value){
        if(capacity < 2 * used + 1)
            grow();

        uint32_t id = hash(key);
        cout << id << endl;
        while(table[id]->present){
            id++;
            if(id >= capacity)
                id = 0;
        }
        
        table[id] = new Bucket(key, value);
        used++;
    }
};

int main(){
    HashMapLinear m;
    for(int i = 0; i < 10; i++)
        m.add(i);
}
