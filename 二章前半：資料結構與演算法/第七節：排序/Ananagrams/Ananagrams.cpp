#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const pair<int, string> &a, const pair<int, string> &b){
	
	return a.second < b.second;
	
}

string lower(string s){
	
	vector<char> temp;
	
	for(int i=0;i<(int)s.size();i++)
		temp.push_back(tolower(s[i]));
		
	sort(temp.begin(), temp.end());
	
	string ans = "";
	
	for(char i:temp)
		ans += i;
		
	return ans;
	
}

int main(){
	
	vector<string> HEAP;
	vector<pair<int, string>> sorted;
	
	string s;
	int n = 0;
	
	while(cin >> s){
		
		if(s == "#")
			break;
			
		string low = lower(s);
			
		HEAP.push_back(s);
		sorted.emplace_back(n++, low);
		
	}
	
	sort(sorted.begin(), sorted.end(), cmp);
	
	vector<string> ans;
	
	for(int i=0;i<n;i++){
		
		if(i == 0){
			
			if(sorted[i].second != sorted[i+1].second)
				ans.push_back(HEAP[sorted[i].first]);
				
		}
		
		else if(i == n-1){
			
			if(sorted[i].second != sorted[i-1].second)
				ans.push_back(HEAP[sorted[i].first]);
				
		}
		
		else{
			
			if(sorted[i].second != sorted[i+1].second && sorted[i].second != sorted[i-1].second)
				ans.push_back(HEAP[sorted[i].first]);
			
		}
			
		
	}
	
	sort(ans.begin(), ans.end());
	
	for(auto i : ans)
		cout << i << "\n";
	
	
	return 0;
}