#include<iostream>
using namespace std;

int flag[1000001] = {0};

int generate(int n){
	
	int t = n;
	
	while(t){
		
		n += t%10;
		t /= 10;
		
	}
	
	return n;
	
}

int main(){
	
	for(int i=1;i<1000000;i++){
		
		int x = generate(i);
		
		if(x<=1000000)
			flag[x] = 1;
		
	}
	
	for(int i=1;i<=1000000;i++){
		
		if(!flag[i])
			cout << i << "\n";
		
	}
	
	
	return 0;
}