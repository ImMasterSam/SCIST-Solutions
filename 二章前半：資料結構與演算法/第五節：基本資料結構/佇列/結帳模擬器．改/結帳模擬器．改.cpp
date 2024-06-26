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
	
}a, b, w;

int main(){
	
	int n, c;
	cin >> n;
	int arr[1000];
	
	for(int i=0;i<n;i++){
		cin >> c;
		w.enqueque(i);
		arr[i] = c;
	}
	
	while(!w.is_empty()){
		
		while(!a.is_empty() && !b.is_empty()){
			a.dequeque();
			b.dequeque();
		}
		
		if(a.is_empty()){
			for(int t=0;t<arr[w.qq[w.head]];t++){
				a.enqueque(1);
			}
			
			cout << w.dequeque() << " ";
		}
		
		else if(b.is_empty()){
			for(int t=0;t<arr[w.qq[w.head]];t++){
				b.enqueque(1);
			}
			
			int temp = w.dequeque();
			w.enqueque(temp);
		}
		
	}
	
	
	return 0;
}