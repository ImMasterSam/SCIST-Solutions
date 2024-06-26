#include<iostream>
using namespace std;

int main(){
	
	int n, l;
	cin >> n >> l;
	
	int light[n][3] = {0};
	
	for(int i=0;i<n;i++)
		cin >> light[i][0] >> light[i][1] >> light[i][2];
		
	int time = 0;
	int l_idx = 0;
	int pos = 0;
	
	while(pos<l){
		
		time++;
		pos++;
		
		if(pos == light[l_idx][0]){
			
			if(time%(light[l_idx][1]+light[l_idx][2])<light[l_idx][1]){
				
				time += light[l_idx][1] - time%(light[l_idx][1]+light[l_idx][2]);
				
			}
			
			l_idx++;
			
		}
		
	}
	
	cout << time;
	
	return 0;
}