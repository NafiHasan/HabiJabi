#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		long long n, m, k;
 		cin >> n >> m >>k;
 		if(m < (n-1) || m > (n*(n-1)/2)){
 			cout << "NO\n";
 			continue;
 		}
 		long long need = 0;
 		if(m < (n*(n-1)/2))need = 2;
 		else need = 1;
 		if(n == 1 && m == 0) need = 0;
 		else if(n == 2 && m == 1)need =1; 
 		if(need < (k-1))cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}