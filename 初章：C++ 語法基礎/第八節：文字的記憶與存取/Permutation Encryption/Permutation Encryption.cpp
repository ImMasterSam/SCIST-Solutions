#include<iostream>
using namespace std;

int a[25] = {0};

int main(){
	
	string s, ans;
	int n;
	cin >> n;
	
	while(n!=0){
		
		for(int i=0;i<n;i++)
			cin >> a[i];
			
		getline(cin, s);
		getline(cin, s);
		
		ans.resize(((s.size()+n-1)/n)*(n), ' ');
		
		
		cout << '\'';
		for(int i=0;i<ans.size();i++){
			if((i/n)*n + a[i%n] > s.size())
				ans[i] = ' ';
			else
				ans[i]= s[ (i/n)*n + a[i%n] - 1 ];
			
		}
		
		cout << ans << '\'';
		
		cout << "\n";
		
		cin >> n;
	}
		
		
	
		
	return 0;
}