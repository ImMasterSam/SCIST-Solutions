#include<iostream>
using namespace std;

int score(int s0, int s1){
	
	if((s0==1&&s1==2)||(s0==2&&s1==1))
		return 10000;
	if(s0 == s1)
		return 100*s0+10*s0+s0;
	
	if(s0>s1)
		return 10*s0+s1;
	else
		return 10*s1+s0;
	
}

int main(){
	
	int s0, s1, s2, s3;
	cin >> s0 >> s1 >> s2 >> s3;
	
	while(s0!=0){
		int score1, score2;
		
		score1 = score(s0, s1);
		score2 = score(s2, s3);
		
		if(score1 == score2)
			cout << "Tie.\n";
		else if(score1 > score2)
			cout << "Player 1 wins.\n";
		else if(score1 < score2)
			cout << "Player 2 wins.\n";
			
		cin >> s0 >> s1 >> s2 >> s3;
	}
	
	
	return 0;
}