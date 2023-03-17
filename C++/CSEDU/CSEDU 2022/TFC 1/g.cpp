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
 		vector<int>v(n);
 		bool ans = 1;
 		for (int i=0; i<n; i++){
 			cin >> v[i];
 			if(v[i] > (n-1))ans = 0;
 		}
 		sort(v.begin(), v.end());
 		int cnt = 0;
 		if((v[n-1] - v[0]) > 1)ans = 0;
 		if(v[n-1] == v[0]){
 			if(v[0] == 0)cnt = n;
 			else cnt = 0;
 		}
 		else if(ans == 1){
 			int tmp =0;
 			for (int i=0; i<n; i++){
 				if(v[i] == v[0])tmp++;
 			}
 			if(tmp != (v[0] + 1))ans = 0;
 			else cnt = n- (v[0] + 1);
 		}
 		if(ans)cout << cnt << '\n';
 		else cout << "-1\n";
 	}	
    return 0;
}