#include<iostream>
#include<algorithm>
using namespace std;

string type[11] = {"", "qaz", "wsx", "edc", "rfvtgb", "", "", "yhnujm", "ik,", "ol.", "p;/"};

int main(){
	
	int f, n;
	
	while(cin >> f >> n){
		
		int handi;
		string words[n];
		int tbl[128] = {0};
		
		tbl[' '] = -1;
		
		for(int i=0;i<f;i++){
			
			cin >> handi;
			
			if(handi == 5 || handi == 6)
				tbl[' ']++;
			else{
				
				for(int i=0;i<(int)type[handi].size();i++){
					
					tbl[ type[handi][i] ]++;
					
				}
				
			}
			
		}
		
		int flag[n] = {0};
		int max = 0;
		int count = 0;
		
		cin.ignore();
		
		for(int i=0;i<n;i++){
			
			getline(cin, words[i]);
			
		}
		
		sort(words, words+n);
		
		for(int i=0;i<n;i++){
			
			bool t = true;
			
			for(int j=0;j<(int)words[i].size();j++){
				
				if(tbl[words[i][j]] >= 1)
					t = false;
				
			}
			
			if(t){
				
				if(words[i] != words[i-1]){
					
					flag[i] = words[i].size();
					
					if(flag[i] > max){
						max = flag[i];
						count = 1;
					}
					else if (flag[i] == max)
						count++;
					
				}
				
			}
			
		}
		
		cout << count << "\n";
		
		if(max){
			
			for(int i=0;i<n;i++){
				
				if(flag[i] == max)
					cout << words[i] << "\n";
				
			}
			
		}
		
	}
	
	return 0;
}