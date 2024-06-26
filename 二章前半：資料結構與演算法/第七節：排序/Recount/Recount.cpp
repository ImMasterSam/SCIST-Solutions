#include<iostream>
#include<algorithm>
using namespace std;

string names[100005];
int c[100005];
string a[100005];

int main(){
	
	int tn = 0;
	string s;
	int idx = 0;
	
	while(getline(cin, s)){
		
		if(s == "***")
			break;
		
		a[idx++] = s;
		
	}
	
	sort(a, a+idx);
	
	int i, j;
	
	int max=0, count_max=0;
	
	for(i=0;i<idx;i=j){
		
		for(j=i+1; j<idx&& a[j] == a[i]; j++);
			
		names[tn] = a[i];
		c[tn] = j - i;
		
		if(c[tn] > max){
			
			max = c[tn];
			count_max = 1;
			
		}
		
		else if(c[tn] == max)
			count_max++;
		
		tn++;
		
	}
	
	if(count_max > 1)
		cout << "Runoff!";
	else{
		
		for(int i=0;i<tn;i++){
			
			if(c[i] == max){
				
				cout << names[i];
				break;
				
			}
			
		}
		
	}
	
	return 0;
}