#include <iostream>
#include <iomanip>
using namespace std;

int arr[8][8] = {0};
int m = 0;

bool add[20] = {0};
bool sub[20] = {0};
bool col[20] = {0};

void dfs(int row, int total){
	
	if(row == 8){
		
		if(total > m)
			m = total;

		return;
		
	}
	
	for(int i=0;i<8;i++){
		
		if(!col[i] && !add[row+i] && !sub[row-i+8]){
			
			col[i] = add[row+i] = sub[row-i+8] = true;
			dfs(row+1, total + arr[row][i]);
			col[i] = add[row+i] = sub[row-i+8] = false;
			
		}
		
	}
	
}

int main(){
	
	int k;
	cin >> k;
	
	while(k--){
		
		m = 0;
		
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				cin >> arr[i][j];
		
		dfs(0, 0);
		
		cout << setw(5) << m << "\n";
		
	}
	
	
	return 0;
}