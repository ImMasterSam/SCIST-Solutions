#include <iostream>
using namespace std;

int main(){
	long long t, p, r, f, count;
	cin >> t;
	
	for(int i=0;i<t;i++){
		cin >> p >> r >> f;
		if(p>f)
			cout << "0\n";
		else{
			count = 1;
			f /= p;
			while(f/r>0){
				f /= r;
				count++;
			}
			
			cout << count << "\n";
		}
	}
	
	return 0;
}

