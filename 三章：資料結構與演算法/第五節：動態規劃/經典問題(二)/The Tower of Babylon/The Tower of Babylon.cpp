#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b){
	
	if(a[0] != b[0])
		return a[0] > b[0];
	if(a[1] != b[1])
		return a[1] > b[1];
	
	return false;
	
}

int main(){ BOOST

	int n;
	int times = 0;
	
	while(cin >> n, n){
		
		cout << "Case " << ++times << ": ";
		vector<vector<int>> types;
		
		int arr[3];
		for(int i=0;i<n;i++){
			
			cin >> arr[0] >> arr[1] >> arr[2];
			
			for(int a=0;a<3;a++){
				
				for(int b=0;b<3;b++){
					
					if(b == a) continue;
					
					for(int c=0;c<3;c++){
						
						if(c == a || c == b) continue;
						
						vector<int> temp = {arr[a], arr[b], arr[c]};
						types.push_back(temp);
						
					}
					
				}
				
			}
			
		}
		
		sort(types.begin(), types.end(), cmp);
		
		vector<int> length (types.size());
		int MAX = 0;
		
		for(int i=0;i<types.size();i++){
			
			length[i] = types[i][2];
			MAX = max(MAX, length[i]);
			
		}
		
		while(1){
			
			bool found = false;
			
			for(int i=0;i<types.size();i++){
				
				for(int j=0;j<types.size();j++){
					
					if(types[i][0] < types[j][0] && types[i][1] < types[j][1]){
						
						if(length[j]+types[i][2] > length[i]){
							
							length[i] = length[j]+types[i][2];
							MAX = max(MAX, length[i]);
							found = true;
							
						}
						
					}
					
				}
				
			}
			
			if(!found)
				break;
			
		}
		
		cout << "maximum height = " << MAX << "\n";
		
	}
	
	return 0;
}
