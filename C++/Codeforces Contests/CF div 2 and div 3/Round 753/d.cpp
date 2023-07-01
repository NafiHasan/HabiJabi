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
 		cin >> n;
 		string s;
 		deque<int>b,r, cnt(n,0);
 		deque<pair<int, char>>v(n);
 		for (int i=0; i<n; i++){
 			cin >> v[i].first;
 			cnt[v[i].first]++;
 		}
 		cin >> s;
 		for (int i=0; i<n; i++){
 			if(s[i]== 'B'){
 				b.push_back(v[i].first);
 				v[i].second = 'B';
 			}
 			else {
 				r.push_back(v[i].first);
 				v[i].second  = 'R';
 			}
 		}
 		sort(b.begin(), b.end());
 		sort(r.begin(), r.end());
 		sort(v.begin(), v.end());
 		bool ans = 1;
 		for (int i=1; i<=n; i++){
 			if(cnt[i] == 0){
 				if(b.back() < i && )
 			}
 		}
 	}	
    return 0;
}