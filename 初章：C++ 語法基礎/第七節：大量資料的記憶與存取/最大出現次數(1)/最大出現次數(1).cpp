#include <iostream>
using namespace std;

int a[1001] = {0};

int main(){
	int n, x, d, max=-1, index = -1;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> x;
		a[x]++;
	}
	
	for(int i=0;i<1001;i++){
		if(a[i] >= max){
			max = a[i];
			index = i;
		}
	}
	
	cout << index << " appears the most.";
	
	return 0;
}

