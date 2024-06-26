#include<iostream>
using namespace std;

int mark[10][7] = {{1, 1, 1, 1, 0, 1, 1}, // 0
				   {0, 0, 1, 0, 0, 1, 0}, // 1
				   {0, 1, 1, 1, 1, 0, 1}, // 2
				   {0, 1, 1, 0, 1, 1, 1}, // 3
				   {1, 0, 1, 0, 1, 1, 0}, // 4
				   {1, 1, 0, 0, 1, 1, 1}, // 5
				   {1, 1, 0, 1, 1, 1, 1}, // 6
				   {0, 1, 1, 0, 0, 1, 0}, // 7
				   {1, 1, 1, 1, 1, 1, 1}, // 8
				   {1, 1, 1, 0, 1, 1, 1}}; // 9

int main(){
	
	int n;
	string s;
	
	bool first = true;
	
	while(cin >> n >> s){
		
		if(n == 0 && s == "0")
			break;
		/*	
		if(!first)
			cout << "\n";*/
			
		int l = s.size();
		
		string dis[2*n+3];
		
		//top
		for(int i=0;i<l;i++){
			
			dis[0] += ' ';
			
			for(int j=0;j<n;j++){
				
				dis[0] += ((mark[s[i]-'0'][1]) ? '-' : ' ');
				
			}
			
			dis[0] += ' ';
			
			if(i != l-1)
				dis[0] += ' ';
			
		}
		
		//upper body
		
		for(int k=0;k<n;k++){
			
			for(int i=0;i<l;i++){
				
				dis[k+1] += ((mark[s[i]-'0'][0]) ? '|' : ' ');
				
				for(int j=0;j<n;j++)
					dis[k+1] += ' ';
				
				dis[k+1] += ((mark[s[i]-'0'][2]) ? '|' : ' ');
				
				if(i != l-1)
					dis[k+1] += ' ';
				
			}
			
		}
		
		//middle
		for(int i=0;i<l;i++){
			
			dis[n+1] += ' ';
			
			for(int j=0;j<n;j++){
				
				dis[n+1] += ((mark[s[i]-'0'][4]) ? '-' : ' ');
				
			}
			
			dis[n+1] += ' ';
			
			if(i != l-1)
				dis[n+1] += ' ';
			
		}
		
		//lower body
		
		for(int k=0;k<n;k++){
			
			for(int i=0;i<l;i++){
				
				dis[n+k+2] += ((mark[s[i]-'0'][3]) ? '|' : ' ');
				
				for(int j=0;j<n;j++)
					dis[n+k+2] += ' ';
				
				dis[n+k+2] += ((mark[s[i]-'0'][5]) ? '|' : ' ');
				
				if(i != l-1)
					dis[n+k+2] += ' ';
				
			}
			
		}
		
		//bottom
		for(int i=0;i<l;i++){
			
			dis[2*n+2] += ' ';
			
			for(int j=0;j<n;j++){
				
				dis[2*n+2] += ((mark[s[i]-'0'][6]) ? '-' : ' ');
				
			}
			
			dis[2*n+2] += ' ';
			
			if(i != l-1)
				dis[2*n+2] += ' ';
			
		}
		
		//display
		for(int i=0;i<2*n+3;i++){
			
			cout << dis[i] << "\n";
			
		}
		
		first = false;
		
		cout << "\n";
		
	}
	
	return 0;
}