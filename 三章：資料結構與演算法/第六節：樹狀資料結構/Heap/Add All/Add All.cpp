#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int n;
long long heap[5005];

void shift_down(int pos){
	
	int left, right, nxt;
	while(pos <= n){
		
		left = (pos << 1);
		right = (left | 1);
		
		if(left > n) break;
		
		nxt = left;
		
		if(right <= n && heap[right] < heap[left]){
			
			nxt = right;
			
		}
		
		if(heap[pos] <= heap[nxt]) break;
		
		swap(heap[pos], heap[nxt]);
		pos = nxt;
		
	}
	
}


void shift_up(int pos){
	
	int parent;
	
	while(pos > 1){
		
		parent = (pos >> 1);
		
		if(heap[pos] >= heap[parent]) break;
		
		swap(heap[pos], heap[parent]);
		pos = parent;
		
	}
	
}

void build(){
	
	for(int i=n;i>=1;i--){
		
		shift_down(i);
		
	}
	
}

int pop(){
	
	int top = heap[1];
	heap[1] = heap[n];
	
	n--;
	
	shift_down(1);
	
	return top;
	
}

void push(int val){
	
	n++;
	
	heap[n] = val;
	shift_up(n);
	
}

int main(){ BOOST

	while(cin >> n, n){
		
		for(int i=1;i<=n;i++)
			cin >> heap[i];
			
		build();
		
		long long ans = 0;
		
		while(n >= 2){
			
			int a = pop();
			int b = pop();
			
			push(a+b);
			
			ans += a+b;
			
			
		}
		
		cout << ans << "\n";
		
	}
	
	return 0;
}
