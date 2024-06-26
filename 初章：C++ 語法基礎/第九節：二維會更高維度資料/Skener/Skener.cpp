#include<iostream>
using namespace std;

char map[60][60];

int main(){
	
	int r, c, a, b;
	cin >> r >> c >> a >> b;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cin >> map[i][j];
	}
			
	for(int i=0;i<r*a;i++){
		for(int j=0;j<c*b;j++){
			cout << map[i/a][j/b];
		}
		cout << "\n";
	}
		
	return 0;
}