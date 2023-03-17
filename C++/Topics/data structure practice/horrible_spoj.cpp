#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

long long a[100005];

struct info{
	long long prop,sum;
}tree[100005 * 3];

// void init(int node, int lo, int hi){
// 	if(lo == hi){
// 		tree[node].sum = a[lo];
// 		return;
// 	}

// 	int left = 2 * node, right = left + 1;
// 	int mid = (lo + hi) / 2;
// 	init(left, lo, mid);
// 	init(right , mid + 1, hi);
// 	tree[node].sum = tree[left].sum + tree[right].sum;
// }

long long query(int node, int lo, int hi, int i, int j, long long carry = 0LL){
	if(i > hi || j < lo) return 0;
	if(i <= lo && j >= hi) return tree[node].sum + (carry * (hi- lo + 1) * 1LL);

	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2;
	long long ans1 = query(left, lo, mid , i, j, carry + tree[node].prop);
	long long ans2 = query(right, mid + 1, hi , i, j, carry + tree[node].prop);
	return ans1 + ans2;
}

void update(int node, int lo, int hi, int i, int j, long long val){
	if(i > hi || j < lo) return;
	if(i <= lo && j >= hi) {
		tree[node].sum += (hi - lo + 1) * 1LL * val;
		tree[node].prop += val;
		return;
	}

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, j, val);
	update(right, mid + 1, hi, i, j, val);
	tree[node].sum = tree[left].sum + tree[right].sum + (hi - lo + 1) * tree[node].prop * 1LL;
}

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, c;
 		cin >> n >> c;
 		// init(1, 0, n-1);
 		memset(tree,0LL,sizeof(tree));
 		// cout << tree[0].sum << " " << tree[0].prop << en;
 		while(c--){
 			int t;
 			cin >> t;
 			if(t){
 				int i,j;
 				cin >> i >> j;
 				cout << query(1, 0, n-1, i-1, j-1, 0LL) << "\n";
 			}
 			else {
 				int i, j;
 				long long val;
 				cin >> i >> j >> val;
 				update(1, 0, n-1, i-1, j-1, val);
 			}
 		}
 	}
    return 0;
}