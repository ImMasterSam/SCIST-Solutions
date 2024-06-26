#include<iostream>
#include<queue>
using namespace std;

int main(){
	
	int n, x;
	int time = 1;
	
	while(cin >> n >> x){
		
		int cards[20];
		
		for(int i=0;i<20;i++)
			cin >> cards[i];
			
		int idx = 0;
		
		queue<int> A, T;
		
		for(int i=1;i<=n;i++){
			A.push(i);
		}
		
		while(A.size() > x && idx < 20){
			
			int k = cards[idx++];
			
			while(A.size()){
				
				int t = k;
				
				while(A.size() && t>1){
					
					T.push(A.front());
					A.pop();
					
					t--;
					
				}
				
				if(A.size()){
					
					//cout << "Kick: " << A.front() << "\n";
					A.pop();
					
				}
				
				if(A.size() + T.size() <= x)
					break;
					
				
			}
				
			while(T.size()){
				
				A.push(T.front());
				T.pop();
				
			}
			
		}
		
		cout << "Selection #" << time++ << "\n";
		
		int flag[100] = {0};
		
		while(A.size()){
			
			flag[A.front()] = 1;
			A.pop();
			
		}
		
		bool first = true;
		
		for(int i=1;i<=55;i++){
			
			if(flag[i]){
				
				if(!first)
					cout << " ";
				
				first = false;
				cout << i;
				
			}
			
		}
		cout << "\n\n";
		
	}
	
	
	return 0;
}