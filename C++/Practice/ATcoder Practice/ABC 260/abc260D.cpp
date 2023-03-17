#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int n, k;
 	cin >> n>> k;
 	vector<int> a(n);
 	for (int i=0; i<n; i++)cin>> a[i];
 	vector<int> grp[n + 5], ans(n + 5, -1), tm(n + 5, -1);
 	if(k == 1){
 		for (int i=0; i<n; i++)ans[a[i] - 1] = i + 1;
 		for (int i=0; i<n; i++)cout << ans[i] << '\n';
 		return 0;
 	}
 	set<int> st, st2;
 	for (int i=0; i<n; i++){
 		if(st.lower_bound(a[i]) != st.end()){
 			int now = *st.lower_bound(a[i]);
 			tm[a[i]] = tm[now];
 			grp[tm[now]].push_back(a[i]);
 			st.erase(now);
 			st.insert(a[i]);
 			if(grp[tm[a[i]]].size() == k){
 				st2.insert(a[i]);
 				ans[a[i]] = i + 1;
 				st.erase(a[i]);
 			}
 		}
 		else {
 			grp[a[i]].push_back(a[i]);
 			tm[a[i]] = a[i];
 			st.insert(a[i]);
 		}
 	}
 	for (auto it = st2.begin(); it != st2.end(); it++){
 		int tmp = *it;
 		for (int i=0; i<grp[tm[tmp]].size(); i++)
 			ans[grp[tm[tmp]][i]] = ans[grp[tm[tmp]].back()];
 	}
 	for (int i=0; i<n; i++)cout<< ans[i + 1] << '\n'; 
    return 0;
}