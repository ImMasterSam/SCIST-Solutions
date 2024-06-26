#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin >> n;
	
	long long a[26] = {0};
	int f[26] = {0};
	string str;
	char v;
	long long x;
	for(int i=0;i<n;i++){
		cin >> v >> str >> x;
		if(str == "="){
			a[v-'a'] = x;
			f[v-'a'] = 1;
		}
		else if (str == "+="){
			a[v-'a'] += x;
		}
		else if (str == "-="){
			a[v-'a'] -= x;
		}
	}
	
	for(int i=0;i<26;i++){
		if(f[i] == 1){
			cout << char(i+'a') << ": " << a[i] << "\n";
		}
	}
	
	return 0;
}

