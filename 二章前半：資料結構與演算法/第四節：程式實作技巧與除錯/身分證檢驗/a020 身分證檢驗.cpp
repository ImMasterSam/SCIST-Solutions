#include <iostream>
using namespace std;

char Letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'
			, 'H', 'I', 'J', 'K', 'L', 'M'
			, 'N', 'O', 'P', 'Q', 'R', 'S'
			, 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

string Nums[26] = {"10", "11", "12", "13", "14", "15", "16"
		, "17", "34", "18", "19", "20", "21"
		, "22", "35", "23", "24", "25", "26"
		, "27", "28", "29", "32", "30", "31", "33"};

int main(){
	string ID, Co="";
	int S=0;
	getline(cin, ID);
	for(int i=0;i<26;i++){
		if(Letters[i] == ID[0])
			Co += Nums[i];
	}
	
	for(int j=1;j<10;j++)
			Co += ID[j];
	
	S = S + (Co[0]-48) + (Co[10]-48);
	
	for (int k=1;k<10;k++)
		S = S + (Co[k]-48)*(10-k);
	
	(S%10) ? cout << "fake" : cout << "real"; 
	
	return 0;
}
