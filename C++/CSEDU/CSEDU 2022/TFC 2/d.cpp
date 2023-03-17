#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
	int ans = 0;
 	for (int i=0; i<256; i++){
 		ans += (50 - i)* (50 - i);
 	}	
 	cout << ans << '\n';
    return 0;
}