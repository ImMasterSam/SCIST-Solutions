#include<iostream>
using namespace std;

struct Linked_list{
	
	const int N = 150;
	
	const int END = -1;
	
	const int HEAD = 0;
	
	int elem[150];
	
	int nxt[150];
	
	int pt = 1; // 儲存下一個沒有使用過的編號為何
	
	
	void init(){
		
		pt = 1;
		
		nxt[HEAD] = END;
		
	}
	
	void generate(int n){
		
		int cur = HEAD;
		int i = 1;
		
		while(i<=n){
			
			int novice = gen_node(i, nxt[cur]);
			
			nxt[cur] = novice;
			
			cur = novice;
			
			i++;
			
		}
		
		
	}
	
	void remove(int pre, int cur){
		
		if(cur == nxt[HEAD])
			nxt[HEAD] = nxt[cur];
		
		nxt[pre] = nxt[cur];
		
	}
	
	int gen_node(const int &data, int next){
		
		int cur = pt;
		
		pt++;
		
		elem[cur] = data;
		
		if(next == END)
			nxt[cur] = nxt[HEAD];
		else
			nxt[cur] = next;
		
		return cur;
		
	}
	
	bool power_cut(int n, int m){
		
		int pre = HEAD;
		for(int i=0;i<n;i++, pre = nxt[pre]);
		int cur = nxt[HEAD];
		
		while(nxt[cur] != cur){
			
			int ptr = cur;
			
			cur = nxt[cur];
			
			remove(pre, ptr);
			
			for(int i=0;i<m-1;i++){
				
				cur = nxt[cur];
				pre = nxt[pre];
				
			}
			
		}
		
		if(elem[cur] == 13)
			return true;
		else
			return false;
		
	}
	
} list ;

int main(){
	
	int n;
	
	while(cin >> n, n){
		
		int m = 1;
		
		while(1){
			
			list.init();
			list.generate(n);
			
			int res = list.power_cut(n, m++);
			
			if(res)
				break;
			
			
		}
		
		cout << m-1 << "\n";
		
	}
	
	
	return 0;
}