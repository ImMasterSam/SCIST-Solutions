#include<iostream>
#include<sstream>
using namespace std;

bool check(string s1, string s2){
	
	string t1="";
	string t2="";
	
	for(int i=0;i<s1.size();i++){
		t1 += tolower(s1[i]);
	}
	
	for(int i=0;i<s2.size();i++){
		t2 += tolower(s2[i]);
	}
	
	return t1 < t2;
	
}


int main(){
	
	int n;
	cin >> n;
	
	string name, s;
	string t_name[35];
	int point[35] = {0};
	int played[35] = {0};
	int win[35] = {0};
	int tie[35] = {0};
	int lose[35] = {0};
	int scored[35] = {0};
	int against[35] = {0};
	int diff[35] = {0};
	int used[35] = {0};
	int t, g;
	
	cin.ignore();
	
	for(int time=0;time<n;time++){
		
		//reset
		for(int i=0;i<35;i++){
			t_name[i] = "";
			point[i] = 0;
			played[i] = 0;
			win[i] = 0;
			tie[i] = 0;
			lose[i] = 0;
			scored[i] = 0;
			against[i] = 0;
			diff[i] = 0;
			used[i] = 0;
		}
		
		getline(cin, name);
		
		cin >> t;
		cin.ignore();
		for(int i=0;i<t;i++){
			getline(cin, t_name[i]);
		}
		
		cin >> g;
		cin.ignore();
		
		
		int s1, s2;
		
		
		for(int i=0;i<g;i++){
			
			getline(cin, s);
			
			char n1[35], n2[35];
			int s1, s2;
			
			sscanf(s.c_str(), "%[^#]#%d@%d#%[^#]", n1, &s1, &s2, n2);
			
			for(int j=0;j<t;j++){
				
				if(n1 == t_name[j]){
					played[j]++;
					scored[j] += s1;
					against[j] += s2;
					
					if(s1 > s2){
						win[j]++;
						point[j] += 3;
					}
					else if (s1 == s2){
						tie[j]++;
						point[j] += 1;
					}
					else
						lose[j]++;
				}
				
				if(n2 == t_name[j]){
					played[j]++;
					scored[j] += s2;
					against[j] += s1;
					
					if(s1 < s2){
						win[j]++;
						point[j] += 3;
					}
					else if (s1 == s2){
						tie[j]++;
						point[j] += 1;
					}
					else
						lose[j]++;
				}
			}
			
		}
		
		for(int i=0;i<t;i++){
			diff[i] = scored[i] - against[i];
		}
		
		int rank = 1;
		
		cout << name << "\n";
		for(int i=0;i<t;i++){
			
			int index = 0;
			
			while(used[index]){
				index++;
			}
			
			
			for(int j=0;j<t;j++){
				if(used[j])
					continue;
					
				if(point[j] > point[index])
					index = j;
				else if(point[j] == point[index]){
					if(win[j] > win[index])
						index = j;
					else if(win[j] == win[index]){
						if(diff[j] > diff[index])
							index = j;
						else if(diff[j] == diff[index]){
							if(scored[j] > scored[index])
								index = j;
							else if(scored[j] > scored[index]){
								if(played[j] < played[index])
									index = j;
								else if(played[j] == played[index]){
									if(check(t_name[j], t_name[index]))
										index = j;
								}
							}
						}
					}
				}
				
			}
			
			used[index] = 1;
			/*
			for(int k=0;k<t;k++){
				cout << used[k] << " ";
			}
			cout << "\n";*/
			
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)", rank++, t_name[index].c_str(), point[index], played[index], win[index], tie[index], lose[index], diff[index], scored[index], against[index]);
			if(time!=n-1 || i != t-1)
				cout << "\n";
		}
		
		if(time != n-1)
			cout << "\n";
		
	}	
	
	
	return 0;
}