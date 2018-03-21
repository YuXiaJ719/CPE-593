#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class TRIE{
private:
    class Node{
    public:
        Node* alphabet[26] = {};
        bool isWord = false;
    };
    Node* root;
    
public:
    TRIE():root(new Node()){}
    ~TRIE(){
        delete root;
    }
    void insert(const char* word){
        Node* p = root;
        int letterIndex;
        int size = (int)strlen(word);
        for(int i = 0; i < size; i++){
            letterIndex = word[i] - 'a';
            if(p->alphabet[letterIndex] == nullptr){
                p->alphabet[letterIndex] = new Node();
            }
            p = p->alphabet[letterIndex];
        }
        p->isWord = true;
    }
    
    bool search(const char* word){
        Node* p = root;
        int letterIndex;
        int size = (int)strlen(word);
        for(int i = 0; i < size; i++){
            letterIndex = word[i] - 'a';
            if(p->alphabet[letterIndex] == nullptr)
                return false;
            p = p->alphabet[letterIndex];
        }
        return p->isWord;
    }
    
    bool containsPrefix(const char* prefix){
        Node* p = root;
        int letterIndex;
        int size = (int)strlen(prefix);
        for(int i = 0; i < size; i++){
            letterIndex = prefix[i] - 'a';
            if(p->alphabet[letterIndex] == nullptr)
                return false;
            p = p->alphabet[letterIndex];
        }
        return true;
    }
};

int main(){
    TRIE t;
    ifstream f("hw5.txt");
    char word[256];
    while(!f.eof()){
        f.getline(word, 256);
        if(word[0] == '\n')
            continue;
        t.insert(word);
    }
    
    char* str1 = (char*)"aardvark";
    char* str2 = (char*)"auramine";
    char* str3 = (char*)"djfdask";
    char* str4 = (char*)"sads";
    char* str5 = (char*)"djsk";

    cout << str1 << ": " << t.search(str1) << endl;
    cout << str2 << ": " << t.search(str2) << endl;
    cout << str3 << ": " << t.search(str3) << endl;
    cout << str4 << ": " << t.search(str4) << endl;
    cout << str5 << ": " << t.search(str5) << endl;
    cout << "aal" << ": " << t.containsPrefix("aal") << endl;
    return 0;
}










