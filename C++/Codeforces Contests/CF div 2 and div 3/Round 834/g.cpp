#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		int m = n/2;
 		vector<int> a(m);
 		map<int,int> mp;
 		for (int i=0; i<m; i++){
 			cin >> a[i];
 			mp[a[i]]++;
 		}
 		set<int, greater<int>> st;
 		for (int i=1; i<=n ;i++){
 			if(mp[i] == 0)st.insert(i);
 		}
 		// for (auto x : st)cout << x << ' ';
 		vector<int> b(m);
 		bool f = 1;
 		for (int i=m - 1; i>=0; i--){
 			if(st.upper_bound(a[i]) == st.end()){
 				f = 0;
 				break;
 			}
 			b[i] = *st.lower_bound(a[i]);
 			// cout << b[i] << '\n';
 			st.erase(st.find(b[i]));
 		}
 		mp.clear();
 		vector<int> ans(n);
 		for (int i=0; i<n; i+=2){
 			ans[i] = a[i/2];
 			ans[i + 1] = b[i/2];
 		}
 		for (int i=0; i<n; i++){
 			mp[ans[i]]++;
 			if(ans[i] > n || mp[ans[i]] > 1){
 				f = 0;
 				break;
 			}
 		}
 		if(!f){
 			cout << "-1\n";
 			continue;
 		}
 		for (int i=0; i<m; i++)cout << min(a[i], b[i]) << ' '<< max(a[i], b[i]) << ' ';
 		cout << '\n';
 	}
    return 0;
}