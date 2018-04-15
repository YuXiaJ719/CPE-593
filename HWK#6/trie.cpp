/*
 Author: Yu Xia
 Date: 03/22/2018
 */
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
    
    // Insert vocabularies from "hw5.txt" into Trie structure
    ifstream f("dict.txt");
    char word[256];
    while(!f.eof()){
        f.getline(word, 256);
        if(word[0] == '\n')
            continue;
        t.insert(word);
    }
    f.close();
    
    // Check if each word in "hw5.txt" can be found in Trie Structure
    ifstream f2("hw5.txt");
    while(!f2.eof()){
        f2.getline(word, 256);
        // If any word is not in Trie, print it out
        if(t.search(word))
            cout << "Word: " << word << "--True." << endl;
        else
            cout << "Word: " << word << ": False" << endl;
        
        if(t.containsPrefix(word))
            cout << "Prefix: " << word << "--True" << endl;
        else
            cout << "Prefix: " << word << "--False" << endl;
    }
    
    f2.close();
    return 0;
}
