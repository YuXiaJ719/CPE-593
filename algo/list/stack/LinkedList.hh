#pragma once 
#include <iostream>

class LinkedList{
private:
	class Node{
	public:
		double val;
		Node* next;
		Node* prev;
		Node(double v, Node* next, Node* prev) : val(v), next(next), prev(prev){}
	};
	int size;
	Node* head;
	Node* tail;
public:
	LinkedList();
	// ~LinkedList();
	void addFirst(double v);
	void addLast(double v);
	void insert(double v, int pos);
	double removeFirst();
	double removeLast();
	bool isEmpty();
	void print();
};