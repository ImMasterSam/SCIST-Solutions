#include <iostream>
using namespace std;

int main(){
	int s;
	cin >> s;
	
	if(s == 100)
		cout << "S\n";
	else if (s >= 90)
		cout << "A\n";
	else if (s >= 80)
		cout << "B\n";
	else if (s >= 70)
		cout << "C\n";
	else if (s >= 60)
		cout << "D\n";
	else
		cout << "F\n";
		
	return 0;
}

