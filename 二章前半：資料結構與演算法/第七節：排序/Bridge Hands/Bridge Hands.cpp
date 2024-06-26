#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define f first
#define s second

map<char, int> WAY = {{'S', 0}, {'W', 1}, {'N', 2}, {'E', 3}};
char way[4] = {'S', 'W', 'N', 'E'};
map<char, int> SHAPE = {{'C', 0}, {'D', 1}, {'S', 2}, {'H', 3}};
map<char, int> POINT = {{'2', 0}, {'3', 1}, {'4', 2}, {'5', 3}, {'6', 4}, {'7', 5}, {'8', 6}, {'9', 7}, {'T', 8}, {'J', 9}, {'Q', 10}, {'K', 11}, {'A', 12}};

bool cmp(const pair<char , char> &a, const pair<char , char> &b){
	
	if(a.f != b.f){
		
		return SHAPE[a.f] < SHAPE[b.f];
		
	}
	
	return POINT[a.s] < POINT[b.s];
	
}

int main(){
	
	vector<vector<pair<char , char>>> v(4);
	
	char d;
	
	while(cin >> d){
		
		v.assign(4, vector<pair<char , char>> ());
		
		if(d == '#')
			break;
			
		int dir = WAY[d];
		
		for(int i=0;i<52;i++){
			
			dir = (dir+1)%4;
			
			char s, p;
			cin >> s >> p;
			
			v[dir].emplace_back(s, p);
			
		}
		
		for(int i=0;i<4;i++){
			
			sort(v[i].begin(), v[i].end(), cmp);
			
		}
		
		for(int i=0;i<4;i++){
			
			cout << way[i] << ": ";
			
			for(int j=0;j<13;j++){
				
				if(j)
					cout << " ";
				
				cout << v[i][j].f << v[i][j].s;
				
			}
			
			cout << "\n";
			
		}
		
	}
	
	
	
	return 0;
}