#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
#define MAX 100005

int val[MAX], tree[3*MAX];

int query (int node, int lo, int hi, int i, int j){
	if(i > hi || j < lo) return 0;
	if(i >= lo && j <= hi) return tree[node];
	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	int ans1 = query (left, lo, mid, i, j);
	int ans2 = query (right, mid + 1, hi, i, j);
	return ans1 + ans2 ;
}

void update(int node, int lo, int hi, int i, int j){

}


int main()
{
	fast_io();
 	int n, q;
 	cin >> n >> q;
 	while(q--){
 		int t,a,b;
 		cin >> t >> a >> b;

 	}	
    return 0;
}