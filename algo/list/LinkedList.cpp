#include <iostream>
#include "LinkedList.hh"
using namespace std;

class Node;
LinkedList::LinkedList():head(nullptr), tail(nullptr), size(0){}
LinkedList::~LinkedList(){
	for(Node* pt = head; pt != nullptr;){
		Node* temp = pt;
		pt = pt->next;
		delete temp;
	}
}

void LinkedList::addFirst(double v){
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

void LinkedList::addLast(double v){
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

double LinkedList::removeFirst(){
	if(size == 0){
		cout << "No data to delete" << '\n';
		return -1;
	}
	else if(size == 1){
		double d = head->data;
		delete head;
		head = tail = nullptr;
		return d;
	}
	else{
		Node* temp = head;
		double d = temp->data;
		head = head->next;
		head->prev = nullptr;
		delete temp;
		return d;
	}
	size--;
}

double LinkedList::removeLast(){
	if(size == 0){
		cout << "No data to delete" << '\n';
		return -1;
	}
	else if(size == 1){
		double d = tail->data;
		delete tail;
		tail = head = nullptr;
		return d
	}
	else{
		Node* temp = tail;
		double d = temp->data;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
		return d;
	}
	size--;
}

void LinkedList::insert(double v, int pos){
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

bool LinkedList::isEmpty(){
	return head == nullptr;
}
	
void LinkedList::print(){
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