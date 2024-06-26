#include<iostream>
using namespace std;

int wl[128][128] = {0};

int main(){
	
	wl['S']['P'] = 2;
	wl['P']['R'] = 2;
	wl['R']['S'] = 2;
	
	wl['S']['S'] = 1;
	wl['P']['P'] = 1;
	wl['R']['R'] = 1;
	
	int r;
	cin >> r;
	string sven = "";
	
	for(int i=0;i<r;i++){
		
		char c;
		cin >> c;
		sven += c;
		
	}
	
	int n;
	cin >> n;
	
	cin.ignore();
	
	int real_p = 0;
	string op[n];
	
	for(int i=0;i<n;i++){
		
		getline(cin, op[i]);
		
		for(int j=0;j<r;j++){
			
			real_p += wl[sven[j]][op[i][j]];
			
		}
		
	}
	
	int max_p = 0;
	
	for(int i=0;i<r;i++){
		
		int max = 0, temp;
		
		// S
		temp = 0;
		
		for(int j=0;j<n;j++){
			
			temp += wl['S'][op[j][i]];
			
		}
		
		if(temp > max)
			max = temp;
			
		// P
		temp = 0;
		
		for(int j=0;j<n;j++){
			
			temp += wl['P'][op[j][i]];
			
		}
		
		if(temp > max)
			max = temp;
			
		// R
		temp = 0;
		
		for(int j=0;j<n;j++){
			
			temp += wl['R'][op[j][i]];
			
		}
		
		if(temp > max)
			max = temp;
			
		max_p += max;
		
	}
	
	cout << real_p << "\n" << max_p;
	
	return 0;
}