#include<iostream>
#include<cstdlib>
#include<cctype>
using namespace std;

struct Linked_list{
	
	const int N = 200000;
	
	const int END = -1;
	
	const int HEAD = 0;
	
	string elem[200000];
	
	int nxt[200000];
	
	int pt = 1;
	
	
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
		
	}
	
	void get(int idx){
		
		int i, cur;
		
		for(i=-1, cur=HEAD;i<idx;i++, cur=nxt[cur]);
		
		cout << elem[cur];
		
		remove(elem[cur]);
		insert(elem[cur]);
		
	}
	
	void remove(string data){
		
		int cur = nxt[HEAD];
		int pre = HEAD;
		bool found = false;
		
		while(cur != END && !found){
			
			if(elem[cur] == data){
				
				found = true;
				
				nxt[pre] = nxt[cur];
				
			}
			
			pre = cur;
			cur = nxt[cur];
			
		}
		
	}
	
	int gen_node(string data, int next){
		
		int cur = pt;
		
		pt++;
		
		elem[cur] = data;
		nxt[cur] = next;
		
		return cur;
		
	}
	
	void insert(const string &data){
		
		//remove(data);
		
		int novice = gen_node(data, nxt[HEAD]);
		
		nxt[HEAD] = novice;
		
	}
	
} list;

int main(){
	
	list.init();
	
	string s;
	
	while(getline(cin, s)){
		
		if(s == "0")
			break;
			
		string word = "";
		int n = 0;
		
		for(int i=0;i<(int)s.size();i++){
			
			if(isalpha(s[i])){
				
				cout << s[i];
				word += s[i];
				
			}
			
			else if(isdigit(s[i])){
				
				n = n*10 + (s[i] - '0');
				
			}
			
			else{
				
				if(word != ""){
					
					list.insert(word);/*
					cout << "\n";
					list.travel();
					
					cout << "\n\n";*/
					
					word = "";
					
				}
				
				if (n){
				
					//cout << "N: " << n << "\n";
					
					list.get(n-1);
					
					n = 0;
					
				}
				
				cout << s[i];
				
			}
			
		}
		
		if(n){
			
			list.get(n-1);
			
		}
		
		if(word != ""){
			
			list.insert(word);/*
			cout << "\n";
			list.travel();
			
			cout << "\n\n";*/
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}