#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b){
	
	if(b == 0)
		return 1;
	
	while(a%b){
		
		int t = a%b;
		a = b;
		b = t;
		
	}
	
	return b;
	
}

void swap(int *a, int *b){
	
	int t = *a;
	*a = *b;
	*b = t;
	
}

int cmp(int i, int j, int k, int l){
	
	int s1, s2;
	
	//cout << i << " " << j << " " << k << " " << l << "\n";
	
	if(i<j)
		swap(&i, &j);
	
	if(k<l)
		swap(&k, &l);
		
	if(i == 2 && j == 1)
		s1 = 10000;
	else if(i == j)
		s1 = i*100;
	else
		s1 = i*10+j;
	
	if(k == 2 && l == 1)
		s2 = 10000;
	else if(k == l)
		s2 = k*100;
	else
		s2 = k*10+l;
		
	if(s1>s2)
		return 1;
	else
		return 0;
	
}

int main(){
	
	char num[4];
	
	while(cin >> num[0] >> num[1] >> num[2] >> num[3]){
		
		if(num[0]=='0'&&num[1]=='0'&&num[2]=='0'&&num[3]=='0')
			break;
			
		int star_flag[4] = {0}, c_star=0;
		
		for(int i=0;i<4;i++){
			
			if(num[i] == '*'){
				
				star_flag[i]++;
				c_star++;
				
			}
			
		}
		
		int sum = 0;
		
		for(int i=1;i<=6;i++){
			
			for(int j=1;j<=6;j++){
				
				for(int k=1;k<=6;k++){
					
					for(int l=1;l<=6;l++){
						
						if(!star_flag[0] && i!=num[0]-'0')
							continue;
						if(!star_flag[1] && j!=num[1]-'0')
							continue;
						if(!star_flag[2] && k!=num[2]-'0')
							continue;
						if(!star_flag[3] && l!=num[3]-'0')
							continue;
							
						sum += cmp(i, j, k, l);
						
					}
					
				}
				
			}
			
		}
		
		int dom = pow(6, c_star);
		int g = gcd(dom, sum);
		
		int front = sum/g;
		int back = dom/g;
		
		if(front == 0)
			cout << "0\n";
		else if(front == back)
			cout << "1\n";
		else
			cout << front << "/" << back << "\n";
		
		
		
	}
	
	return 0;
}