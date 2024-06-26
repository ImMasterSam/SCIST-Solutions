#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > piles(30);
int position[30][30] = {0};


void move_onto(int a, int b){
	
	int pa = position[a][0], pb = position[b][0];
	
	
	for(int i=piles[pa].size()-1;i>position[a][1];i--){
		
		position[piles[pa][i]][0] = piles[pa][i];
		position[piles[pa][i]][1] = piles[piles[pa][i]].size();
		
		piles[piles[pa][i]].push_back(piles[pa][i]);
		piles[pa].pop_back();
	}
	
	for(int i=piles[pb].size()-1;i>position[b][1];i--){
		
		position[piles[pb][i]][0] = piles[pb][i];
		position[piles[pb][i]][1] = piles[piles[pb][i]].size();
		
		piles[piles[pb][i]].push_back(piles[pb][i]);
		piles[pb].pop_back();
	}
	
	
	
	piles[pa].pop_back();
	position[a][0] = pb;
	position[a][1] = piles[pb].size();
	piles[pb].push_back(a);

}

void move_over(int a, int b){
	
	int pa = position[a][0], pb = position[b][0];
	
	
	for(int i=piles[pa].size()-1;i>position[a][1];i--){
		
		position[piles[pa][i]][0] = piles[pa][i];
		position[piles[pa][i]][1] = piles[piles[pa][i]].size();
		
		piles[piles[pa][i]].push_back(piles[pa][i]);
		piles[pa].pop_back();
	}
	
	
	
	piles[pa].pop_back();
	position[a][0] = pb;
	position[a][1] = piles[pb].size();
	piles[pb].push_back(a);

}

void pile_onto(int a, int b){
	
	int pa = position[a][0], pb = position[b][0];
	int sublen = piles[pa].size() - position[a][1];
	
	for(int i=piles[pb].size()-1;i>position[b][1];i--){
		
		position[piles[pb][i]][0] = piles[pb][i];
		position[piles[pb][i]][1] = piles[piles[pb][i]].size();
		
		piles[piles[pb][i]].push_back(piles[pb][i]);
		piles[pb].pop_back();
	}
	
	for(int i=position[a][1];i<piles[pa].size();i++){
		
		position[piles[pa][i]][0] = pb;
		position[piles[pa][i]][1] = piles[pb].size();
		
		piles[pb].push_back(piles[pa][i]);
	}
	
	for(int i=0;i<sublen;i++)
		piles[pa].pop_back();

}

void pile_over(int a, int b){
	
	int pa = position[a][0], pb = position[b][0];
	int sublen = piles[pa].size() - position[a][1];
	
	for(int i=position[a][1];i<piles[pa].size();i++){
		
		position[piles[pa][i]][0] = pb;
		position[piles[pa][i]][1] = piles[pb].size();
		
		piles[pb].push_back(piles[pa][i]);
	}
	
	for(int i=0;i<sublen;i++)
		piles[pa].pop_back();

}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	string act, prep;
	int a, b;
	while(cin >> n){
		
		for(int i=0;i<n;i++){
			position[i][0] = i;
			position[i][1] = 0;
			piles[i].clear();
			piles[i].push_back(i);
		}
		
		cin >> act;
		
		while(act != "quit"){
			cin >> a >> prep >> b;
			if(position[a][0]!=position[b][0]){
				if(act == "move"){ 
					if(prep == "onto")
						move_onto(a, b);
					else if(prep == "over")
						move_over(a, b);
				}
				else if(act == "pile"){
					if(prep == "onto")
						pile_onto(a, b);
					else if(prep == "over")
						pile_over(a, b);
				}
			}
			
			cin >> act;
		}
		
		for(int i=0;i<n;i++){
			cout << i << ":";
			
			for(auto i : piles[i]){
				cout << " " << i;
			}
			cout << "\n";
		}
		/*
		for(int i=0;i<n;i++){
			cout << i << ": " << position[i][0] << " " << position[i][1] << "\n";
		}
		*/
	}
	
	return 0;
}