#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		long long n;
 		cin >> n;
 		cout << -(n-1) << ' ' << n << '\n';
 	}
    return 0;
}