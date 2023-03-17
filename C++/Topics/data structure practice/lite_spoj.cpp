#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

struct info{
	int prop, sum;  // sum --> how many lights are turned on
	                // prop --> 0/1 -
} tree[3 * 100005];

int query(int node, int lo, int hi, int i, int j, int carry = 0){
	if(i > hi || j < lo) return 0;
	if(i <= lo && j >= hi){
		if(carry % 2) return (hi - lo + 1) - tree[node].sum;
		else return tree[node].sum;
	}

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	int ans1= query(left, lo, mid, i, j, carry + tree[node].prop);
	int ans2 = query(right, mid + 1, hi, i, j , carry + tree[node].prop);
	return ans1 + ans2;
}

void update(int node, int lo, int hi, int i, int j){
	if(i > hi || j < lo) return;
	if(i <= lo && j >= hi){
		tree[node].prop = 1 - tree[node].prop;
		tree[node].sum = (hi - lo + 1) - tree[node].sum;
		return ;
	}

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, j);
	update(right, mid + 1, hi, i, j);
	if(tree[node].prop) 
		tree[node].sum = (hi - lo + 1)- (tree[left].sum + tree[right].sum);
	else tree[node].sum = tree[left].sum + tree[right].sum;
}


int main()
{
	fast_io();
 	int n, m;
 	cin >> n >> m;
 	//memset(tree, 0 , sizeof(tree));
 	while(m--){
 		int t, i, j;
 		cin >> t >> i >> j;
 		if (t){
 			cout << query(1, 0, n-1, i-1, j-1, 0) << "\n";
 		}
 		else update(1, 0, n-1, i-1, j-1);
 	}
    return 0;
}