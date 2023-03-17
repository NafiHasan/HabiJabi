#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	char a[100] = "Hello World" , b[100] = "CSEDU";
 	for (int i=0; b[i]; i++){
 		a[i] = b[i];
 	}	
 	cout << a << '\n';
    return 0;
}