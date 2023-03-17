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
 		cin >> n >> m;
 		vector<int> b(m);
 		priority_queue<int, vector<int>, greater<int>> pq;
 		for (int i=0; i<n; i++){
 			int x;
 			cin >> x;
 			pq.push(x);
 		}
 		for (int i=0; i<m; i++)cin >> b[i];
 		for (int i=0; i<m; i++){
 			pq.pop();
 			pq.push(b[i]);
 		}
 		int sum = 0;
 		while(pq.size() > 0){
 			sum += pq.top();
 			pq.pop();
 		}
 		cout << sum << '\n';
 	}
    return 0;
}