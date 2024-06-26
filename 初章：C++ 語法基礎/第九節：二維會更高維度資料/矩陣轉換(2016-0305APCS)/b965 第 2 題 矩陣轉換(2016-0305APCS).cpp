#include <iostream>
using namespace std;

void copy(int a[10][10], int b[10][10]){
	int i, j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			a[i][j] = b[i][j];
}

int main(){
	int r, c, m, t;
	while(scanf("%d %d %d", &r, &c, &m) != EOF){
		int move[10], a[10][10]={}, b[10][10]={};
		
		for(int i=0;i<r;i++)  //存B陣列 
			for(int j=0;j<c;j++)
				cin >> a[i][j];
				
		for(int i=0;i<m;i++)  //存動作 
			cin >> move[i];
			
		for(int i=m-1;i>=0;i--){ 
			if(move[i] == 0){  //反旋轉 
				for(int j=0;j<r;j++)
					for(int k=0;k<c;k++)
						b[c-1-k][j] = a[j][k];
				t = c;
				c = r;
				r = t;
				copy(a, b);
			}
			else if(move[i] == 1){  //翻轉 
				for(int j=0;j<r;j++)
					for(int k=0;k<c;k++)
						b[r-1-j][k] = a[j][k];
				copy(a, b);
			}
		}
		printf("%d %d\n", r, c);
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				if(j == c-1) cout << a[i][j];
				else cout << a[i][j] << " ";
			printf("\n");
		}
		
		
	}
	return 0;
}

