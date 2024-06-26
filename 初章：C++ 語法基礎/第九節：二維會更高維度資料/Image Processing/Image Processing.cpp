#include<iostream>
using namespace std;

int a[25][25] = {0};
int b[20][20] = {0};

int main(){
	
	int h, w, n, m;
	cin >> h >> w >> n >> m;
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
			cin >> a[i][j];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin >> b[i][j];
	}
	
	for(int i=0;i<h-n+1;i++){
		for(int j=0;j<w-m+1;j++){
			
			int sum=0;
			
			for(int x=0;x<n;x++){
				for(int y=0;y<m;y++){
					sum += b[x][y]*a[i+n-x-1][j+m-y-1];
				}
			}
			
			cout << sum << " ";
			
		}
		cout << "\n";
	}
		
	return 0;
}