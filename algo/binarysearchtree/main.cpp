//
//  main.cpp
//  binarysearchtree
//
//  Created by Yu Xia on 3/26/18.
//  Copyright © 2018 Yu Xia. All rights reserved.
//

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
            if(left != nullptr)
                delete left;
            if(right != nullptr)
                delete right;
        }
    };
    Node* root;
    
public:
    binarysearchtree():root(nullptr){}
    ~binarysearchtree(){
        delete root;
    }
    
    void add(double val){
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
            
            if(p->val < temp->val)
                temp->left = p;
            else
                temp->right = p;
        }
    }
    
    void printInorder(){
        Node* p = root;
        
        while(p->left != nullptr){
            p = p->left;
        }
        
        if(p->right != nullptr)
            cout << p->right->val;
        
        cout << p->val;
        while(p != root){
            p = p->parent;
            cout << p->val;
            if(p->right != nullptr && p != root)
                cout << p->right->val;
        }
        
        while(p->right != nullptr){
            p = p->right;
            if(p->left != nullptr)
                cout << p->left->val;
            cout << p->val;
        }
        
        cout << endl;
    }
    
};

int main(){
    binarysearchtree bst;
    bst.add(20);
    bst.add(18);
    bst.add(6);
    bst.add(19);
    bst.add(13);
    bst.add(100);
    
    bst.printInorder();
}










