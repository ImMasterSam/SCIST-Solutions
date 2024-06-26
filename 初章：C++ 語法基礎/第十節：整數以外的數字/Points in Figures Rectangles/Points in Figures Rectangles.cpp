#include<iostream>
using namespace std;

double r[11][4];

int main(){
	
	char rec, len_r=0;
	cin >> rec;
	
	while(rec!='*'){
		cin >> r[len_r][0] >> r[len_r][1] >> r[len_r][2]>> r[len_r][3];
		len_r++;
		
		cin >> rec;
	}
	
	double x, y, point=1;
	cin >> x >> y;
	
	while(x!=9999.9 && y!=9999.9){
		
		bool inrec = false;
		
		for(int i=0;i<len_r;i++){
			if(x>r[i][0]&&x<r[i][2]&&y>r[i][3]&&y<r[i][1]){
				cout << "Point " << point << " is contained in figure " << i+1 << "\n";
				inrec = true;
			}
				
		}
		
		if(!inrec){
			cout << "Point " << point << " is not contained in any figure\n";
		}
		
		point++;
		cin >> x >> y;
	}
	
		
	return 0;
}