#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
#define MAX 100005

int tree[3*MAX], a[MAX];

void init (int node, int lo, int hi){
	if(lo == hi){
		tree[node] = a[lo];
		return;
	}
	int left = 2 * node , right = left + 1;
	int mid = (lo + hi) / 2;
	init (left, lo, mid);
	init (right, mid + 1 , hi);
	tree[node] = tree[left] + tree[right];
}

int query (int node, int lo, int hi, int i, int j){
	if(i > hi || j < lo) return 0;
	if (i <= lo && j >= hi) return tree[node];
	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	int ans1 = query(left, lo, mid, i, j);
	int ans2 = query(right, mid + 1, hi, i, j);
	return ans1 + ans2;
}

void update (int node, int lo, int hi, int i, int val, int type){
	if(i > hi || i < lo) return;
	if(i == lo && i == hi) {
		int tmp= tree[node];
		if(type==1) tree[node] = val;
		else tree[node] += val;
		if(type ==1)cout << tmp << en;
		return;
	}
	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, val, type);
	update(right, mid + 1, hi, i, val, type);
	int tmp = tree[node];
	tree[node]= tree[left] + tree[right];
	//return tmp;
}

int main()
{
	fast_io();
	int tc, cs=1;
	cin >> tc;
	while(tc--){
		int n, q;
		cin >> n >>q;
		for (int i=0; i<n; i++) cin >> a[i];
		init(1, 0, n-1);
		// for (int i=1; i<3*n; i++) cout << tree[i] << " ";
		// cout << en;
		cout << "Case " << cs++ << ":\n";
		while(q--){
			int t;
			cin >> t;
			if(t == 1){
				int x;
				cin >> x;
				update (1, 0, n-1, x, 0, 1);
			}
			else if(t==2){
				int x, y;
				cin >> x >> y;
				update(1, 0, n-1, x, y, 2);
			}
			else {
				int i, j;
				cin >> i >> j;
				cout << query (1, 0, n-1, i, j) << "\n";
			}
		}
	}
    return 0;
}