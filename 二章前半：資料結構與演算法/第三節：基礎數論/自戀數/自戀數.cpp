#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	long long b;
	string s;
	
	cin >> b >> s;
	
	long long n = 0;
	long long power = 0;
	
	for(int i=0;i<s.size();i++){
		
		n += (s[i]-'0') * pow(b, s.size()-i-1);
		
	}
	
	for(int i=0;i<s.size();i++){
		
		power += pow((s[i]-'0'), s.size());
		
	}
	
	//cout << n << " : " << power << "\n";
	
	if(n == power)
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}