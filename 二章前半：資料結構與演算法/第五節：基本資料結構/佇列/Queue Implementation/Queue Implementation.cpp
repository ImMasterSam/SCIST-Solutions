#include<iostream>
using namespace std;


struct que{
	
	const int NOT_EXIST = -1;
	
	int head=0, tail=0;
	
	int qq[1024];
	
	bool is_empty(){
		return head == tail;
	}
	
	int length(){
		return tail - head;
	}
	
	void clear(){
		head = 0;
		tail = 0;
	}
	
	void enqueque(int data){
		qq[tail++] = data;
	}
	
	int dequeque(){
		
		int res = NOT_EXIST;
		if(!is_empty()){
			res = qq[head++];
		}
		return res;
	}
	
}q;

int main(){
	
	q.enqueque(1);
	q.enqueque(2);
	q.enqueque(5);
	
	cout << q.dequeque() << "\n";
	cout << q.dequeque() << "\n";
	cout << q.dequeque() << "\n";
	
	return 0;
}