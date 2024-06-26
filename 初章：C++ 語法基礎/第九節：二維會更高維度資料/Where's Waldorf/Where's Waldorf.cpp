#include<iostream>
using namespace std;

char a[60][60];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t, r, c, n;
	cin >> t;
	
	string s, temp;
	int x, y;
	
	for(int time=0;time<t;time++){
		
		cin >> r >> c;
		
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				cin >> a[i][j];
		}
		
		cin >> n;
		
		for(int num=0;num<n;num++){
			
			bool found = false;
			
			cin >> s;
			
			for(int i=0;i<(int)s.size();i++)
				s[i] = tolower(s[i]);
			
			temp.resize(s.size(), ' ');
			
			for(int i=0;i<r and !found;i++){
				for(int j=0;j<c and !found;j++){
					
					//left
					if(j>=(int)s.size()-1  and !found){
						for(int k=j;k>=j-(int)s.size();k--)
							temp[j-k] = tolower(a[i][k]);
						if(s==temp){
							cout << i+1 << " " << j+1 << "\n";
							found = true;
						}
					}
					
					//right
					if(j<= c - (int)s.size()  and !found){
						for(int k=j;k<=j+(int)s.size();k++)
							temp[k-j] = tolower(a[i][k]);
						if(s==temp){
							cout << i+1 << " " << j+1 << "\n";
							found = true;
						}
					}
					
					//up
					if(i>=(int)s.size()-1  and !found){
						for(int k=i;k>=i-(int)s.size();k--)
							temp[i-k] = tolower(a[k][j]);
						if(s==temp){
							cout << i+1 << " " << j+1 << "\n";
							found = true;
						}
					}
					
					//down
					if(i<= r - (int)s.size()  and !found){
						for(int k=i;k<=i+(int)s.size();k++)
							temp[k-i] = tolower(a[k][j]);
						if(s==temp){
							cout << i+1 << " " << j+1 << "\n";
							found = true;
						}
					}
					
					//left up
					if(j>=(int)s.size()-1 and i>=(int)s.size()-1 and !found){
						for(int k=0;k<(int)s.size();k++)
							temp[k] = tolower(a[i-k][j-k]);
						if(s==temp){
							cout << i+1 << " " << j+1 << "\n";
							found = true;
						}
					}
					
					//right up
					if(j<= c - (int)s.size() and i>=(int)s.size()-1 and !found){
						for(int k=0;k<(int)s.size();k++)
							temp[k] = tolower(a[i-k][j+k]);
						if(s==temp){
							cout << i+1 << " " << j+1 << "\n";
							found = true;
						}
					}
					
					//left down
					if(j>=(int)s.size()-1 and i<= r - (int)s.size() and !found){
						for(int k=0;k<(int)s.size();k++)
							temp[k] = tolower(a[i+k][j-k]);
						if(s==temp){
							cout << i+1 << " " << j+1 << "\n";
							found = true;
						}
					}
					
					//right down
					if(j<= c - (int)s.size() and i<= r - (int)s.size() and !found){
						for(int k=0;k<(int)s.size();k++)
							temp[k] = tolower(a[i+k][j+k]);
						if(s==temp){
							cout << i+1 << " " << j+1 << '\n';
							found = true;
						}
					}
					
				}
			}
			
		}
		if(time != t-1)
			cout << '\n';
		
	}
		
	return 0;
}