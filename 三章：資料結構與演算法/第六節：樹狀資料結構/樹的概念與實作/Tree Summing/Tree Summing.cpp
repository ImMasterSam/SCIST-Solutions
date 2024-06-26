#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

struct node{
	
	int child = 0; // 記錄子結點數量
	int left = -1 , right = -1; // 紀錄是否有子節點 (-1 == 未知)
	
};

int n;
node *root;
bool ans = false;

void input(node *cur, int total){
	
	char c;
	int x;
	
	cin >> c; // read in '('
	
	cin >> x;
	
	// 若'('後的輸入不為整數則上面的 cin >> x 會無法讀入數字
	// 這時 cin 流會進入到錯誤狀態
	// 我們可以利用 cin.clear() 把狀態恢復
	
	if(!cin){
		
		cin.clear();
		cur->child++;
		
		(cur->child&1 ? cur->left = 0 : cur->right = 0);
		
		if(cur->left == 0 && cur->right == 0){
			
			if(n == total)
				ans = true;
			
		}
		
	}
	else{
		
		int nxt = total + x;
		cur->child++;
		(cur->child&1 ? cur->left = 1 : cur->right = 1);
		node *temp = new node;
		input(temp, nxt);
		input(temp, nxt);
		
	}
	
	cin >> c; // read in '('
	
}

int main(){ BOOST

	while(cin >> n){
		
		root = new node;
		ans = false;
		input(root, 0);
		cout << (ans ? "yes" : "no") << "\n";
		
	}
	
	return 0;
}
