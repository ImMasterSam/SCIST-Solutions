#include<iostream>
#include<cmath>
using namespace std;

char alpha[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int decimal(string s, int b){
	
	int l = s.size();
	int sum = 0;
	
	for(int i=0;i<l;i++){
		
		for(int j=0;j<36;j++){
			
			if(alpha[j] == s[i]){
				
				sum += j*pow(b, l-i-1);
				break;
				
			}
			
		}
		
	}
	
	return sum;
	
}

int least(string s){
	
	int max = 2;
	
	for(int i=0;i<(int)s.size();i++){
		
		for(int j=0;j<36;j++){
			
			if(alpha[j] == s[i]){
				
				if(j >= max)
					max = j+1;
					
				break;
				
			}
			
		}
		
	}
	
	return max;
}

int main(){
	
	string x;
	string y;
	
	while(cin >> x >> y){
		
		bool found = false;
		
		int x_min = least(x);
		int y_min = least(y);
		
		for(int i=x_min;i<=36&&!found;i++){
			
			for(int j=y_min;j<=36&&!found;j++){
				/*
				if(j == i)
					continue;*/
				
				if(decimal(x, i) == decimal(y, j)){

					cout << x << " (base " << i << ") = " << y << " (base " << j << ")\n";
					found = true;
					
				}
				
			}
			
		}
		
		if(!found)
			cout << x << " is not equal to " << y << " in any base 2..36\n";
		
	}
	
	
	return 0;
}