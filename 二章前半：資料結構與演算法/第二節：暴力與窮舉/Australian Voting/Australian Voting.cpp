#include<iostream>
#include<sstream>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int t;
	cin >> t;
		
	for(int time=0;time<t;time++){
		
		if(time>0){
			cout << "\n";
		}
		
		int n;
		cin >> n;
		
		cin.ignore();
		
		string names[25];
		
		for(int i=0;i<n;i++){
			
			getline(cin, names[i]);
			
		}
		
		string s;
		int ranks[1000][25];
		
		int nums = 0;
		
		while(getline(cin, s)){
			
			if(s == "") break;
			
			const char *ptr = s.c_str();
			int pos;
			
			for(int i=0;i<n;i++){

				sscanf(ptr, "%d%n", &ranks[nums][i], &pos);
				ptr += pos;
				
			}
			
			nums++;
			
		}


		int c_flag[25] = {0};
		
		while(1){
			
			int max = 0;
			int min = 3000;
			
			int count[25] = {0};
			
			for(int i=0;i<nums;i++){
				
				int idx = 0;
				
				while(c_flag[ranks[i][idx]]) idx++;
				
				count[ranks[i][idx]]++;
				
				
			}
			/*
			for(int i=1;i<=n;i++)
				cout << count[i] << " ";
			cout << "\n";*/
			
			for(int i=1;i<=n;i++){
				
				if(count[i] > max && !c_flag[i])
					max = count[i];
				
				if(count[i] < min && !c_flag[i])
					min = count[i];
				
			}
			
			if(max == min){
				
				for(int i=1;i<=n;i++){
					
					if(!c_flag[i])
						cout << names[i-1] << "\n";
					
				}
				
				break;
				
			}
			
			else if(max*2 >= nums){
				
				for(int i=1;i<=n;i++){
			
					if(!c_flag[i]){
						
						cout << names[i-1] << "\n";
						break;
						
					}
					
				}
				
				break;
				
			}
			
			else{
				
				for(int i=1;i<=n;i++){
					
					if(count[i] == min){
						c_flag[i] = 1;
						break;
					}
					
				}
				
			}
			
		}
		
	}
		
	
		
	return 0;
}