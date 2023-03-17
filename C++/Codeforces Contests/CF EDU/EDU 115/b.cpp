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
 		vector<int>v[5];
 		bool ans = 0;
 		for (int i=0; i<n; i++){
 			for (int j=0; j<5; j++){
 				int x;
 				cin >> x;
 				if(x == 1)v[j].push_back(i);
 			}
 		}
 		for (int i=0; i<4; i++){
 			for (int j=i+1; j<5; j++){
 				vector<int>cnt(n+5,0);
 				for (int k=0; k<v[i].size(); k++){
 					cnt[v[i][k]]++;
 				}
 				for (int k=0; k<v[j].size(); k++){
 					cnt[v[j][k]]++;
 					// cout << v[j][k] << 'a';
 				}
 				int need1 = n/2, need2 = n/2;
 				for (int k=0; k<v[i].size(); k++)if(cnt[v[i][k]] == 1)need1--;
 				for (int k=0; k<v[j].size(); k++)if(cnt[v[j][k]] == 1)need2--;
 				int one = 0, two = 0;
 				for (int k = 0; k<n; k++){
					if(cnt[k] == 2)two++;
 				}
 				need1 = max(0,need1);
 				need2 = max(0, need2);
 				if(((need1 + need2) - two) <= 0){
 					ans = 1;
 					// cout << i << ' ' << j << '\n';
 					i = 5;
 					break;
 				}
 			}
 		}
 		if(ans == 1)cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}