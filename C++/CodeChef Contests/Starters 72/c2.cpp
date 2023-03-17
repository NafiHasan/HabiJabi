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
		vector<int> a(n), pre(n + 5, 0);
		for (int i=0; i<n; i++){
			cin >> a[i];
			if(a[i] == 1)pre[i + 1] = pre[i] + 1;
			else pre[i + 1] = pre[i] - 1;
		}
		// priority_queue<int, vector<int>, greater<int>>pq;
		int st = -1, en = -1, mx = INT_MIN;
		int mn = INT_MAX, ind = 1;
		for (int i=0; i<=n; i++){
			if(pre[i] < mn){
				mn = pre[i];
				ind = i;
			}
			if(pre[i] - mn > mx){
				mx = pre[i] - mn;
				st = ind + 1;
				en = i ;
			}
		}
		if(st > en){
			cout << "1\n1\n";
			continue;	
		}
		vector<int> ans;
		ans.push_back(st);
		ans.push_back(st + 1);
		// cout << st << ' ' << en << '\n';
		int cnt1 = 0, cnt0 = 0;
 		if(st != -1)cnt1 =1;
 		for (int i = st; i<en; i++){
 			if(a[i] == 1)cnt1++;
 			else cnt0++;
 			if(cnt1 - cnt0 == (int)ans.size()){
 				ans.push_back(i + 2);
 			}
 		}
 		cout << ans.size() << '\n';
 		for (int i=0; i<ans.size(); i++)cout << ans[i] << ' ';
 		cout << "\n";
	}	
    return 0;
}