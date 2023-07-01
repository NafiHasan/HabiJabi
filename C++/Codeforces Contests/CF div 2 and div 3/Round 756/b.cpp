#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		long long a, b;
 		cin >> a >> b;
 		long long sum = a+b;
 		sum/=4;
 		sum = min(sum, min(a,b));
 		cout << sum << '\n';
 	}	
    return 0;
}