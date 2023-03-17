#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int a[100005];

struct info{
	int sum,prop;
}tree[100005 * 3];

void init(int node, int lo, int hi){
	if (hi == lo){
		tree[node].sum = a[lo];
		return ;
	}
	int left = node * 2, right = left + 1;
	int mid = (lo + hi) / 2;
	init(left, lo, mid);
	init (right, mid+1, hi);
	tree[node].sum = tree[left].sum + tree[right].sum;
}

int query(int node, int lo, int hi, int i, int j, int carry = 0){
	if(i > hi || j < lo)return 0;
	if(i <= lo && j >= hi) {
		if(carry % 2) return (hi - lo + 1) - tree[node].sum;
		else return tree[node].sum;
	}
	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	int ans1 = query(left, lo, mid, i, j, carry + tree[node].prop);
	int ans2 = query(right, mid + 1, hi, i, j, carry + tree[node].prop);
	return ans1 + ans2;
}
void update(int node, int lo ,int hi, int i, int j){
	if(i > hi || j < lo)return;
	if (i <= lo && j >= hi) {
		tree[node].prop = 1 - tree[node].prop;
		tree[node].sum = (hi - lo + 1) - tree[node].sum;
		return ;
	}

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) /2 ;
	update (left, lo , mid, i , j);
	update(right, mid + 1, hi, i, j);
	if(tree[node].prop) 
		tree[node].sum = (hi - lo + 1) - (tree[left].sum + tree[right].sum);
	else 
		tree[node].sum = tree[left].sum + tree[right].sum ;
}

int main()
{
	fast_io();
 	int cs=1,tc;
 	cin >> tc;
 	while(tc--){
 		string s;
 		cin >> s;
 		int n = s.size();
 		for (int i=0; i<n; i++)a[i]=s[i]-'0';
 		memset(tree, 0 , sizeof(tree));
 		init(1, 0, n-1);
 		int q;
 		cin >> q;
 		cout << "Case " << cs++ << ":\n";
 		while(q--){
 			char c;
 			int i, j;
 			cin >> c;
 			if(c == 'I'){
 				cin >> i >> j;
 				update(1, 0, n-1, i-1, j-1);
 			}
 			else {
 				cin >> i;
 				cout << query(1, 0, n-1, i-1, i-1) << en;
 			}
 		}
 	}
    return 0;
}