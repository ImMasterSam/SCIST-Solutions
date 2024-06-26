#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

const int NOT_EXIST = -1;

int main(){ BOOST

	int k;
	cin >> k;
	
	int a, b;
	string buffer;
	
	vector<int> parent(105, NOT_EXIST);
	
	while(cin >> a){
		
		if(a == -1) break;
		
		getline(cin, buffer);
		const char *ptr = buffer.c_str();
		int pos;
		
		while(sscanf(ptr, "%d%n", &b, &pos) != EOF){
			
			parent[b] = a;
			ptr += pos;
			
		}
		
	}
	
	while(k != NOT_EXIST){
		
		cout << k << " ";
		k = parent[k];
		
	}
	
	return 0;
}
