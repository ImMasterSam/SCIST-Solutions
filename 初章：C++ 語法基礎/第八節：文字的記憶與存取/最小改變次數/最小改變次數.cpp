#include<iostream>
using namespace std;

int main(){
	
	int min = 100000000, count;
	string a, b, t;
	cin >> a >> b;
	
	for(int i=0;i<a.size()-b.size()+1;i++){
		
		count = 0;
		
		t = a.substr(i, b.size());
		
		for(int j=0;j<b.size();j++){
			if(t[j]!=b[j])
				count++;
		}
		
		if(count < min)
			min = count;
		
	}
	
	cout << min << " times";
	
	return 0;
}