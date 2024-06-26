#include<iostream>
using namespace std;

int main(){
	
	string s;
	int ans = 0, str[100]={0}, i=0, max=0;
	
	while(getline(cin, s)){		
		str[i] = s.size();
		i++;
		if(s.size()>max)
			max = s.size();
			
		//cout << s.size() << "\n";
	}
	
	for(int j=0;j<i-1;j++){
		if(str[j]!=0)
			ans += (max-str[j])*(max-str[j]);
	}
	
	cout << ans;
	
	return 0;
}