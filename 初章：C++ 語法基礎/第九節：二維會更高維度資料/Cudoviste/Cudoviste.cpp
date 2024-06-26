#include<iostream>
using namespace std;

char a[55][55];
int p[5] = {0};

int main(){
	
	int r , c;
	cin >> r >> c;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cin >> a[i][j];
	}
	
	for(int i=0;i<r-1;i++){
		for(int j=0;j<c-1;j++){
			
			int crush=0;
			
			if((a[i][j]!='#' && a[i+1][j]!='#') && (a[i][j+1]!='#' && a[i+1][j+1]!='#')){
				
				if(a[i][j]=='X')
					crush++;
				if(a[i+1][j]=='X')
					crush++;
				if(a[i][j+1]=='X')
					crush++;
				if(a[i+1][j+1]=='X')
					crush++;
					
				p[crush]++;
				
			}
			
			
		}
		
	}
	
	for(int i=0;i<5;i++){
		cout << p[i] << "\n";
	}
		
	return 0;
}