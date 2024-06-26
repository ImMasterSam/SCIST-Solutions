#include <iostream>
using namespace std;

int main(){
	int m, n, count=0;
	cin >> n >> m;
	
	for(int x=1;x<=m;x++){
		for(int y=1;y<=m;y++){
			for(int z=1;z<=m;z++){
				if(x+y+z == n)
				 count++;
			}
		}
	}
	
	cout << "ans: " << count << "\n";
	
	return 0;
}

