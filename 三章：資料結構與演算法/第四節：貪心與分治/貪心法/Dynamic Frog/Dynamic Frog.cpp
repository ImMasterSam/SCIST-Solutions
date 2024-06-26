#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int t;
	cin >> t;
	
	for(int time=0;time<t;time++){
		
		int n, d;
		cin >> n >> d;
		
		cin.ignore();
		
		vector<char> stone;
		vector<int> pos;
		
		string s;
		getline(cin, s);
		
		const char *ptr = s.c_str();
		char rock;
		int position;
		int p = 0;
		
		while(sscanf(ptr, "%c-%d %n", &rock, &position, &p) != EOF){
			
			stone.push_back(rock);
			pos.push_back(position);
			
			ptr += p;
			
		}
		
		stone.push_back('B');
		pos.push_back(d);
		
		int maxA = 0, maxB = 0;
		int A = 0, B = 0;
		
		for(int i=0;i<n+1;i++){
			
			if(stone[i] == 'B'){
				
				maxA = max(maxA, pos[i]-A);
				maxB = max(maxB, pos[i]-B);
				
				A = pos[i];
				B = pos[i];
				
			}
			
			else if (stone[i] == 'S'){
				
				if(A <= B){
					
					maxA = max(maxA, pos[i]-A);
					A = pos[i];
					
				}
				
				else{
					
					maxB = max(maxB, pos[i]-B);
					
					B = pos[i];
					
				}
				
			}
			
		}
		
		cout << "Case " << time+1 << ": " << max(maxA, maxB) << "\n";
		
	}
	
	
	return 0;
}