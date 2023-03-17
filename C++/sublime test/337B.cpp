#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	#endif
}

int main()
{
	fast_io();
    file_io();
 	ll a, b, c,d;
 	cin >> a >> b >> c >> d;
 	ll area1=a*b , area2=c*d;
 	for (ll i=2; ;i++){
 		area1=a*b*i*i;
 		if (area1>=area2){
 			break;
 		}
 	}	
 	ll p=area1-area2, q=area1;
 	ll div=__gcd(p,q);
 	p/=div;
 	q/=div;
 	cout << p << "/" << q << en;
    return 0;
}