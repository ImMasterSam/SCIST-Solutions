#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

struct word{
	
	string key;
	string value;
	
} dic[100005];
/*
void swap(word *a, word *b){
	
	word t = *a;
	*a = *b;
	*b = t;
	
}

void BubbleSort(word *dic, int n){
	
	for(int i=0;i<n-1;i++){
		
		for(int j=0;j<n-i-1;j++){
			
			if(dic[j].value>dic[j+1].value){
				
				swap(&dic[j], &dic[j+1]);
				
			}
			
		}
		
	}
	
}
*/

bool cmp(word a, word b){
	
	if(a.value != b.value)
		return a.value < b.value;
	
	return false;
	
}

int BinarySearch(word *dic, string q, int n){
	
	int l=0, r=n-1;
	int res = -1;
	
	while(l<=r){
		
		int mid = (l+r)/2;
		
		if(dic[mid].value == q){
			res = mid;
			break;
		}
		else if(dic[mid].value < q)
			l = mid + 1;
		else 
			r = mid - 1;
		
	}
	
	return res;
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n=0;
	string s, q;
	
	while(getline(cin, s) && s != ""){
		
		stringstream ss;
		ss << s;
		ss >> dic[n].key >> dic[n].value;
		n++;
		
	}
	
	sort(dic, dic+n, cmp);
	
	while(cin >> q){
		
		int res = BinarySearch(dic, q, n);
		
		if(res != -1){
			cout << dic[res].key << "\n";
		}
		else
			cout << "eh\n";
		
	}
	/*
	for(int i=0;i<n;i++){
		
		cout << dic[i].key << " " << dic[i].value << "\n";
		
	}*/
	
	return 0;
}