#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

vector<int>a(100005), tree(3*100005);

void init(int node, int lo, int hi){
	if(lo == hi){
		tree[node] = a[lo];
		return; 
	}
	int left = node * 2, right = left + 1;
	int mid = (lo + hi) / 2;
	init(left, lo, mid);	
	init(right, mid + 1, hi);
	tree[node] = min(tree[left], tree[right]);	
}

int query(int node, int lo, int hi, int i, int j){
	if(i > hi || j < lo)return INT_MAX;
	if (lo >= i && hi <= j) return tree[node];
	int left = node * 2, right = left + 1;
	int mid = (lo + hi) / 2;
	int ans1 = query(left, lo, mid, i, j);
	int ans2 = query(right, mid + 1, hi, i, j);
	return min(ans1, ans2);
}
int main()
{
	fast_io();
 	int tc,cs=1;
 	cin >> tc;
 	while(tc--){
 		int n, m;
 		cin >> n >> m;
 		for (int i=0; i<n; i++)cin >> a[i];
 		init(1,0,n-1);
 		cout << "Case " << cs++ << ":\n";
 		while(m--){
 			int i, j;
 			cin >> i >> j ;
 			i--, j--;
 			int ans= query(1, 0, n-1, i, j);
 			cout << ans << "\n";
 		}
 	}
    return 0;
}