#include <bits/stdc++.h>
using namespace std;

string methods[6] = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};

struct node{
	
	int a, b;
	int from_idx;
	int from_method;
	
};

int A, B, N;
int used[1001][1001];
node que[1000005];

void trace(int idx){
	
	node cur = que[idx];
	
	if(cur.from_idx != -1){
		
		trace(cur.from_idx);
		
	}
	
	if(cur.from_method != -1)
		cout << methods[cur.from_method] << "\n";
	
}

int bfs(){
	
	que[0].a = 0;
	que[0].b = 0;
	que[0].from_idx = -1;
	que[0].from_method = -1;
	used[0][0] = true;
	
	int i, j;
	node cur;
	node nxt;
	
	for(i=0, j=1;i<j;i++){
		
		cur = que[i];
		
		if(cur.a == N || cur.b == N){
			
			return i;
			
		}
		
		// fill A
		if(cur.a < A && !used[A][cur.b]){
			
			nxt = cur;
			nxt.a = A;
			nxt.from_idx = i;
			nxt.from_method = 0;
			
			used[A][cur.b] = true;
			que[j++] = nxt;
			
		}
		
		//fill B
		if(cur.b < B && !used[cur.a][B]){
			
			nxt = cur;
			nxt.b = B;
			nxt.from_idx = i;
			nxt.from_method = 1;
			
			used[cur.a][B] = true;
			que[j++] = nxt;
			
		}
		
		//empty A
		if(cur.a != 0 && !used[0][cur.b]){
			
			nxt = cur;
			nxt.a = 0;
			nxt.from_idx = i;
			nxt.from_method = 2;
			
			used[0][cur.b] = true;
			que[j++] = nxt;
			
		}
		
		//empty B
		if(cur.b != 0 && !used[cur.a][0]){
			
			nxt = cur;
			nxt.b = 0;
			nxt.from_idx = i;
			nxt.from_method = 3;
			
			used[cur.a][0] = true;
			que[j++] = nxt;
			
		}
		
		//pour A B
		if(cur.a != 0 && cur.b < B){
			
			nxt = cur;
			int after_b = min(cur.b+cur.a, B);
			nxt.a -= after_b - cur.b;
			nxt.b = after_b;
			nxt.from_idx = i;
			nxt.from_method = 4;
			
			if(!used[nxt.a][nxt.b]){
				
				used[nxt.a][nxt.b] = true;
				que[j++] = nxt;
				
			}
			
		}
		
		//pour B A
		if(cur.b != 0 && cur.a < A){
			
			nxt = cur;
			int after_a = min(cur.b+cur.a, A);
			nxt.b -= after_a - cur.a;
			nxt.a = after_a;
			nxt.from_idx = i;
			nxt.from_method = 5;
			
			if(!used[nxt.a][nxt.b]){
				
				used[nxt.a][nxt.b] = true;
				que[j++] = nxt;
				
			}
			
		}
		
	}
	
	return -1;
}

int main(){
	
	while(cin >> A >> B >> N){
		
		memset(used, false, sizeof(used));
		
		int last = bfs();
		
		trace(last);
		cout << "success\n";
		
	}
	
	return 0;
}