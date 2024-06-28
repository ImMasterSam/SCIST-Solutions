#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int parents[2005] = {0};
int rnk[2005] = {0};

void init(){
	
	memset(parents, -1, sizeof parents);
	memset(rnk, -1, sizeof rnk);
	
}

int getRoot(int cur){
	
	if(parents[cur] == -1){
		
		return cur;
		
	}
	
	return parents[cur] = getRoot(parents[cur]);
	
}

void merge(int a, int b){
	
	a = getRoot(a);
	b = getRoot(b);
	
	if(a != b){
		
		if(rnk[a] < rnk[b])
			swap(a, b);
			
		parents[a] = b;
		
		if(rnk[a] == rnk[b])
			rnk[b]--;
		
	}
	
}

bool query(int a, int b){
	
	return getRoot(a) == getRoot(b);
	
}

int main(){ BOOST

	int t;
	cin >> t;
	
	bool first = true;
	
	while(t--){
		
		if(!first)
			cout << "\n";
		
		init();
		
		int n;
		cin >> n;
		cin.ignore();
		
		string buffer;
		char op;
		int a, b;
		
		int YES = 0;
		int NO = 0;
		
		while(getline(cin, buffer)){
			
			if(buffer == "") break;
			
			stringstream ss;
			ss << buffer;
			ss >> op >> a >> b;
			//cout << op << " " << a << " " << b << "\n";
			
			switch(op){
				
				case 'c':
					merge(a, b);
					break;
				case 'q':
					if(query(a, b))
						YES++;
					else
						NO++;
					break;
					
				
			}
			
		}
		
		cout << YES << "," << NO << "\n";
			
		first = false;
		
	}
	
	return 0;
}
