#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)



const int N = 35;
vector<int> edge[N];
vector<bool> vis(N, 0);
int cnt = 0;
map<int, int> got;
void dfs(int u){
	vis[u] = 1;
	if(got[u] == 0){
		got[u]++;
		cnt++;
	}
	for (int i : edge[u]){
		if(!vis[i]){
			dfs(i);
		}
	}
}



int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n; cin >> n;
 		string s; cin >> s;
 		string ans = "";
 		map<char, char> mp;
 		for (int i=0; i<26; i++) mp['a' + i] = '$';
 		for (int i=0; i<30; i++) edge[i].clear();
 		vector<int> taken(30, 1);
 		for (int i=0; i<n; i++){
 			if(mp[s[i]] != '$') ans += mp[s[i]];
 			else {
 				char cc = '&';
 				for (int j=0; j<30; j++){
 					if(s[i] == ('a' + (j % 26)))continue;
 					if(taken[j] == 0)continue;
 					for (int k = 0; k<30; k++)vis[k] = 0;
 					cnt = 0;
 					got.clear();
 					dfs(j % 26);
 					if(cnt < 26 && vis[s[i] - 'a'] == 1)continue;
 					edge[s[i] - 'a'].push_back(j);
 					cc = 'a' + (j % 26);
 					taken[j] = 0;
 					break; 
 				}
 				mp[s[i]] = cc;
 				ans += cc;
 			}
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}