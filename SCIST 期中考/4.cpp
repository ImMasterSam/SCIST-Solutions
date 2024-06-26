#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<long long > s;
	//set<long long > maxs;
	long long n, m, x;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> m;
		if(m == 1){
			cin >> x;
			s.push_back(x);
			//maxs.insert(x);
		}
		else if(m == 2){
			if(s.size() != 0){
				//maxs.erase(s[s.size()-1]);
				s.pop_back();
			}
		}
		else if(m == 3){
			
			if(s.size() == 0)
				cout << "empty!\n";
				
			else{
				
				//cout << *(maxs.rbegin()) << "\n";
				cout << *(max_element(s.begin(), s.end())) << "\n";
				
			}
			
		}
	}

	return 0;
}

