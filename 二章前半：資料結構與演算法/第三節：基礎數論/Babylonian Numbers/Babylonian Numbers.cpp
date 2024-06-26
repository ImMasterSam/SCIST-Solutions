#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	string buf;
	cin.ignore();
	
	for(int time=0;time<n;time++){
		
		getline(cin, buf);
		
		int coe[10];
		int idx = 0;
		int t_sum = 0;
		
		for(int i=0;i<(int)buf.size();i++){
			
			if(buf[i] == ','){
				
				coe[idx++] = t_sum;
				t_sum = 0;
				
			}
			else{
				
				t_sum *= 10;
				t_sum += buf[i] - '0';
				
			}
			
		}
		
		coe[idx++] = t_sum;
		
		long long ans = 0;
		
		for(int i=0;i<idx;i++){
			
			ans += coe[i]*pow(60, idx-i-1);
			
		}
		
		cout << ans << "\n";
		
	}
	
	return 0;
}