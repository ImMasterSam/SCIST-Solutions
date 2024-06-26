#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<char, int> alpha = {{'A', 2}, {'B', 2}, {'C', 2},
						{'D', 3}, {'E', 3}, {'F', 3},
						{'G', 4}, {'H', 4}, {'I', 4},
						{'J', 5}, {'K', 5}, {'L', 5},
						{'M', 6}, {'N', 6}, {'O', 6},
						{'P', 7}, {'R', 7}, {'S', 7},
						{'T', 8}, {'U', 8}, {'V', 8},
						{'W', 9}, {'X', 9}, {'Y', 9}};

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		vector<string> v;
		
		string s;
		
		for(int i=0;i<n;i++){
			
			cin >> s;
			
			string nums = "";
			
			for(int i=0;i<(int)s.size();i++){
				
				if(s[i] == '-')
					continue;
					
				if(isalpha(s[i]))
					nums += (char) (alpha[s[i]] + '0');
				else
					nums += s[i];
				
			}
			
			v.push_back(nums);
			
			
		}
		
		sort(v.begin(), v.end());
		
		vector<string> dup_nums;
		vector<int> count;
		
		int i, j;
		
		for(i=0;i<v.size();i=j){
			
			for(j=i+1;j<v.size() && v[j] == v[i];j++);
			
			dup_nums.push_back(v[i]);
			count.push_back(j-i);
			
		}
		
		bool found = false;
		
		for(i=0;i<dup_nums.size();i++){
			
			if(count[i] > 1){
				
				for(j=0;j<dup_nums[i].size();j++){
					
					cout << dup_nums[i][j];
					
					if(j == 2)
						cout << "-";
					
				}
				
				cout << " " << count[i] << "\n";
				found = true;
				
			}
			
		}
		
		if(!found)
			cout << "No duplicates.\n";
		
		
		if(t)
			cout << "\n";
		
	}
	
	
	return 0;
}