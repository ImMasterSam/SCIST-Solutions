#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>
using namespace std;

#define f first
#define s second

int n;
pair<int, int> points[10];
bool used[10] = {0};
double m = DBL_MAX_EXP;

double cal(int idx1, int idx2){
	
	return sqrt(pow(points[idx1].f-points[idx2].f, 2) + pow(points[idx1].s-points[idx2].s, 2));
	
}

void dfs(int depth, int target, double dis, int last){
	
	if(depth == target){
		
		if(dis < m)
			m = dis;
		
		return;
		
	}
	
	for(int i=0;i<n;i++){
		
		if(!used[i]){
			
			double temp = 0.0;
			
			if(last != -1)
				temp = cal(last, i);
			
			used[i] = true;
			dfs(depth+1, target, dis+temp, i);
			used[i] = false;
			
		}
		
	}
	
}

int main(){
	
	cin >> n;
	
	for(int i=0;i<n;i++)
		cin >> points[i].f >> points[i].s;
	
	dfs(0, n, 0.0, -1);
	
	cout << fixed << setprecision(2) << m;
	
	
	return 0;
}