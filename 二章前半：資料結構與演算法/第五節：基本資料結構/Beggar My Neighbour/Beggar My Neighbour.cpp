#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;

int num(string s){
	
	char c = s[1];
	
	if(c>='0' && c<='9')
		return c - '0';
	if(c == 'A')
		return 1;
	if(c == 'T')
		return 10;
	if(c == 'J')
		return 11;
	if(c == 'Q')
		return 12;
	if(c == 'K')
		return 13;
		
}

int main(){
	
	string s;
	
	while(1){
		
		int cards[52];
		queue<int> A, B;
		
		// input
		for(int i=0;i<52;i++){
			
			cin >> s;
			
			if(s == "#")
				return 0;
			
			cards[i] = num(s);
			
		}
		
		for(int i=51;i>=0;i--){
			
			if(i%2) A.push(cards[i]);
			else B.push(cards[i]);
			
		}
		
		//play
		int turn = 1;
		int lose = -1;
		queue<int> H;
		while(1){
			
			if(turn == 0 && A.empty()){
				lose = 0;
				break;
			}
			if(turn == 1 && B.empty()){
				lose = 1;
				break;
			}
				
			int card;
			
			if(turn == 0){
				card = A.front();
				A.pop();
			}
			if(turn == 1){
				card = B.front();
				B.pop();
			}
			
			H.push(card);
			
			turn = !turn;
			bool end = false;
			
			while(card>=11 || card == 1){
				
				end = true;
				
				int paid;
				
				if(card == 1)
					paid = 4;
				else
					paid = card - 10;
					
				for(int i=0;i<paid;i++){
					
					if(turn == 0 && A.empty()){
						lose = 0;
						break;
					}
					if(turn == 1 && B.empty()){
						lose = 1;
						break;
					}
					
					if(turn == 0)
						card = A.front(), A.pop();
					if(turn == 1)
						card = B.front(), B.pop();
						
					H.push(card);
						
					if(card>=11 || card == 1)
						break;
						
				}
				
				if(lose >= 0)
					break;
					
				turn = !turn;
				
			}
			
			if(lose >= 0)
				break;
			
			if(end){
				
				if(turn == 0){
					
					while(H.size()){
						
						A.push(H.front());
						H.pop();
						
					}
					
				}
				
				else{
					
					while(H.size()){
						
						B.push(H.front());
						H.pop();
						
					}
					
				}
				
			}
			
		}
		
		cout << 2-lose;
		cout << setw(3) << (lose ? A.size() : B.size());
		cout << "\n";
		
	}
	
	return 0;
}