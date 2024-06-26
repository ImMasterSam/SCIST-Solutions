#include<iostream>
using namespace std;

int main(){
	
	int w, p, size;
	
	cin >> w >> p;
	int l[p+2] = {0}, f[w+5]={0};
	
	for(int i=1;i<p+2;i++){	
		if(i==p+1)
			l[i] = w;
		else
			cin >> l[i];
	}
	
	for(int i=1;i<p+2;i++){
		for(int j=0;j<i;j++){
			
			size = l[i] - l[j];
			f[size] = 1;
			
		}
	}
	
	for(int i=0;i<w+5;i++){
		if(f[i]==1)
			cout << i << " ";
	}
	
	return 0;
}
