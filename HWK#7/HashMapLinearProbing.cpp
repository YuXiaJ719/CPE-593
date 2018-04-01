/*
 Author: Yu Xia
 Reference:
 */

#include <iostream>
using namespace std;

template<typename key, typename value>
class HashMapLinearProbing{
private:
    class Bucket{
    public:
        key k;
        value v;
        bool present;
        Bucket(){present = false;};
    };
    
    Bucket* table;
    int size;
    int used;
    // Waiting for defining
    uint32_t hash(const key& key){
        
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
    
    void grow(uint32_t size){
        Bucket* temp = table;
        
    }
    
    
    void add(key k){
        
    }
}
