#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int a, b, c;
 		cin >> a >> b >> c;
 		if((a+b+c) %3 == 0)cout << "0\n";
 		else cout << "1\n";
 	}	
    return 0;
}