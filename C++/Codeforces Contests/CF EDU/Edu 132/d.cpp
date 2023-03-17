#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200005;

int a[N], tree[N * 4];

void init (int node , int lo, int hi){
	if(lo == hi){
		tree[node] = a[lo];
		return;
	}
	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2 ;
	init (left, lo, mid);
	init (right, mid + 1, hi);
	tree[node] = max(tree[left] , tree[right]);
}

int query(int node, int lo, int hi, int i, int j){
	if(i > hi || j < lo) return 0;
	if(lo >= i && hi <= j) return tree[node];

	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2;
	return max(query (left, lo, mid, i, j) , query (right, mid + 1, hi, i, j));
}


int main() {
	FastIO;
	int n, m;
	cin >> n >> m;
	for (int i=0; i<m; i++)cin >> a[i];
	init(1, 0, m-1);
	int q;
	cin >> q;
	while(q--){
		int r1, c1, r2, c2, k;
		cin >> r1 >> c1 >> r2 >> c2 >> k;
		if(a[c1 - 1] >= r1 || a[c2 - 1] >= r2 || (abs(r1 - r2) % k) != 0 || (abs(c1 - c2) % k != 0)){
			cout<< "NO\n";
			continue;
		}
		if(c1 == c2){
			cout << "YES\n";
			continue;
		}
		int last = n - ((n - r1) % k);
		int mx = query(1, 0, m - 1, min(c1 - 1, c2 - 1), max(c1 - 1, c2 - 1));
		if(mx >= last){
			cout << "NO\n";
		}
		else cout << "YES\n";
	}
    return 0;
}