#include<iostream>
using namespace std;

struct que{
	
	const int NOT_EXIST = -1;
	
	int head=0, tail=0;
	
	int qq[10240];
	
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
	
}a, b;

int main(){
	
	int n, c;
	cin >> n;
	
	for(int i=0;i<n;i++){
		
		while(!a.is_empty() && !b.is_empty()){
			a.dequeque();
			b.dequeque();
		}
		
		cin >> c;
		
		if(a.is_empty()){
			for(int t=0;t<c;t++){
				a.enqueque(1);
			}
			
			cout << i << " ";
		}
		
		else if(b.is_empty()){
			for(int t=0;t<c;t++){
				b.enqueque(1);
			}
		}
		
	}
	
	
	return 0;
}