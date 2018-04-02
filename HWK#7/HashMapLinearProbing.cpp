/*
 Author: Yu Xia
 Reference:
 */

#include <iostream>
using namespace std;

class HashMapLinearProbing{
private:
    class Bucket{
    public:
        uint32_t k;
        uint32_t v;
        bool present;
        Bucket(){present = false;};
        Bucket(uint32_t k):k(k), present(true){}
    };
    
    Bucket* table;
    int size;
    int used;
    // Waiting for defining
    uint32_t hash(const uint32_t& key){
        return (key << 3 + key >> 4) % size;
    }
    
public:
    HashMapLinearProbing(uint32_t initialized_size):size(initialized_size){
        table = new Bucket[size];
    }
    
    ~HashMapLinearProbing(){
        delete [] table;
    }
    
    HashMapLinearProbing(const HashMapLinearProbing& orig):size(orig.size), used(orig.used){
        table = new Bucket[size];
        for(int i = 0; i < size; i++){
            if(orig.table[i].present)
                table[i] = orig.table[i];
        }
    }
    
    HashMapLinearProbing& operator =(const HashMapLinearProbing& orig){
        if(this != &orig){
            delete [] table;
            size = orig.size;
            used = orig.used;
            table = new Bucket[size];
            for(int i = 0; i < size; i++){
                if(orig.table[i].present)
                    table[i] = orig.table[i];
            }
        }
        
        return *this;
    }
    
    void grow(){
        Bucket* temp = table;
        table = new Bucket[2 * size];
        for(int i = 0; i < size; i++){
            if(temp[i].present){
                Bucket* t = temp[i];
                uint32_t id = hash(t->key);
                while(table[id].present){
                    id++;
                    if(id >= size)
                        id = 0;
                }
                table[id] = t;
            }
        }
    }
    
    void add(uint32_t k){
        if(size < 2 * used)
            grow();
        
        uint32_t id = hash(k);
        while(table[id].present){
            id++;
            if(id >= size)
                id = 0;
        }
        
        table[i] = new Bucket(k);
    }
    
    uint32_t getSize(){
        return size;
    }
};

int main(){
    HashMapLinearProbing m;
    for(uint32_t i = 0; i < 100000; i++)
        m.add(i);
    
    cout << m.getSize() << endl;
}
