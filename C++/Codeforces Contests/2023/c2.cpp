#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

signed main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, m;
 		cin >> n>> m;
 		vector<int> a(n);
 		for (int i=0; i<n; i++)cin >> a[i];

 		int ans = 0, sum = 0;
 		priority_queue<int> pq;
 		priority_queue<int, vector<int>, greater<int>> mn;
 		for (int i = m- 1; i>0; i--){
 			sum += a[i];
 			if(a[i] > 0)pq.push(a[i]);
 			while(sum > 0 && pq.size() > 0){
 				ans++;
 				sum -= 2LL * pq.top();
 				pq.pop();
 			}
 		}
 		sum = 0;
 		
 		for (int i=m; i<n; i++){
 			sum += a[i];
 			if(a[i] < 0)mn.push(a[i]);
 			while(sum < 0 && mn.size() > 0){
 				ans++;
 				sum -= 2LL * mn.top();
 				// cout << mn.top() << '\n';
 				mn.pop();
 			}
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}