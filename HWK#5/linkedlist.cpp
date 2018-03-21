/*
	Author: Yu Xia
	Date: 3/2/2018
*/

#include <iostream>
#include <fstream>
#include <string>
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
        if(size == 0){
			cout << "No data to delete" << '\n';
            return;
        }
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
        if(size == 0){
			cout << "No data to delete" << '\n';
            return;
        }
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
            return;
		}else{
			Node* p = head;
			for(int i = 0; i < pos;i++)
				p  = p->next;
			Node* temp = new Node(v, p, p->prev);
            p->prev = temp;
            temp->prev->next = temp;
            
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

class fileReader{
private:
	ifstream f;
	LinkedList list;

public:
	fileReader(string fileName){
		f.open(fileName);
	}
	~fileReader(){
		f.close();
	}

	void add_front(double start, double step, double end){
		for(double i = start; i <= end; i+=step){
			list.addFirst(i);
		}
	}

	void add_back(double start, double step, double end){
		for(double i = start; i <= end; i+=step){
			list.addLast(i);
		}
	}

	void output(){
		list.print();
	}

	void remove_front(int num){
		for(int i = 0; i < num; i++)
			list.removeFirst();
	}

	void remove_back(int num){
		for(int i = 0; i < num;i++)
			list.removeLast();
	}

	static string LowerString(char arr[], int n){
		int i = 0; char c;
		while(arr[i]){
			arr[i] = tolower(arr[i]);
			i++;
		}
		string s(arr);
		return s;
	}

	void excute(){
		char c_char[256];
		double start, step, end;
		int number;
		string::size_type index, size;
		
		while(!f.eof()){
			index = 0;
			f.getline(c_char, 256);
			string s = LowerString(c_char, 256);
			while(c_char[index] != ' ' && c_char[index]){
				index++;
			}
			string command = s.substr(0, index);
			while(c_char[index] && c_char[index] == ' '){
				index++;
			}
			string p = s.substr(index);
			if(command == "add_front" || command == "add_back"){
				
				start = stod(p, &size);
				p = p.substr(size + 1);
				step = stod(p, &size);
				p = p.substr(size + 1);
				end = stod(p, &size);

				int condi = (command == "add_back") * 1;
				switch(condi){
					case 0 :	
						add_front(start, step, end);
						break;
					case 1:
						add_back(start, step, end);
						break;
				}
				
			}else if(command == "remove_front"){
				number = stoi(p);
				remove_front(number);
			}else if(command == "remove_back"){
				number = stoi(p);
				remove_back(number);
			}else if(command == "output"){
				output();
			}
		}
	}
};


int main(){
	fileReader fr("HW4b.txt");
	fr.excute();
	return 0;
}
