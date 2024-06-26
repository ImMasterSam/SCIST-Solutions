#include<iostream>
using namespace std;

#define min(a, b) (a<b)?a:b

int main(){
	
	int t, p;
	cin >> t;
	
	string g, c, s1, s2, s3;
	
	for(int times=0;times<t;times++){
		
		int min = 100000000;
		
		cin >> g >> c >> s1 >> s2 >> s3;
		
		for(int i=min(g.size(), c.size());i>=0;i--){
			
			if(g.substr(0, i)==c.substr(0, i)){
				p = (int)c.size()-i + (int)g.size()-i;
				if(p<min) min = p;
				break;
			}
			
		}
		
		for(int i=min(g.size(), s1.size());i>=0;i--){
			
			if(g.substr(0, i)==s1.substr(0, i)){
				p = (int)s1.size()-i + (int)g.size()-i +1;
				if(p<min) min = p;
				break;
			}
			
		}
		
		for(int i=min(g.size(), s2.size());i>=0;i--){
			
			if(g.substr(0, i)==s2.substr(0, i)){
				p = (int)s2.size()-i + (int)g.size()-i +1;
				if(p<min) min = p;
				break;
			}
			
		}
		
		for(int i=min(g.size(), s3.size());i>=0;i--){
			
			if(g.substr(0, i)==s3.substr(0, i)){
				p = (int)s3.size()-i + (int)g.size()-i +1;
				if(p<min) min = p;
				break;
			}
			
		}
		cout << min << "\n";
		
		
	}
	
	return 0;
}