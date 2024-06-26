#include<iostream>
using namespace std;

int main(){
	
	int n, k;
	string name[15];
	string menu;
	cin >> n;
	
	int index = -1;
	
	for(int t=0;t<n;t++){
		
		bool pancake = false, peasoup = false;
		
		cin >> k;
		
		cin.ignore();
		getline(cin, name[t]);
		
		for(int t1=0;t1<k;t1++){
			
			getline(cin, menu);
			//cout << menu << "\n";
			
			if(menu == "pancakes")
				pancake = true;
			else if(menu == "pea soup")
				peasoup = true;
			
		}
		
		//cout << pancake << " " << peasoup << "\n";
		
		if(pancake && peasoup && index == -1){
			
			index = t;
			
		}
		
	}
	
	if(index == -1)
		cout << "Anywhere is fine I guess";
	else
		cout << name[index];
		
	return 0;
}