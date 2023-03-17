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
 		ll a,b,c;
 		cin >> a >>b >>c;
 		a--,b--;
 		c=pow(10,c-1);
 		ll x=pow(10,a);
 		ll y=(pow(10,b))+c;
 		cout << x << " " << y  << en;
 	}	
    return 0;
}