#include<iostream>
using namespace std;

char a[30][30];

int main(){
	
	int r, c;
	cin >> r >> c;
	string min = "zzzzzzzzzzzzzzzzzzzzzzzz";
	string t = "";
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cin >> a[i][j];
	}
	
	//right
	for(int i=0;i<r;i++){
		
		t = "";
		//cout << "row " << i+1 << "\n";
		
		for(int j=0;j<c;j++){
			
			if(a[i][j]=='#'){
				if(t < min && (int)t.size()>1)
					min = t;
				//cout << t << "\n";
				t = "";
				continue;
			}
			else
				t += a[i][j];
			
		}
		if(t < min && (int)t.size()>1)
					min = t;
	}
	
	//down
	for(int j=0;j<c;j++){
		
		t = "";
		//cout << "colum " << j+1 << "\n";
		
		for(int i=0;i<r;i++){
			
			if(a[i][j]=='#'){
				if(t < min && (int)t.size()>1)
					min = t;
				//cout << t << "\n";
				t = "";
				continue;
			}
			else
				t += a[i][j];
			
		}
		if(t < min && (int)t.size()>1)
					min = t;
	}
	
	cout << min << "\n";
	
	
		
	return 0;
}