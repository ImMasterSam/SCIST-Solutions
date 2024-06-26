#include<iostream>
#include<sstream>
using namespace std;

int main(){
	
	string s;
	getline(cin, s);
	
	int arr[100] = {0}, i=0, pos;
	
	const char *ptr = s.c_str();
	
	while(sscanf(ptr, "%d%n", &arr[i], &pos) == 1){
		
		ptr += pos;
		i++;
		
	}
	
	for(int j=0;j<i;j++){
		cout << arr[j] << "\n";
	}
	
	
	return 0;
}