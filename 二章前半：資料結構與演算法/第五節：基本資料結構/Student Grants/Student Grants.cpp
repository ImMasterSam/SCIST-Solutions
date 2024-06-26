#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;

int main(){
	
	queue<int> q;
	
	int n, k;
	cin >> n >> k;
	int arr[27] = {0};
	
	
	while(n!=0 && k!= 0){
		
		for(int i=1;i<=n;i++){
			q.push(i);
			arr[i] = 0;
		}
		
		int cash = 1;
		
		while(q.size() > 0){
			
			int take = cash;
			
			while(take > 0){
				
				if(q.size() == 0)
					break;
				
				if(arr[q.front()] + take < 40){
					arr[q.front()] += take;
					take = 0;
					q.push(q.front());
					q.pop();
				}
				
				else{
					take -= 40 - arr[q.front()];
					cout << setw(3) << q.front();
					q.pop();
				}
			}
			/*
			cout << "[";			
			for(int i=1;i<=n;i++)
				cout << arr[i] << " ";
			cout << "]\n";*/
			
			cash = (cash%k)+1;
		}
		
		cin >> n >> k;
		
		cout << "\n";
	}
	
	
	return 0;
}