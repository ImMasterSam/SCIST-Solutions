#include<iostream>
using namespace std;

string nums[2] = {"one", "two"};

int main(){
	
	int n;
	string s;
	
	cin >> n;
	
	for(int time=0;time<n;time++){
		
		cin >> s;
		
		if(s.size() == 5)
			cout << "3\n";
		else{
			
			int one=0, two=0;
			
			for(int i=0;i<3;i++){
				
				if(s[i] != nums[0][i])
					one++;
				
				if(s[i] != nums[1][i])
					two++;
				
			}
			
			if(one <= 1)
				cout << "1\n";
			else if(two <= 1)
				cout << "2\n";
			
		}
		
	}
	
	return 0;
}