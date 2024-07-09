#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
queue<int> buffer;

int main(){ BOOST

	int q;
	cin >> q;
	
	for(int que=0;que<q;que++){
		
		int p, x;
		cin >> p;
		
		switch(p){
			
			case 1:
				cin >> x;
				buffer.push(x);
				break;
			case 2:
				if(!pq.size()){
					
					cout << buffer.front() << "\n";
					buffer.pop();
					
				}
				else{
					
					cout << pq.top() << "\n";
					pq.pop();
					
				}
				break;
			case 3:
				while(buffer.size()){
					
					pq.push(buffer.front());
					buffer.pop();
					
				}
				break;
			
		}
		
	}
	
	return 0;
}
