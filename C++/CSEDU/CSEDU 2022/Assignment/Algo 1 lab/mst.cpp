#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 3e5 + 10;

vector<int> parent(N), rnk(N, 0);

void makeset(int n) {
	for (int i = 1; i <= n; i++)parent[i] = i;
}

int get(int a) {
	return (parent[a] == a ? a : (parent[a] = get(parent[a])));
}

void union_set(int a, int b) {
	a = get(a);  // find the topmost parent
	b = get(b);

	if (a == b)return; // are in same set

	if (rnk[a] == rnk[b])rnk[a]++;

	if (rnk[a] > rnk[b])parent[b] = a;
	else parent[a] = b;
}

void clr(int n) {
	makeset(n);
	for (int i = 0; i <= n; i++)rnk[i] = 0;
}


vector<pair<int, pair<int, int>>> EdgeList;

void Kruskal_MST() {
	clock_t tStart = clock();

	sort(EdgeList.begin(), EdgeList.end());
	long long mst_cost = 0;
	for (int i = 0; i < EdgeList.size(); i++) {
		pair<int, pair<int, int>> front = EdgeList[i];
		int parentFirst = get(front.second.first);   // parent of first node
		int parentSecond = get(front.second.second);  // parent of second node
		if (parentFirst != parentSecond) {
			mst_cost += front.first;
			union_set(front.second.first, front.second.second);
		}
	}
	cout << "Cost using Kruskal's : " << mst_cost << '\n';
	cout << "Time taken : " << (double)(clock() - tStart) / (CLOCKS_PER_SEC) << "\n";
}



int main() {
	FastIO;
	int n;
	cin >> n;
	EdgeList.clear();
	makeset(n);
	for (int i = 0; i < n; i++) {
		int u, v;
		long long cost;
		cin >> u >> v >> cost;
		EdgeList.push_back({cost, {u, v}});
	}
	Kruskal_MST();
	return 0;
}