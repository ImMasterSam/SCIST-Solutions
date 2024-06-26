#include<iostream>
#include<sstream>
using namespace std;

int main(){
	
	char msg[128];
	char item_name[5] = "Iron";
	int item_count = 64;
	
	sprintf(msg, "get item [%s] x %d!!\n", item_name, item_count);
	
	puts(msg);
	
	return 0;
}