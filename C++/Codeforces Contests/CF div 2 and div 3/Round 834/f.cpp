#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, p;
 		cin >> n >> p;
 		map<int,int> mp;
 		vector<int> a(n);
 		set<int> st;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			mp[a[i]]++;
 			st.insert(a[i]);
 		}
 		int tmp = a[n -1];
 		int sm = - 1, bg = -1;
 		for (auto i : st){
 			if(i >= a[n - 1] && mp[i - 1] == 0 && i > 0){
 				bg = i - 1;
 			}
 		}
 		if(mp[p - 1] == 0)bg = p - 1;

 		for (auto i : st){
 			if(i <= a[n - 1]){
 				if(mp[i - 1] == 0 && i > 0)sm = i - 1;
 				if(mp[i + 1] == 0 && i < p - 1 && i + 1 <= a[n - 1])sm = i + 1;
 			}
 		}
 		if(sm == -1 && bg != -1){
 			cout << bg - a[n -1] << '\n';
 			continue;
 		}
 		if(sm == -1 && bg == -1){
 			cout << "0\n";
 			continue;
 		}
 		int ans = p - a[n - 1];
 		mp[0]++;
 		int i = n - 2, inc = 1;
 		while(i >= 0 && inc){
 			a[i] += 1;
 			if(a[i] >= p){
 				a[i] = 0;
 			}
 			else {
 				inc = 0;
 			}
 			mp[a[i]]++;
 			st.insert(a[i]);
 			i--;
 		}
 		if(i < 0 && inc){
 			mp[1]++;
 			st.insert(1);
 		}
 		for (auto i : st){
 			if(i <= tmp){
 				if(mp[i + 1] == 0 && i < p - 1 && i + 1 <= tmp)sm = i + 1;
 				if(mp[i - 1] == 0 && i > 0)sm = i - 1;
 			}
 		}
 		if(mp[sm] == 0){
 			ans += sm;
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}