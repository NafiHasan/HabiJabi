#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main()
{
	fast_io();
	string s;
 	cin >> s;
 	int n = s.size();
 	ll ans = 0;
 	for (int i=0; i<s.size(); i++){
 		for (int j = 1; j<=(n-i); j++){
 			string sub = s.substr(i,j);
 			ll sz = i;
 			ll rem = n - (int)sub.size() - i - 1;
 			rem = max(rem, 0LL);
 			ll rem2 = sz-1;
 			rem2 = max(0LL, rem2);
 			ans += stoll(sub) * pow(2LL, (rem + rem2));
 		}
 	}	
 	cout << ans << '\n';
    return 0;
}