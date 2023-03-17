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

// vector<int> a2(N, 0);
struct info {
	int prop = 0, sum = 0;
} tree2[N * 4];

int query2(int node, int lo, int hi, int i, int j,int carry = 0){
	if(i > hi || j < lo) return 0;
	if(i <= lo && j >= hi)return tree2[node].sum + carry * (hi - lo + 1) ;

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;

	return query2(left, lo, mid, i , j , carry + tree2[node].prop) + query2(right, mid + 1, hi, i , j , carry + tree2[node].prop);
}

void update(int node, int lo, int hi, int i, int j, int val){
	if(i > hi || j < lo) return;
	if(i <= lo && j >= hi) {
		tree2[node].sum += (hi - lo + 1) * val;
		tree2[node].prop += val;
		return;
	}

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, j, val);
	update(right, mid + 1, hi, i, j, val);
	tree2[node].sum = tree2[left].sum + tree2[right].sum + (hi - lo + 1) * tree2[node].prop;
}


int main() {
	FastIO;
 	int n, m, last = 1e9;
 	cin >> n >> m;
 	vector<pair<int,int>> vp(n);
 	for (int i=0; i<n; i++)cin >> vp[i].first >> vp[i].second;
 	sort(vp.begin(), vp.end());
 	for (int i=0; i<n; i++){
 		a[i] = vp[i].second;
 		last = min(last, vp[i].second);
 	}
 	init(1, 0 , n - 1);
 	vector<int> range(m + 5, -1);
 	for (int i=0; i<n; i++){
 		if(vp[i].first > last)break;
 		int mx = 0;
 		int lo = 0, hi = i, last1 = 0, mid;
 		while(lo <= hi){
 			mid = (lo + hi)/2;
 			if(vp[mid].first < vp[i].first)lo = mid + 1;
 			else if(vp[mid].first == vp[i].first){
 				hi = mid - 1;
 				last1 = mid;
 			}
 			else hi = mid - 1;
 		}
 		if(last > 0)mx = query(1, 0, n - 1, 0, last1 - 1);
 		range[vp[i].first] = max(vp[n - 1].first, mx);
 	}
 	for (int i=1; i<=last; i++){
 		if(range[i] == -1){
 			int lo = 0, hi = n - 1, mid, last1 = -1;
 			while(lo <= hi){
 				mid = (lo + hi)/2;
 				if(vp[mid].first > i)hi = mid - 1;
 				else {
 					last1 = mid;
 					lo = mid + 1;
 				}
 			}
 			int mx = 0;
 			if(last1 != -1)mx = query(1, 0, n - 1, 0, last1);
 			range[i] = max(mx, vp[n - 1].first); 
 		}
 	}
 	for (int i=1; i<=last; i++){
 		if(range[i] == -1)continue;
 		int st = range[i] - i + 1, ls = m - i + 1;
 		update(1, 0, m - 1, st - 1, ls - 1, 1);
 	}
 	for (int i=1; i<=m; i++){
 		cout << query2(1, 0, m - 1, i - 1, i - 1, 0) << ' ';
 	}
 	cout << "\n";
    return 0;
}