#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, m;
 		cin >> n;
 		vector<int> a(n), b(n);
 		for(int i=0; i<n; i++)cin>> a[i];
 		for(int i=0; i<n; i++)cin>> b[i];
 		cin >> m;	
 		map<int,int> x;
 		for(int i=0; i<m; i++){
 			int p;
 			cin >> p;
 			x[p]++;
 		}
 		bool ok = 1;
 		for (int i=0; i<n; i++){
 			if(a[i] < b[i]){
 				ok = 0;
 				break;
 			}
 		}
 		if(!ok){
 			cout << "NO\n";
 			continue;
 		}
 		priority_queue<int, vector<int>, greater<int>>pq;
 		vector<int> req;
 		for (int i=0; i<n; i++){
 			if(pq.empty() && a[i] != b[i]){
 				pq.push(b[i]);
 				continue;
 			}
 			if(!pq.empty()){
 				if(b[i] < pq.top() && a[i] != b[i]){
 					pq.push(b[i]);
 				}
 				else {
 					while(!pq.empty()){
 						if(pq.top() < b[i]){
 							req.push_back(pq.top());
 							pq.pop();
 						}
 						else break;
 					}
 					if(a[i] != b[i]){
 						if(!pq.empty() && pq.top() != b[i])pq.push(b[i]);
 						else if(pq.empty())pq.push(b[i]);
 					}
 				}
 			}
 		}
 		while(!pq.empty()){
 			req.push_back(pq.top());
 			pq.pop();
 		}
 		for (int i=0; i<req.size(); i++){
 			// cout << req[i] << '\n';
 			if(x[req[i]] == 0){
 				ok = 0;
 				break;
 			}
 			x[req[i]]--;
 		}
 		if(ok)cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}