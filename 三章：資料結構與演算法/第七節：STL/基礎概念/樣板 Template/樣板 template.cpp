#include <bits/stdc++.h>
using namespace std;

// compiler 會主動替換 < ... > 到 T (typename)
template <typename T>
bool less_than(T a, T b){
	
	return a < b;
	
}

int main(){
	
	cout << less_than<int>(10, 20) << "\n";
	cout << less_than<string>("apple", "banana") << "\n";
	cout << less_than<float>(0.5, 0.3) << "\n";
	
	return 0;
}