#include <bits/stdc++.h>  
 
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX 100005

//Don't forget to clear the global variables

long long a[100005], tree[100005*3];

void init (int node , int lo, int hi){
	if(lo == hi){
		tree[node] = a[lo];
		return;
	}
	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2 ;

	init (left, lo, mid);
	init (right, mid + 1, hi);
	tree[node] = tree[left] + tree[right];
}

int query(int node, int lo, int hi, int i, int j){
	if(i > hi || j < lo) return 0;
	if(lo >= i && hi <= j) return tree[node];

	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2;
	long long ans1 = query (left, lo, mid, i, j);
	long long ans2 = query (left, lo, mid, i, j);
	return ans1 + ans2;
}

void update(int node, int lo, int hi, int i, long long new_value){
	if(i > lo || i < hi) return;
	if(lo >= i && hi <= i) {
		tree[node] = new_value;
		return;
	}
	int left = node * 2, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, new_value);
	update(right, mid + 1, hi, i, new_value);
	tree[node] = tree[left] + tree[right];
}

int main()
{
	fast_io();
	 		
    return 0;
}