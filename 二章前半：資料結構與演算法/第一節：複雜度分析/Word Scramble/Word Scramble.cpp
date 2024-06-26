#include<iostream>
using namespace std;

int main(){
	
	string s;
	
	while(getline(cin, s)){
		
		char temp[1000];
		int pos;
		const char* ptr = s.c_str();
		
		while(true){
			
			int res = sscanf(ptr, " %[^ ]%n", temp, &pos);
			
			if(res == -1){
				break;
			}
			
			if(ptr != s.c_str())
				cout << " ";
				
			ptr += pos;
			
			//cout << ptr - s.c_str();
			
			//cout << temp << " ";
			string t = temp;
			//cout << t << " ";
			
			for(int c=t.size()-1;c>=0;c--){
				cout << t[c];
			}
			
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}