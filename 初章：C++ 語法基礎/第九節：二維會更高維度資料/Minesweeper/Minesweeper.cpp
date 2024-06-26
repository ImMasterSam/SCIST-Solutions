#include<iostream>
using namespace std;

char a[105][105];
int b[105][105];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int r, c, test = 1;
	cin >> r >> c;
	
	while(r!=0 and c!=0){
		
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				 cin >> a[i][j];
			}
		}
		
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				
				if(a[i][j]=='*')
					b[i][j] = 10;
				else{
					int count = 0;
					
					if(a[i-1][j-1]=='*')
						count++;
					if(a[i-1][j]=='*')
						count++;
					if(a[i-1][j+1]=='*')
						count++;
					if(a[i][j-1]=='*')
						count++;
					if(a[i][j+1]=='*')
						count++;
					if(a[i+1][j-1]=='*')
						count++;
					if(a[i+1][j]=='*')
						count++;
					if(a[i+1][j+1]=='*')
						count++;
						
					b[i][j] = count;	
						
				}
				 
			}
		}
		
		cout << "Field #" << test << ":\n";
		
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				if(b[i][j]==10)
				 	cout << '*';
				else
					cout << b[i][j];
			}
			cout << "\n";
		}
		
		cout << "\n";
		
		cin >> r >> c;
		test++;
	}
	
	
	return 0;
}