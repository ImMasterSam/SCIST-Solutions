#include<iostream>
#include<vector>
using namespace std;

char alpha[4] = {'A', 'T', 'C', 'G'};

vector<string> used;

int check_sub(string l, string t){
	
	string temp;
	int count = 0;
	
	for(auto i : used){
		if(i == t)
			return 0;
	}
	
	used.push_back(t);
	
	for(int i=0;i<l.size()-t.size()+1;i++){
			temp = l.substr(i, t.size());
			if(temp == t){
				count++;
			}
		}
		
	return count;
	
}

int main(){
	
	string s, l, temp;
	cin >> s;
	
	while(s != "0"){
		used.clear();
		int c1=0, c2=0, c3=0;
		cin >> l;
		
		//type 1
		for(int i=0;i<l.size()-s.size()+1;i++){
			temp = l.substr(i, s.size());
			if(temp == s){
				c1++;
			}
		}
		
		//type 2
		
		for(int i=0;i<s.size();i++){
			temp = s.substr(0, i);
			temp += s.substr(i+1, s.size()-i);
			
			c2 += check_sub(l, temp);
		}
		
		//type 3
		
		for(int c=0;c<4;c++){
			
			char chr = alpha[c];
			
			for(int i=0;i<=s.size();i++){
				temp = s.substr(0, i);
				temp += chr;
				temp += s.substr(i, s.size()-i);
				
				c3 += check_sub(l, temp);
			}
			
		}
		
		
		cout << c1 << " " << c2 << " " << c3 << "\n";
		
		
		
		cin >> s;
	}
	
		
	return 0;
}