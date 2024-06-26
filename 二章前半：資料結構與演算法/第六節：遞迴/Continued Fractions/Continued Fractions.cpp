#include<iostream>
using namespace std;

int main(){
	
	long long a, b;
	
	while(cin >> a >> b){
		
		string ans = "";
		
		if(a%b==0){
			cout << '[' << a/b << "]\n";
		}
		else{
			int level = 0;
			cout << '[';
			while(b != 1 && b != 0){
				
				if(level == 1){
					cout << ';';
				}
				else if(level > 1){
					cout << ',';
				}
				cout << a/b;
				level++;
				
				int t = b;
				
				b = a%b;
				a = t;
				
			}
			if(b == 1){
				if(level == 1){
					cout << ';';
				}
				else if(level > 1){
					cout << ',';
				}
				cout << a;
			}
				
			cout << "]\n";
			/*
			cout << '[';
			for(int i=0;i<ans.size();i++){
				if(i==0){
					cout << ans[i] << ';';
					continue;
				}
				cout << ans[i];
				if(i!=ans.size()-1)
					cout << ',';
				
			}
			cout << "]\n";*/
		}
		
	}
	
	return 0;
}