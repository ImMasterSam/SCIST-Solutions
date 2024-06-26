#include<iostream>
using namespace std;

struct Linked_list{
	
	const int N = 100005;
	
	const int END = -1;
	
	const int HEAD = 0;
	
	char elem[100005];
	
	int nxt[100005];
	
	int pt = 1; // 儲存下一個沒有使用過的編號為何
	
	int ptr = HEAD;
	
	void init(){
		
		pt = 1;
		
		nxt[HEAD] = END;
		ptr = HEAD;
		
	}
	
	void Home(){
		
		ptr = HEAD;
		
	}
	
	void End(){
		
		while(nxt[ptr] != END)
			ptr = nxt[ptr];
		
	}
	
	void travel(){
		
		for(int cur = nxt[HEAD] ; cur != END ; cur = nxt[cur]){
				
			cout << elem[cur];
			
		}
		
		cout << "\n";
		
	}
	
	int gen_node(const int &data, int next){
		
		int cur = pt;
		
		pt++;
		
		elem[cur] = data;
		nxt[cur] = next;
		
		return cur;
		
	}
	
	void push(const char &data){
		
		int novice = gen_node(data, nxt[ptr]);
		
		nxt[ptr] = novice;
		
		ptr = novice;
		
	}
	
} list;

int main(){
	
	string s;
	
	while(getline(cin, s)){
		
		list.init();
		
		for(int i=0;i<(int)s.size();i++){
			
			if(s[i] == '[')
				list.Home();
			else if(s[i] == ']')
				list.End();
			else
				list.push(s[i]);
							
		}
		
		list.travel();
		
	}
	
	
	return 0;
}