#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 270005;
vector<int> edge[N], edge2[N];
vector<bool> vis(N, 0);

int cnt = 0;
void dfs(int u){
	vis[u] = 1;
	cnt++;
	for (int i : edge[u]){
		if(!vis[i]){
			dfs(i);
		}
	}
}


int main() {
	FastIO;
 	int n;
 	cin >> n;
 	string s;
 	cin >> s;
 	vector<int> a;
 	for (int i=1; i<= (1 << n); i++){
 		a.push_back(i);
 	}
 	for (int i=1; i<=n; i++){
 		vector<int> tmp;
 		for (int j=0; j<a.size() - 1; j+=2){
 			if(s[i - 1] == '1' || a[i - 1] == '0'){
 				edge[a[j]].push_back(a[j + 1]);
 				tmp.push_back(a[j]);
 			}
 			else {
 				edge[a[j + 1]].push_back(a[j]);
 				tmp.push_back(a[j]);
 			}
 		}
 		a.clear();
 		for (auto x : tmp){
 			// cout << x << ' ';
 			a.push_back(x);
 		}
 		// cout << '\n';
 	}
 	cnt = 0;
 	dfs(1);
 	int left = cnt - 1;
 	vis.clear();
 	for (int i=1; i<= (1 << n); i++){
 		for (auto j : edge[i]){
 			edge2[j].push_back(i);
 		}
 	}
 	for (int i=1; i<= (1 << n); i++){
 		edge[i].clear();
 		for(auto j : edge2[i])edge[i].push_back(j);
 	}
 	for (int i=0; i<=(1 << n); i++)vis[i] = 0;
 	cnt = 0;
 	dfs(1);
 	int right = cnt - 1;
 	for (int i=left + 1; i<= (1 << n) - right; i++)cout << i << ' ';
 	cout << '\n';
 	// cout << "F";
    return 0;
}