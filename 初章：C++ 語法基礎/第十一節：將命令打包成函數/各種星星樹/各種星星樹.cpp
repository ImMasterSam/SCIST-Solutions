#include<iostream>
using namespace std;

void normal(int n){	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++)
			cout << " ";
		for(int j=0;j<2*i+1;j++)
			cout << "*";
		cout << "\n";
	}
	cout << "\n";
}

void dou(int n){
	for(int k=0;k<2;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++)
				cout << " ";
			for(int j=0;j<2*i+1;j++)
				cout << "*";
			cout << "\n";
		}
	}
	cout << "\n";	
}

void X_mas(int n){
	for(int k=1;k<=n;k++){
		for(int i=0;i<k;i++){
			for(int j=0;j<n-i-1;j++)
				cout << " ";
			for(int j=0;j<2*i+1;j++)
				cout << "*";
			cout << "\n";
		}
	}	
	cout << "\n";
}

void pot(int n){	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i+1;j++)
			cout << " ";
		for(int j=0;j<2*i+1;j++)
			cout << "*";
		
		cout << "\n";
	}
	for(int j=0;j<2*n+3;j++)
		cout << "#";
	cout << "\n\n";
}

int main(){
	
	int t, n;
	char c;
	cin >> t;
	
	for(int i=0;i<t;i++){
		cin >> c >> n;
		
		if(c == 'A') normal(n);
		if(c == 'B') dou(n);
		if(c == 'C') X_mas(n);
		if(c == 'D') normal(10*n);
		if(c == 'E') pot(n);
		if(c == 'F') normal(2*n);
		if(c == 'G') normal(3*n);
		if(c == 'H') normal(7*n);
		if(c == 'I') normal(4*n-1);
		
	}
	
	//cout << "\n";
		
	return 0;
}