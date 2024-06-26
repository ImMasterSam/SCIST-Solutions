#include<iostream>
using namespace std;

int solve(){
	
	int Wl, Dl, Wr, Dr;
	
	cin >> Wl >> Dl >> Wr >> Dr;
	
	if(Wl == 0)
		Wl = solve();
		
	if(Wr == 0)
		Wr = solve();
	
	if(Wl == -1 || Wr == -1)
		return -1;
		
	else if(Wl*Dl == Wr*Dr)
		return Wl + Wr;
	else
		return -1;
	
}

int main(){
	
	int n;
	cin >> n;
	
	bool first = true;
	
	for(int i=0;i<n;i++){
		
		int res = solve();
		
		if(!first)
			cout << "\n";
		
		if(res > 0)
			cout << "YES\n";
		else
			cout << "NO\n";
		
		first = false;
		
	}
	
	return 0;
}