#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int a[100000], last = 0;

void push(int num){
	a[last++] = num;
}

int top(){
	return a[last - 1];
}

int pop(){
	if(last == 0){
		cout << "Stack is empty\n";
		return -1;
	}
	return a[--last];
}

int main()
{
	fast_io();
 	push(5);
 	push(10);
 	push(15);
 	cout << top() << '\n';
 	cout << pop() << '\n';
 	cout << top() << '\n';
    return 0;
}