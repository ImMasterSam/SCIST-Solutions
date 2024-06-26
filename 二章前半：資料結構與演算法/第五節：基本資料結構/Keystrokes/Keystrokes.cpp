#include<iostream>
using namespace std;

struct Linked_list{
	
	const int N = 1000005;
	
	const int END = -1;
	
	const int HEAD = 0;
	
	char elem[1000005];
	
	int nxt[1000005];
	int pre[1000005];
	
	int pt = 1;
	
	int ptr = HEAD;
	
	void init(){
		
		pt = 1;
		
		ptr = HEAD;
		nxt[HEAD] = END;
		pre[HEAD] = END;
		
	}
	
	void travel(){
		
		for(int cur = nxt[HEAD] ; cur != END ; cur = nxt[cur]){
				
			cout << elem[cur];
			
		}
		
		cout << "\n";
		
	}
	/*
	int get(int idx){
		
		int i, cur;
		
		for(i=-1, cur=HEAD;i<idx;i++, cur=nxt[cur]);
		
		return cur;
		
		
	}*/
	
	void Left(){
		
		if(pre[ptr] != END)
			ptr = pre[ptr];
		
	}
	
	void Right(){
			
		if(nxt[ptr] != END)
			ptr = nxt[ptr];
		
	}
	
	void backspace(){
		
		int previous = pre[ptr];
		
		nxt[previous] = nxt[ptr];
		
		ptr = previous;
		
	}
	
	int gen_node(const char &data, int next, int previous){
		
		int cur = pt;
		
		pt++;
		
		elem[cur] = data;
		nxt[cur] = next;
		pre[cur] = previous;
		
		return cur;
		
	}
	
	void type(const char &data){
		
		//int previous = pre[ptr];
		
		int novice = gen_node(data, nxt[ptr], ptr);
		
		nxt[ptr] = novice;
		
		ptr = novice;
		
	}
	
} list;

int main(){
	
	list.init();
	
	string s;
	
	getline(cin, s);
	
	for(int i=0;i<(int)s.size();i++){
		
		if(s[i] == 'L')
			list.Left();
			
		else if(s[i] == 'R')
			list.Right();
		
		else if(s[i] == 'B')
			list.backspace();
		
		else
			list.type(s[i]);
		
	}
	
	list.travel();
	
	
	return 0;
}