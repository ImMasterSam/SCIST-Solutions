#include <iostream>
#include <vector>
using namespace std;

char s[36] = {'1', '1', '2', '3', '4', '5', '6', '7', '8', '9'
			, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'
			, 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

vector<int> v;

void out(int a, int b, int d, int l){
	if(a/b == 0){
		cout << s[a] << "*" << b << "(";
		if(d){
			out(d, b, 0, 1);
		}
		else{
			cout << 0;
		}
		if(l)
			cout << ")";
		else
			cout << ")+";
	}
	else{
		if(a%b == 0){
			if(l)
				out(a/b, b, d+1, 1);
			else
				out(a/b, b, d+1, 0);
		}
		else{
			out(a/b, b, d+1, 0);
			cout << s[a%b] << "*" << b << "(";
			if(d){
				out(d, b, 0, 1);
			}
			else{
				cout << 0;
			}
			
			if(l)
				cout << ")";
			else
				cout << ")+";
		}
	}
}

int main(){
	int a, b;
	cin >> a >> b;
	
	out(a, b, 0, 1);
	
	return 0;
}

