#include<iostream>
using namespace std;

struct stack{
	
	const int NOT_EXIST = -1;
	
	int top = 0;
	int stack[1024];
	
	bool is_empty(){
		
		return top == 0;
		
	}
	
	int length(){
		
		return top;
		
	}
	
	void clear(){
		
		top = 0;
		
	}
	
	int get_top(){
		
		int res = NOT_EXIST;
		if(!is_empty()){
			
			res = stack[top-1];
			
		}
		return res;
		
	}
	
	void push(int data){
		
		stack[top++] = data;
		
	}
	
	int pop(){
		
		int res = NOT_EXIST;
		
		if(!is_empty()){
			
			res = stack[--top];
			
		}
		return res;
		
	}
	
};

int main(){
	
	
	
	return 0;
}