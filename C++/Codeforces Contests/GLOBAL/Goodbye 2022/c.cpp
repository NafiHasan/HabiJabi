#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

signed main() {
	FastIO;
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int> a(n);
		map<int,int> mp;
		bool ok = 1;
		int cnt1 = 0, cnt2 = 0;
		for (int i=0; i<n; i++){
			cin>> a[i];
			if(a[i] % 2LL)cnt2++;
			else cnt1++;
			mp[a[i]]++;
			if(mp[a[i]] > 1)ok = 0;
		}
		if(ok){
			if(cnt1 > 1 && cnt2 > 1)cout << "NO\n";
			else cout << "YES\n";
		}
		else cout << "NO\n";
	}	
    return 0;
}
//7
// 2 6 8 10 12 14 16