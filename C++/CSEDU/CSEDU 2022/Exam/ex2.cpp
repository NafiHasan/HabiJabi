#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int a , b;
 	char c;
 	cin >> a >> b >> c;
 	if(c == '+') cout << a + b << '\n';
 	else if(c == '-') cout << a - b << '\n';
 	else cout << a * b << '\n';	
    return 0;
}