#include<iostream>
using namespace std;

bool Slump(string s, int &i){
	
	if((s[i]=='D' || s[i]=='E') && s[++i]=='F'){
		
		while(s[++i]=='F');
		if(s[i] == 'G')
			return true;
		else if(s[i]=='D' || s[i]=='E')
			return Slump(s, i);
		else
			return false;
		
	}
	else
		return false;
	
}

bool Slimp(string s, int &i){
	
	if(s[i] == 'A'){
		
		i++;
		
		if(s[i] == 'H')
			return true;
			
		else if(s[i] == 'B'){
			
			if(Slimp(s, ++i) && s[++i] == 'C')
				return true;
			else
				return false;
			
		}
		
		else if(Slump(s, i) && s[++i] == 'C')
			return true;
			
		else
			return false;
		
	}
	else
		return false;
	
}

int main(){
	
	int n, i;
	string s;
	cin >> n;
	
	cout << "SLURPYS OUTPUT\n";
	
	for(int k=0;k<n;k++){
		
		cin >> s;
		i = 0;
		
		if(Slimp(s, i) && Slump(s, ++i) && i == s.size()-1)
			cout << "YES\n";
		else
			cout << "NO\n";
		
	}
	
	cout << "END OF OUTPUT\n";
	
	
	return 0;
}