#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

struct node{
	
	string key;
	string value;
	int left, right;
	bool erased;
	
};

node pool[100005];
int root = 1, pp = 1;

void insert(string k, string t, int &pos){
	
	if(!pos){
		
		pos = pp++;
		pool[pos].key = k;
		pool[pos].value = t;
		pool[pos].left = pool[pos].right = 0;
		pool[pos].erased = false;
		return;
		
	}
	
	if(k < pool[pos].key){
		
		insert(k, t, pool[pos].left);
		
	}
	else{
		
		insert(k, t, pool[pos].right);
		
	}
	
}

string find(string k, int &pos){
	
	if(!pos){
		
		return "eh";
		
	}
	
	if(pool[pos].key == k && !pool[pos].erased){
		
		return pool[pos].value;
		
	}
	
	if(k < pool[pos].key){
		
		return find(k, pool[pos].left);
		
	}
	else{
		
		return find(k, pool[pos].right);
		
	}
	
}

int main(){ BOOST

	string buffer;
	
	while(getline(cin, buffer)){
		
		if(buffer == "") break;
		
		stringstream ss;
		string t, k;
		ss << buffer;
		ss >> t >> k;
		
		root = 1;
		insert(k, t, root);
		
	}
	
	string input;
	while(cin >> input){
		
		root = 1;
		cout << find(input, root) << "\n";
		
	}
	
	
	return 0;
}
