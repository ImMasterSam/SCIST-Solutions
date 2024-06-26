#include <iostream>
#include <cmath>
using namespace std;

char list[17]={'0', '1', '2', '3', '4'
			, '5', '6', '7', '8', '9', 'A'
			, 'B', 'C', 'D', 'E', 'F'};

int main(){
	string a;
	long long b, c, l, index, num, i;
	char ans[7];
	while(cin >> a >> b >> c){
		if(a == "0")
			cout << "      0\n";
		else{
			char ans[7] = {' '};
			l=a.size();
			num=0;
			for(i=l-1;i>=0;i--){
				for(index=0;index<17;index++){
					if(list[index]==a[i]){
						num += index*pow(b, l-1-i);
					}
				}
			}
			i=6;
			while(num>0 && i>=0){
				ans[i] = list[(num%c)];
				num /= c;
				i--;
			}
			
			if(num>0)
				cout << "  ERROR\n";
			else{
				for(i=0;i<7;i++)
					cout << ans[i];
				cout << "\n";
			}
			
		}
	} 
	return 0;
}

