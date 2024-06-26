#include<iostream>
#include<queue>
using namespace std;

int main(){
	
	int n;
	
	while(cin >> n, n){
		
		queue<int> q;
		
		for(int i=1;i<=n;i++)
			q.push(i);
			
		bool first = true;
		
		cout << "Discarded cards:";
		
		while(q.size()>1){
			
			int x = q.front();
			
			if(!first)
				cout << ",";
			
			cout << " " << x;
			first = false;
			
			q.pop();
			
			if(q.size()>1)
				q.push(q.front()), q.pop();
			
		}
		
		cout << "\nRemaining card: " << q.front() << "\n";
		q.pop();
		
	}
	
	
	return 0;
}