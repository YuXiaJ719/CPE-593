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

        Bucket(){present = false;}
        Bucket(key k, value v) : k(k), v(v), present(true){}
        Bucket(key k) : k(k), present(true){}
           
    };
    
    Bucket* table;
    uint32_t size;
    uint32_t used;

    uint32_t hash(uint32_t k){
        // k = (k+0x7ed55d16) + (k<<12);
        // k = (k^0xc761c23c) ^ (k>>19);
        // k = (k+0x165667b1) + (k<<5);
        // k = (k+0xd3a2646c) ^ (k<<9);
        // k = (k+0xfd7046c5) + (k<<3);
        // k = (k^0xb55a4f09) ^ (k>>16);
        return k % 101;
    }

public:
    HashMapLinearProbing(uint32_t initialized_size=1024):size(initialized_size), used(0){
        table = new Bucket[size];
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
        
    ~HashMapLinearProbing(){
        delete [] table;
    }
    
    void grow(uint32_t grow_size){
        Bucket* temp = table;
        table = new Bucket[grow_size];

        for(int i = 0; i < size; i++){
            if(temp[i].present){
                int id = hash(temp[i].k);
                table[id] = new Bucket(temp[i].k, temp[i].v);
            }
        }

        delete [] temp;
        size = grow_size;
    }
    
    void add(key k){
        if(size < 2 * used)
            grow(2*size);

        uint32_t id = hash(k);

        while(table[id].present){
            id++;
            if(id >= size)
                id = 0;
        }

        table[id] = new Bucket(id);
        used++;
    }

    uint32_t getSize(){
        return size;
    }
};


int main(){
    HashMapLinearProbing<uint32_t, int> map;
    // cout << map.getSize() << endl;
    for(int i = 0; i < 100000; i++)
        map.add(i);
}
