#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//Don't forget to clear the global variables
// make sure to set the maximum size according to the problem

const int N = 1e5 + 10;

vector<int> par(N), rnk(N,0), siz(N,1);

void makeset(){
	for (int i=1; i<N; i++)par[i] = i;
}

int get(int a) {
	// path compressed, change if needed
  	return (par[a] == a ? a : (par[a] = get(par[a])));
}

void union_set(int a, int b) {
	a = get(a);  // find the topmost parent
	b = get(b);

	if(a == b)return; // are in same set

	if (rnk[a] == rnk[b])rnk[a]++;

	if (rnk[a] > rnk[b])par[b] = a;
	else par[a] = b;
}

void clr(){
	makeset();
	par.clear();
	rnk.clear();
	siz.clear();
}

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		// clr();
 		int n, m;
 		cin >> n >> m;
 		vector<pair<int,int>>ans;
 		int last ;
 		for (int i=0; i<m; i++){
 			int u, mid, v;
 			cin >> u >> mid >> v;
 			if(get(u) != get(v)){
 				ans.push_back({u,v});
 				union_set(u,v);
 			}
 			last = u;
 		}
 		for (int i=1; i<=n; i++){
 			if(i != last && get(last) != get(i)){
 				ans.push_back({last,i});
 				union_set(last,i);
 			}
 		}
 		for (int i=0; i<n-1; i++){
 			cout << ans[i].first << ' ' << ans[i].second<< '\n';
 		}
 		// cout << '\n';
 	}	
    return 0;
}