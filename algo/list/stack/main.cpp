#include <iostream>
#include "LinkedList.hh"
using namespace std;


class stack{
private:
	LinkedList lkl;

public:
	void add(double val){
		lkl.addLast(val);
	}
	double pop(){
		return lkl.removeLast();
	}
};

int main(){
	stack s;
	s.add(3);
	s.add(10);
}