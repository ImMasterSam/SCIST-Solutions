#include<iostream>
using namespace std;

char a[50][11];


int f[50] = {0};

int main(){
	
	int n, count=0;
	cin >> n;
	
	for(int i=0;i<n;i++){
		
		bool full = true;
		cin >> a[i];
		for(int j=0;j<10;j++)
			if(a[i][j]!='#')
				full = false;
				
		if(full){
			count++;
			f[i]++;
		}
		
	}
	
	cout << "remove " << count << " rows.\n";
	
	for(int i=0;i<count;i++)
		cout << "..........\n";
		
	for(int i=0;i<n;i++){
		
		if(!f[i])
			cout << a[i] << "\n";
		
	}
		
	
		
	return 0;
}