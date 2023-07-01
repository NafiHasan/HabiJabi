#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin>> tc;
 	while(tc--){
 		int n;
 		string s;
 		cin >> n;
 		vector<int>v(n), b, r;
 		for (int i=0; i<n; i++){
 			cin >> v[i];
 		}
 		cin >> s;
 		for (int i=0; i<n; i++){
 			if( s[i] == 'B') b.push_back(v[i]);
 			else r.push_back(v[i]);
 		}
 		sort(b.rbegin(), b.rend());
 		sort(r.rbegin(), r.rend());
 		bool ans = 1;
 		for (int i=1; i<=n; i++){
 			if(!b.empty() && b.back() >= i)b.pop_back();
 			else if(!r.empty() && r.back() <= i)r.pop_back();
 			else {
 				ans = 0;
 				// cout << 'n';
 				// cout << i << '\n';
 				break;
 			}
 		}
 		if(!b.empty() || !r.empty())ans = 0;
 		if(ans)cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}