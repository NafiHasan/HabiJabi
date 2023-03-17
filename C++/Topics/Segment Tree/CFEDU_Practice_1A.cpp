#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 300010;

long long tree[N * 2];
int n;

void clear(int n){
	for (int i=0; i <= 2 * n; i++) tree[i]= 0;
}

void init (){
	for (int i = n - 1; i > 0; --i) tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

void update(int pos, int value){
	for (tree[pos += n] = value; pos > 1; pos >>= 1) tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
}

long long query(int l, int r){
	long long res = 0;
  	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    	if (l&1) res += tree[l++];
    	if (r&1) res += tree[--r];
  	}
  	return res;
}


int main() {
	// FastIO;
	int q;
	cin >> n >> q;
	for (int i=0; i<n; i++)cin >> tree[i + n]; 

	init();

	while(q--){
		int t, u, v;
		cin >> t >> u >> v;
		if(t == 1){
			update(u, v);
		}
		else {
			cout << query(u, v) << '\n';
		}
	}
    return 0;
}