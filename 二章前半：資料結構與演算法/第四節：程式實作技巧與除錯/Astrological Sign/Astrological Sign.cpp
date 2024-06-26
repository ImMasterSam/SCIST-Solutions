#include<iostream>
using namespace std;

string months[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
int Astro[13] = {120, 219, 320, 420, 520, 621, 722, 822, 921, 1022, 1122, 1221, 1231};
string Sign[13] = {"Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"};

int main(){
	
	int t;
	cin >> t;
	
	for(int time=0;time<t;time++){
		
		int d;
		string m;
		
		cin >> d >> m;
		
		int date = d;
		
		for(int i=1;i<=12;i++){
			
			if(m == months[i])
				date += i*100;
			
		}
		
		for(int i=0;i<13;i++){
			
			if(date > Astro[i])
				continue;
			else{
				
				cout << Sign[i] << "\n";
				break;
				
			}
			
		}
		
	}
	
	return 0;
}