#include<iostream>
#include<cmath>
using namespace std;

char alpha[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

long long decimal(string s, int b){
	
	int l = s.size();
	long long sum = 0;
	
	for(int i=0;i<l;i++){
		
		for(int j=0;j<16;j++){
			
			if(alpha[j] == s[i]){
				
				sum += j*pow(b, l-i-1);
				break;
				
			}
			
		}
		
	}
	
	return sum;
	
}

int least(string s){
	
	int max = 1;
	
	for(int i=0;i<(int)s.size();i++){
		
		for(int j=0;j<16;j++){
			
			if(alpha[j] == s[i]){
				
				if(j >= max)
					max = j+1;
					
				break;
				
			}
			
			else if(j==15)
				return -1;
			
		}
		
	}
	
	return max;
}

int main(){
	
	int in, out;
	string x;
	
	while(cin >> in >> out >> x){
		
		int min = least(x);
		
		if(min > in || min<0)
			cout << x << " is an illegal base " << in << " number\n";
			
		else{
			
			long long num = decimal(x, in);
			
			string ans = "";
			
			while(num){
				
				ans += alpha[num%out];
				num /= out;
				
			}
			
			cout << x << " base " << in << " = ";
			
			for(int i=ans.size()-1;i>=0;i--){
				
				cout << ans[i];
				
			}
			
			if(ans == "")
				cout << "0";
			
			cout << " base " << out << "\n";
			
		}
		
	}
	
	return 0;
}