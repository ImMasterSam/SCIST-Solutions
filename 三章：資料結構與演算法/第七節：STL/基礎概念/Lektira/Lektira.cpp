#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	string s;
	cin >> s;
	
	vector<string> heap;
	
	for(int i=1;i<s.size();i++){
		
		for(int j=i+1;j<s.size();j++){
			
			string a = s.substr(0, i);
			string b = s.substr(i, j-i);
			string c = s.substr(j, s.size()-j);
			
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			reverse(c.begin(), c.end());
			
			heap.push_back(a+b+c);
						
		}
		
	}
	
	sort(heap.begin(), heap.end());
	cout << heap[0] << "\n";
	
	return 0;
}
