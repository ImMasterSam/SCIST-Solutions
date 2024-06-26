#include<iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	char a[n][n];

	bool check = true;
	for(int i=0;i<n;i++)
		cin >> 	a[i];
		
	for(int i=0;i<n;i++){
		int b = 0, w = 0;
		for(int j=0;j<n;j++){
			if(a[i][j]=='B')
				b++;
			else
				w++;
			if(j<n-2){
				if(a[i][j]==a[i][j+1] and a[i][j+1]==a[i][j+2]){
					check = false;
				}
			}
			
		}
		if(b!=w){
			check = false;
		}
	}
	
	for(int i=0;i<n;i++){
		int b = 0, w = 0;
		for(int j=0;j<n;j++){
			if(a[j][i]=='B')
				b++;
			else
				w++;
				
			if(i<n-2){
				if(a[i][j]==a[i+1][j] and a[i+1][j]==a[i+2][j]){
					check = false;
				}
			}
		}
		if(b!=w)
			check = false;
	}
		
	
	
	cout << check;
		
	return 0;
}