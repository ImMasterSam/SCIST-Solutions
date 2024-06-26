#include<iostream>
#include<iomanip>
using namespace std;

struct linked_list{
	
	const int END = -1;
	
	const int HEAD = 0;
	const int TAIL = 25;
	
	int elem[30] = {0};
	
	int nxt[30];
	int pre[30];
	
	int pt = 1;
	
	
	void init(){
		
		pt = 1;
		
		nxt[HEAD] = END;
		pre[TAIL] = END;
		
	}
	
	void travel(){
		
		bool first = true;
		
		int idx = 0;
		
		for(int cur = nxt[HEAD]; idx<10 && cur != END ; idx++,  cur = nxt[cur]){
			
			if(!first)
				cout << ", ";
				
			cout << elem[cur];
			first = false;
			
		}
		
		cout << "\n";
		
	}
	
	int gen_node(const int &data, int next, int prev){
		
		int cur = pt;
		
		pt++;
		
		elem[cur] = data;
		
		nxt[cur] = next;
		pre[cur] = prev;
			
		return cur;
		
	}
	
	void generate(int n){
		
		int i;
		int front = HEAD;
		
		for(i=1;i<=n;i++){
			
			int novice = gen_node(i, nxt[front], pre[TAIL]);
			
			nxt[front] = novice;
			pre[TAIL] = novice;
			pre[nxt[HEAD]] = novice;
			
			if(nxt[novice] == END)
				nxt[novice] = nxt[HEAD];
				
			if(pre[novice] == END)
				pre[novice] = pre[TAIL];
			
			front = novice;
			
		}
		
	}
	
	void remove(int ptr){
		
		if(ptr == nxt[ptr] && ptr == pre[ptr]){
			
			nxt[HEAD] = END;
			pre[TAIL] = END;
			
		}
		
		else{
			
			if(ptr == nxt[HEAD])
				nxt[HEAD] = nxt[ptr];
			
			nxt[pre[ptr]] = nxt[ptr];
			
			if(ptr == pre[TAIL])
				pre[TAIL] = pre[ptr];
			
			pre[nxt[ptr]] = pre[ptr];
			
		}
		
	}
	
	void pick(int n, int k, int m){
		
		bool first = true;
		
		int clock = nxt[HEAD];
		int counter = pre[TAIL];
		
		while(nxt[HEAD] != END && pre[TAIL] != END){
			
			cout << "\n" << nxt[HEAD] << " ___ " << pre[TAIL] << "\n";
			
			//travel();
			
			for(int i=0;i<k-1;i++)
				clock = nxt[clock];
			
			for(int i=0;i<m-1;i++)
				counter = pre[counter];
			
			
			cout << "[" << elem[clock] << " " << elem[counter] << "]\n";
				
			if(elem[clock] == elem[counter]){
				
				if(!first)
					cout << ",";
				
				cout << setw(3) << elem[clock];
				
				remove(clock);
				
				clock = nxt[clock];
				counter = pre[counter];
				
				cout << "\n" << nxt[HEAD] << " --- " << pre[TAIL] << "\n";
				
				first = false;
				
			}
			else{
				
				if(!first)
					cout << ",";
					
				cout << setw(3) << elem[clock];
				remove(clock);
				clock = nxt[clock];
						
				cout << setw(3) << elem[counter];
				remove(counter);
				if(clock == counter)
					clock = nxt[clock];
				counter = pre[counter];
				
				first = false;
				
			}
		}
		
		cout << "\n";
		
	}
	
} list ;

int main(){
	
	
	int n, k, m;
	
	while(cin >> n >> k >> m, n){
		
		list.init();
		
		list.generate(n);
		
		list.pick(n, k, m);
		
	}
	
	
	return 0;
}