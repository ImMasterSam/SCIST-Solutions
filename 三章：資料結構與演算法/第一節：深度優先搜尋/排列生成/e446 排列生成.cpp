#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> s;
	
	for(int i=0;i<n;i++){
		s.push_back(i+1);
	}
	
	do{
		for(auto a : s)
			printf("%d ", a);
		printf("\n");
	}while(next_permutation(s.begin(), s.end()));
	
	return 0;
}

