#include<iostream>
using namespace std;

int a[14] = {0};

int main(){
	
	string s;
	
	for(int i=0;i<5;i++){
		cin >> s;
		
		if(s[0]=='A')
			a[1]++;
		else if(s[0]=='T')
			a[10]++;
		else if(s[0]=='J')
			a[11]++;
		else if(s[0]=='Q')
			a[12]++;
		else if(s[0]=='K')
			a[13]++;
		else
			a[s[0]-'0']++;
		
	}
	int max = 0;
	
	for(int i=0;i<14;i++){
		if(a[i]>max)
			max = a[i];
	}
	
	cout << max;
		
	return 0;
}