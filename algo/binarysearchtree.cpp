#include <iostream>
using namespace std;

class binarysearchtree{
private:
    class Node{
    public:
        double val;
        Node* parent;
        Node* left;
        Node* right;
        
        Node(double val, Node* parent=nullptr, Node* left=nullptr, Node* right=nullptr) : val(val), parent(parent), left(left), right(right){}
        ~Node(){
            delete parent;
            delete left;
            delete right;
        }
    };
    Node* root;

public:
    ~bst(){
        if(root != nullptr)
            delete root;
    }
    add(double val){
        if(root == nullptr)
            root = new Node(val);
        else{
            Node* p = root;
            Node* temp;
            while(p != nullptr){
                if(val < p->val){
                    temp = p;
                    p = p->left;
                }else{
                    temp = p;
                    p = p->right;
                }
            }
            p = new Node(val, temp);
        }
    }
}


int main(){
    binarysearchtree bst;
    bst.add(4);
    bst.add(5);
}
