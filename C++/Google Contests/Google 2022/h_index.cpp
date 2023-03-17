#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

//Don't forget to clear the global variables or just init


struct info {
	int prop, sum, best;
} tree[100005 * 3];

// void init(int node, int lo, int hi){
// 	if(lo == hi) {
// 		tree[node].sum = a[lo];
// 		return;
// 	}
// 	int left = 2 * node, right = left + 1;
// 	int mid = (lo + hi) / 2;
// 	init(left, lo, mid);
// 	init(right, mid + 1, hi);
// 	tree[node].sum = tree[left].sum + tree[right].sum;
// }

int query(int node, int lo, int hi, int i, int j, long long carry = 0) {
	if (i > hi || j < lo) return 0;
	if (i <= lo && j >= hi) {
		// cout << i << ' ' << j << ' ' << tree[node].best << "best\n";
		return tree[node].best + carry;
	}

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	int ans1 = query(left, lo, mid, i , j , carry + tree[node].prop);
	int ans2 = query(right, mid + 1, hi, i , j , carry + tree[node].prop);

	return max({tree[node].best , ans1 , ans2}) ;
}

void update(int node, int lo, int hi, int i, int j, long long val) {
	if (i > hi || j < lo) return;
	if (i <= lo && j >= hi) {
		tree[node].sum += val;
		tree[node].prop += val;
		tree[node].best = min(hi - lo + 1, max(tree[node].best , tree[node].sum));
		cout << lo << ' ' << hi << ' ' << tree[node].best << '\n';
		return ;
	}

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, j, val);
	update(right, mid + 1, hi, i, j, val);
	// tree[node].sum = max(tree[node].sum, max(tree[left].sum , tree[right].sum));
	tree[node].best = max({tree[node].best, tree[left].best , tree[right].best});
	// + (hi - lo + 1) * tree[node].prop * 1LL;
}

int main() {
	fast_io();
	int tests;
	cin >> tests;
	for (int test_case = 1; test_case <= tests; test_case++) {
		// Get number of papers for this test case
		memset(tree, 0, sizeof(tree));
		int paper_count;
		cin >> paper_count;
		vector<int> answer(paper_count), a(paper_count);
		for (int i = 0; i < paper_count; i++) {
			cin >> a[i];
			// update(1, 1, 100005 , 1, x, 1);
			// answer[i] = query(1, 1, 100005 , 1, i + 1, 0);
		}
		int mx = *max_element(a.begin() , a.end());
		for (int i = 0; i < paper_count; i++) {
			// cin >> a[i];
			update(1, 1, mx , 1, a[i], 1);
			cout << "end\n";
			answer[i] = query(1, 1, mx , 1, i + 1, 0);
		}
		cout << "Case #" << test_case << ": ";
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

