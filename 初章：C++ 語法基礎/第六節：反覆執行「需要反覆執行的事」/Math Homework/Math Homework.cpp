#include <iostream>
using namespace std;

int main(){
	long long b, d, c, l, count=0;
	cin >> b >> d >> c >> l;
	
	for(int i=0;i*b<=l;i++){
		for(int j=0;j*d<=l;j++){
			for(int k=0;k*c<=l;k++){
				if(b*i+d*j+c*k==l){
					cout << i << " " << j << " " << k << "\n";
					count++;
				}

			}
		}
	}
	
	if(!count)
		cout << "impossible";
	
	return 0;
}

