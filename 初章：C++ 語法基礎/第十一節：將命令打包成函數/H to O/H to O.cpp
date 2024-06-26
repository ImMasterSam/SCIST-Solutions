#include<iostream>
using namespace std;

void set_ary(long long ary[], string s){
	
	int idx = 0;
  	while(idx < s.size()) {
    int qnt = 0;
    char c = s[idx++];
    while(s[idx] >= '0' && s[idx] <= '9') {
      	qnt = qnt * 10 + s[idx] - '0';
      	idx++;
    }
    ary[c-'A'] += max(1, qnt);
  }
}

int main(){
	cin.tie(0); ios::sync_with_stdio(0);
	
	long long source[26] = {0};
	long long require[26] = {0};
	
	string s, re;
	long long n;
	
	cin >> s >> n >> re;
	
	set_ary(source, s);
	set_ary(require, re);
	/*
	for(int i=0;i<26;i++){
		if(source[i]!=0)
			cout << (char)(i+'A') << ": " << source[i] << '\n';
	}
	*/
	long long m = 1e9;
	/*
	cout << source[7] << "\n";
	cout << require[7] << "\n";
	*/
	for(int i=0;i<26;i++){
		if(require[i] != 0)
			m = min(m, source[i]*n/require[i]);
			//cout << (char)(i+'A') << ": " << m << "\n";
	}
	
	cout << m << "\n";
	
	return 0;
}