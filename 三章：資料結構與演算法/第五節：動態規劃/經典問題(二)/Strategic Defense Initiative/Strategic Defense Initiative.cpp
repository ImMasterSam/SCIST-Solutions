#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int arr[1000];

int main(){ BOOST

	int t;
	cin >> t;
	cin.ignore(2);
	
	bool first = true;
	
	while(t--){
		
		if(!first)
			cout << "\n";
		
		string input;
		stringstream ss;
		int n = 0;
		
		while(getline(cin, input)){
			
			if(input == "")
				break;
				
			ss.str("");
			ss.clear();
			
			ss << input;
			ss >> arr[n++];
			
		}
		
		vector<int> length (n, 1);
		vector<int> prev (n, -1);
		
		int maxIDX = 0;
		
		for(int i=0;i<n;i++){
			
			for(int j=i+1;j<n;j++){
				
				if(arr[j] > arr[i]){
					
					if(length[i]+1 > length[j]){
						
						length[j] = length[i]+1;
						
						if(length[j] > length[maxIDX])
							maxIDX = j;
						
						prev[j] = i;
						
					}
					
				}
				
			}
			
		}
		
		cout << "Max hits: " << length[maxIDX] << "\n";
		vector<int> path;
		
		while(maxIDX != -1){
			
			path.push_back(arr[maxIDX]);
			maxIDX = prev[maxIDX];
			
		}
		
		for(int i=path.size()-1;i>=0;i--)
			cout << path[i] << "\n";
			
		first = false;
		
	}
	
	return 0;
}
