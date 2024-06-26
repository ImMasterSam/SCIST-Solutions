#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	long long a[m];
	
	for(int i=0;i<m;i++){
		cin >> a[i];
	}
	
	int k=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<a[i];j++){
			k += 1;
			if(k>n){
				cout << "\n";
				k = 1;
			}
			if(i%2 ==0)
				cout << "*";
			else
				cout << "#";
		}
	}
	
	return 0;
}

