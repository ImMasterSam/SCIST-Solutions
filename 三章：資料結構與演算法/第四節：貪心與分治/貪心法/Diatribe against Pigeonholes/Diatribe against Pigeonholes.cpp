#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

bool cmp_1(const pair<char, int> &a, const pair<char, int> &b){
	
	if(a.s == b.s)
		return a.f < b.f;
	
	return a.s > b.s;
	
}

bool cmp_2(const pair<char, int> &a, const pair<char, int> &b){
	
	if(a.s == b.s)
		return a.f > b.f;
	
	return a.s > b.s;
	
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		char c;
		pair<int, int> arr[26], ans[26];
		
		for(int i=0;i<26;i++)
			arr[i].f = i;
		
		while(cin >> c){
			
			if(c == '#')
				break;
				
			arr[c-'A'].s++;
			
		}
			
		int l = 0;
		int r = n-1;
		
		for(int i=0;i<n;){
			
			if(i+1<n){
				
				sort(arr+i, arr+n, cmp_1);
				
				if(arr[i].s != arr[i+1].s){
					
					if(arr[i].f < arr[i+1].f){
						
						ans[l++] = arr[i];
						sort(arr+i+1, arr+n, cmp_2);
						ans[r--] = arr[i+1];
						
					}
					else{
						
						swap(arr[i], arr[i+1]);
						ans[l++] = arr[i];
						sort(arr+i+1, arr+n, cmp_2);
						ans[r--] = arr[i+1];
						
					}
					
				}
				else{
					
					sort(arr+i, arr+n, cmp_1);
					ans[l++] = arr[i];
					sort(arr+i+1, arr+n, cmp_2);
					ans[r--] = arr[i+1];
					
				}
				i += 2;
			}
			else{
				
				ans[l] = arr[i];
				i++;
				
			}
			
		}
		
		for(int i=0;i<n;i++)
			cout << (char)(ans[i].f+'A') << (i==n-1 ? '\n' : ' ');
		for(int i=0;i<n;i++)
			cout << ans[i].s << (i==n-1 ? '\n' : ' ');
		
	}
	
	return 0;
}