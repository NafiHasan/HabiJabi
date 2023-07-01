#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

signed main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, k;
 		cin >> n >> k;
 		vector<int> h(n), p(n);
 		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
 		for (int i=0; i<n; i++)cin >> h[i];
 		for (int i=0; i<n; i++)cin >> p[i];
 		for (int i=0; i<n; i++){
 			pq.push({p[i], h[i]});
 		}
 		int dec = k;
 		while(k > 0 && !pq.empty()){
 			// cout << dec << ' ' << k << '\n' ;
 			pair<int,int> tp = pq.top();
 			pq.pop();
 			tp.second -= dec;
 			if(tp.second > 0){
 				tp.second += dec;
 				pq.push(tp);
 				k -= tp.first;
 			}
 			else {
 				while(!pq.empty() && pq.top().second - dec <= 0)pq.pop();
 				k -= pq.top().first;
 			}
 			if(k > 0){
 				dec += k;
 			}
 			// cout << pq.size() << '\n';
 		}
 		if(pq.size() > 0){
 			cout << "NO\n";
 		}
 		else cout << "YES\n";
 	}	
    return 0;
}