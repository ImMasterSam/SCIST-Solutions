#include<iostream>
using namespace std;

int a[5][6];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	bool line = false;
	
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++)
			cin >> a[i][j];
	}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			
			if((a[i][j]==a[i][j+1]) && (a[i][j+1]==a[i][j+2]))
				line = true;
			if((a[i][j]==a[i+1][j]) && (a[i+1][j]==a[i+2][j]))
				line = true;
			
		}
	}
	
	if(line)
		cout << "Yes\n";
	else
		cout << "No\n";
	
	
	return 0;
}