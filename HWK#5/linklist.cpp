#include <iostream>
using namespace std;

class LinkedList{
private:
	class Node{
	public:
		double val;
		Node* next;
		Node* prev;
		Node(double val, Node* n= nullptr, Node* p = nullptr) : val(val), next(n), prev(p){}
	};
	int size;
	Node* head;
	Node* tail;

public:
	LinkedList():head(), tail(), size(0){}
	~LinkedList(){
		for(Node* pt = head; pt != nullptr;){
			Node* temp = pt;
			pt = pt->next;
			delete temp;
		}
	}

	void addFirst(double v){
		if(size == 0){
			Node* temp = new Node(v, nullptr, nullptr);
		    head = temp;
		    tail = head;
		}else{
			Node* temp = new Node(v, head, nullptr);
			head->prev = temp;
			head = temp;
		}
		size++;
	}

	void addLast(double v){
		if(size == 0){
			Node* temp = new Node(v, nullptr, nullptr);
			head = temp;
			tail = head;
		}else{
			Node* temp = new Node(v, nullptr, tail);
			tail->next = temp;
			tail = temp;
		}
		size++;
	}

	void removeFirst(){
		if(size == 0)
			cout << "No data to delete" << '\n';
		else if(size == 1){
			delete head;
			head = tail = nullptr;
		}
		else{
			Node* temp = head;
			head = head->next;
			head->prev = nullptr;
			delete temp;
		}
		size--;
	}

	void removeLast(){
		if(size == 0)
			cout << "No data to delete" << '\n';
		else if(size == 1){
			delete tail;
			tail = head = nullptr;
		}
		else{
			Node* temp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete temp;
		}
		size--;
	}

	void insert(double v, int pos){
		if(pos > size - 1){
			cout << "Out of index" << '\n';
		}else{
			Node* p = head;
			for(int i = 0; i < pos;i++)
				p  = p->next;
			Node* temp = new Node(v, p->next, p);
		}
		size++;
	}

	bool isEmpty(){
		return head == nullptr;
	}
	
	void print(){
		if(size == 0){
			cout << "This is a empty list." << '\n';
			return;
		}

		Node* p = head;
		for(; p->next!=nullptr;p = p->next){
			cout << p->val << ',';
		}
		cout << p->val << '\n';
	}
};