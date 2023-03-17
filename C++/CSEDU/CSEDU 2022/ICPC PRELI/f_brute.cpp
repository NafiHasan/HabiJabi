#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	w(t){
 		int a,b,m;
 		cin >> a >> b >>m;
 		for (int i=0; i<=m; i++){
 			if(__gcd(a+i,b+i) == 1)cout << a+i << " " << b+i <<en;
 		}
 	}	
    return 0;
}