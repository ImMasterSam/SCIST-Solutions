#include<iostream>
using namespace std;

string cipher;
int alpha[26] = {0};

int main(){
	
	alpha['Q'-'A'] = 1;
	string key;
	getline(cin, key);
	
	for(int i=0;i<(int)key.size();i++){

		if(key[i]!=' ' && alpha[toupper(key[i])-'A'] == 0){
			cipher += (char)toupper(key[i]);
			alpha[toupper(key[i])-'A']++;
		}

	}
	
	for(int i=0;i<26;i++){
		if(alpha[i]==0){
			cipher += (char)('A'+i);
			
		}
	}
	/*
	for(int i=0;i<25;i++){
		cout << cipher[i];
		if(i%5==4)
			cout << "\n";
	}*/
	string word;
	getline(cin, word);
	string group;
	int index=0, a, b;
	
	while(index<word.size()){
		
		while(word[index]==' ')
			index++;
			
		if(toupper(word[index]) == group[0])
			group += 'X';
		else{
			group += (char)(toupper(word[index]));
			index++;
		}
		
		if(index == word.size() && group.size()==1)
			group += 'X';
		
		//cout << group << "\n";
		
		if(group.size() == 2){
			for(int i=0;i<25;i++){
				if(cipher[i]==group[0])
					a = i;
				if(cipher[i]==group[1])
					b = i;
			}
			
			//same row
			if(a/5 == b/5){
				if(a%5==4)
					cout << cipher[a-4];
				else
					cout << cipher[a+1];
					
				if(b%5==4)
					cout << cipher[b-4];
				else
					cout << cipher[b+1];
			}
			
			//same row
			else if(a%5 == b%5){
				if(a/5==4)
					cout << cipher[a-20];
				else
					cout << cipher[a+5];
					
				if(b/5==4)
					cout << cipher[b-20];
				else
					cout << cipher[b+5];
			}
			
			else{
				cout << cipher[(a/5)*5+b%5];
				cout << cipher[(b/5)*5+a%5];
			}
			
			group = "";
			
		}
		
	}
	
	
	return 0;
}