#include<iostream>
using namespace std;

struct Linked_list{
	
	const int N = 200005;
	
	const int END = -1;
	
	const int HEAD = 0;
	
	int elem[200005];
	
	int nxt[200005];
	
	int pt = 1; // 儲存下一個沒有使用過的編號為何
	
	
	void init(){
		
		pt = 1;
		
		nxt[HEAD] = END;
		
	}
	
	void travel(){
		
		bool first = true;
		
		for(int cur = nxt[HEAD] ; cur != END ; cur = nxt[cur]){
			
			if(!first)
				cout << ", ";
				
			cout << elem[cur];
			first = false;
			
		}
		
		cout << "\n";
		
	}
	
	int get(int idx){
		
		int i, cur;
		
		for(i=-1, cur=HEAD;i<idx;i++, cur=nxt[cur]);
		
		return cur;
		
		
	}
	
	void remove(int idx){
		
		int pre = get(idx - 1);
		
		int cur = nxt[pre];
		
		nxt[pre] = nxt[cur];
		
	}
	
	int gen_node(const int &data, int next){
		
		int cur = pt;
		
		pt++;
		
		elem[cur] = data;
		nxt[cur] = next;
		
		return cur;
		
	}
	
	void insert(int idx, const int &data){
		
		int pre = get(idx-1);
		
		int novice = gen_node(data, nxt[pre]);
		
		nxt[pre] = novice;
		
	}
	
};

int main(){
	
	
	return 0;
}