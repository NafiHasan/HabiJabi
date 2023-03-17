#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	ll n;
 	string s;
 	cin >> n >>s;
 	ll cnt=0;
 	for (int i=0; i<s.size(); i++)if (s[i]=='1')cnt++;	
 	if ((ll)s.size() > n){
 		cout << "0\n";
 		return 0;
 	}
 	else {
 		ll st=(n-cnt);
 		ll ans = pow(2LL,st);
 		ll cnt2=n-(ll)s.size()+1;
 		ll fact=1;
 		for (ll i=2; i<=cnt2; i++)fact*=i;
 		cout << fact*ans <<en;
 	}
    return 0;
}