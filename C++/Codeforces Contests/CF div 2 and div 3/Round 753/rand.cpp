#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

//Don't forget to clear the global variables

long long a[200005], tree[200005*3];

void init (int node , int lo, int hi, int op){
	if(lo == hi){
		tree[node] = a[lo];
		return;
	}
	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2 ;

	init (left, lo, mid, op+1);
	init (right, mid + 1, hi, op + 1);
	if(op%2==1){
		tree[node] = tree[left] | tree[right];
		cout << op << ' ' << lo << ' '<< hi << '\n';
	}
	else {
		tree[node] = tree[left] ^ tree[right];
		cout << op << ' ' << lo << ' '<< hi << '\n';
	}
}

// int query(int node, int lo, int hi, int i, int j, int op){
// 	if(i > hi || j < lo) return 0;
// 	if(lo >= i && hi <= j) return tree[node];

// 	int left = node * 2 , right = left + 1;
// 	int mid = (lo + hi) / 2;
// 	long long ans1 = query (left, lo, mid, i, j, op+1);
// 	long long ans2 = query (left, lo, mid, i, j, op+1);
// 	if(op%2==0)return tree[left] | tree[right];
// 	else return tree[left] ^ tree[right];
// }

void update(int node, int lo, int hi, int i, long long new_value, int op){
	if(i > lo || i < hi) return;
	if(lo >= i && hi <= i) {
		tree[node] = new_value;
		return;
	}
	int left = node * 2, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, new_value, op+1);
	update(right, mid + 1, hi, i, new_value, op+1);
	if(op%2==1){
		tree[node] = tree[left] | tree[right];
		cout << op << ' ' << lo << ' '<< hi << '\n';
	}
	else {
		tree[node] = tree[left] ^ tree[right];
		cout << op << ' ' << lo << ' '<< hi << '\n';
	}
}


int main()
{
	fast_io();
 	int n, m;
 	cin>> n >> m;
 	for (int i=0; i<(1<<n); i++)cin >> a[i];
 	init(1, 0, (1<<n)-1, 0);
 	while(m--){
 		int pos, val;
 		cin >> pos >> val;
 		update(1, 0, (1<<n)-1, pos-1, (long long)val, 0);
 		cout << tree[1] << '\n';
 	}
    return 0;
}