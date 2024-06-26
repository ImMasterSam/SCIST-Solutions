#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>
using namespace std;

#define f first
#define s second

int n;
double m = DBL_MAX_EXP;
int path[10];
int temp_path[10];
bool used[10] = {0};
pair<int, int> points[10];

double cal(int idx1, int idx2){
	
	return sqrt(pow(points[idx1].f-points[idx2].f, 2) + pow(points[idx1].s-points[idx2].s, 2)) + 16.0;
	
}

void dfs(int depth, double dis, int last){
	
	if(depth == n){
		
		if(dis < m){
			
			m = dis;
			
			for(int i=0;i<10;i++)
				path[i] = temp_path[i];
			
		}
		
		return;
		
	}
	
	for(int i=0;i<n;i++){
		
		if(!used[i]){
			
			double temp = 0.0;
			
			if(last != -1)
				temp = cal(last, i);
			
			used[i] = true;
			temp_path[depth] = i;
			dfs(depth+1, dis+temp, i);
			used[i] = false;
			
		}
		
	}
	
}

int main(){
	
	int times = 1;
	
	cout << fixed << setprecision(2);
	
	while(cin >> n, n){
		
		for(int i=0;i<n;i++)
			cin >> points[i].f >> points[i].s;
			
		cout << "**********************************************************\n";
		cout << "Network #" << times++ << "\n";
		
		m = DBL_MAX_EXP;
		dfs(0, 0.0, -1);
		
		for(int i=1;i<n;i++){
			
			cout << "Cable requirement to connect (" << points[path[i-1]].f << "," << points[path[i-1]].s << ") to (" << points[path[i]].f << "," << points[path[i]].s << ") is " << cal(path[i-1], path[i]) << " feet.\n";
			
		}
		
		cout << "Number of feet of cable required is " << m << ".\n";
		
	}
	
	return 0;
}