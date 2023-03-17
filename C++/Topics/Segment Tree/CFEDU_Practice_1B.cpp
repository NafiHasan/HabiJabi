#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 300010;
map<int,int> mp;

pair<int,int> tree[N * 2];
int n;

// void clear(){
// 	for (int i=0; i <= 2 * n; i++) tree[i]= 0;
// }

void init (){
	for (int i = n - 1; i > 0; --i) {
		tree[i].first = min(tree[i << 1].first , tree[i << 1 | 1].first);
		if(tree[i << 1].first == tree[i << 1 | 1].first)
			tree[i].second = tree[i << 1].second = tree[i << 1 | 1].second;
		else {
			if(tree[i << 1].first > tree[i << 1 | 1].first)tree[i].second = tree[i << 1 | 1].second;
			else tree[i].second = tree[i << 1].second;
		}
	}
}

void update(int pos, int value){
	for (tree[pos += n].first = value; pos > 1; pos >>= 1) {
		tree[pos >> 1].first = min(tree[pos].first , tree[pos ^ 1].first);
		
		if(tree[pos].first == tree[pos ^ 1].first)
			tree[pos >> 1].second = tree[pos].second + tree[pos ^ 1].second;
		else {
			if(tree[pos].first > tree[pos ^ 1].first)
				tree[pos >> 1].second = tree[pos ^ 1].second;
			else 
				tree[pos >> 1].second = tree[pos].second;
		}
	}
}

pair<int,int> query(int l, int r){
	int res = INT_MAX, cnt = 0;
  	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    	if (l&1){
    		// cout << l << " l " << r << ' ' << tree[l].first << '\n';
    		if(res > tree[l].first){
    			res = tree[l].first;
    			cnt = tree[l].second;
    		}
    		else if(res == tree[l].first){
    			res = tree[l].first;
    			cnt += tree[l].second;
    		}
    		l++;
    		// res = min(res, tree[l]);
    	}
    	if (r&1) {
    		r--;
    		// cout << r << " r " << l << ' ' << tree[r].first << '\n';
    		// res = min(res, tree[--r]);
    		if(res > tree[r].first){
    			res = tree[r].first;
    			cnt = tree[r].second;
    		}
    		else if(res >= tree[r].first){
    			res = tree[r].first;
    			cnt += tree[r].second;
    		}
    	}
  	}
  	return {res, cnt};
}


int main() {
	// FastIO;
	int q;
	cin >> n >> q;
	for (int i=0; i<n; i++){
		cin >> tree[i + n].first; 
		tree[i + n].second = 1;
	}

	init();

	while(q--){
		int t, u, v;
		cin >> t >> u >> v;
		if(t == 1){
			update(u, v);
		}
		else {
			pair<int, int> ans = query(u, v);
			cout << ans.first << ' ' << ans.second << '\n';
		}
	}
    return 0;
}