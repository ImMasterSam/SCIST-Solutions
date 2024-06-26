#include<iostream>
#include<cstring>
using namespace std;

int cmp(string s, string t){
	
	return strcmp(s.c_str(), t.c_str());
	
}

int main(){

	string s;
	string t;
	
	cin >> s >> t;
	
	cout << cmp(s, t);	
	
	return 0;
}