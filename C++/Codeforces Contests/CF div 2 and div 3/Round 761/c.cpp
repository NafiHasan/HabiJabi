#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		vector<int>a(n), b(n+1, 0), got, need;
 		map <int,int> m;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			m[a[i]]++;
 			if(a[i] <= n)b[a[i]]++;
 			if(a[i] > n || m[a[i]] > 1){
 				a[i] = (a[i] - 1 ) / 2;			
 				got.push_back(a[i]);
 			}
 		}
 		for (int i=1; i<=n; i++)if(b[i] == 0)need.push_back(i);
 		sort(need.begin(), need.end());
 		sort(got.begin(), got.end());
 		bool ans = 1;
 		int cnt =0;
 		if(need.size() == got.size()){
 			for (int i=0; i<need.size(); i++){
 				if(need[i] <= got[i])cnt++;
 				else ans = 0;
 			}
 		}
 		if(need.size() != got.size())ans = 0;
 		if(ans)cout << cnt << '\n';
 		else cout << "-1\n";
 	}	
    return 0;
}