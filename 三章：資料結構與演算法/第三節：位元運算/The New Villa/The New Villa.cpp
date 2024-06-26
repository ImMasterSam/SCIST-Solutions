#include <bits/stdc++.h>
using namespace std;

struct node{
	
	int pos;
	int step;
	int light;
	int last;
	int method;
	
};

int r, d, s;
bool side[12][12];
int but[12] = {0};
bool used[12][1025];
node q[1000000];

void trace(int idx){
	
	node cur = q[idx];
	
	if(cur.last != -1){
		
		trace(cur.last);
		
	}
	
	if(cur.last != -1){
		
		if(cur.method == 999)
			cout << "- Move to room " << cur.pos << ".\n";
		else{
			
			if((1 << cur.method) & cur.light)
				cout << "- Switch on light in room " << cur.method << ".\n";
			else
				cout << "- Switch off light in room " << cur.method << ".\n";
			
		}
		
	}
	
}

int bfs(){
	
	node cur;
	node nxt;
	
	cur.pos = 1;
	cur.step = 0;
	cur.light = 2;
	cur.last = -1;
	cur.method = -1;
	
	q[0] = cur;
	used[0][0] = true;
	
	int i, j;
	
	for(i=0, j=1; i<j; i++){
		
		cur = q[i];
		
		if(cur.pos == r && cur.light == (1 << r)){
			
			cout << "The problem can be solved in " << cur.step << " steps:\n";
			return i;
			
		}
		
		// light switch
		for(int k=1;k<=10;k++){
			
			int button = (1 << k);
			
			if(k == cur.pos || !(but[cur.pos] & button))
				continue;
			
			nxt = cur;
			nxt.step++;
			nxt.last = i;
			nxt.method = k;
			nxt.light ^= button;
			
			if(!used[nxt.pos][nxt.light]){
				
				used[nxt.pos][nxt.light] = true;
				q[j++] = nxt;
				
			}
			
		}
		
		// walk
		for(int k=1;k<=10;k++){
			
			int next_light = (1 << k);
			
			if(k == cur.pos || !(cur.light & next_light) || !side[cur.pos][k])
				continue;
			
			nxt = cur;
			nxt.pos = k;
			nxt.step++;
			nxt.last = i;
			nxt.method = 999;
			
			if(!used[nxt.pos][nxt.light]){
				
				used[nxt.pos][nxt.light] = true;
				q[j++] = nxt;
				
			}
			
		}
		
	}
	
	return -1;
	
}

int main(){
	
	int time = 1;
	
	while(cin >> r >> d >> s){
		
		if(r==0&&d==0&&s==0)
			break;
			
		memset(side, false, sizeof side);
		memset(used, false, sizeof used);
		memset(but, 0, sizeof but);
		
		for(int i=0, a, b;i<d;i++){
			
			cin >> a >> b;
			side[a][b] = side[b][a] = true;
			
		}
		
		for(int i=0, k, l;i<s;i++){
			
			cin >> k >> l;
			but[k] |= (1 << l);
			
		}
		
		cout << "Villa #" << time++ << "\n";
		
		int res = bfs();
		
		if(res == -1)
			cout << "The problem cannot be solved.\n";
		else
			trace(res);
			
		cout << "\n";
		
	}
	
	return 0;
}