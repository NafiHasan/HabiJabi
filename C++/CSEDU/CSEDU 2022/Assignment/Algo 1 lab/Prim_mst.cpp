#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

struct node {
	pair<int, int> val;
	struct node *l;
};

class Priority_Queue {
private:
	node *front; // top element of the priority queue
public:
	Priority_Queue() {
		front = NULL;
	}
	void Push(pair<int, int> val) {
		node *t, *q;
		t = new node;
		t->val = val;
		if (front == NULL || val < front->val) {
			t->l = front;
			front = t;
		} else {
			q = front;
			while (q->l != NULL && q->l->val <= val) {
				q = q->l;
			}
			t->l = q->l;
			q->l = t;
		}
	}
	void Pop() {
		node *t;
		t = front;
		front = front->l;
		free(t);
	}
	pair<int, int> Top() {
		return front->val;
	}
	bool Empty() {
		return (front == NULL);
	}
};

const int N = 200005;
vector<int> taken;
vector<pair<int, int>> AdjList[N];
Priority_Queue pq;

void process(int vtx) {
	taken[vtx] = 1;
	for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
		pair<int, int> v = AdjList[vtx][j];
		if (!taken[v.second]) pq.Push({ v.first, v.second});
	}
}

void Prims_MST() {

	clock_t tStart = clock();


	taken.assign(N - 1, 0); // no vertex is taken at the beginning
	process(1); // take vertex 1 and process all edges incident to it

	int mst_cost = 0;
	while (!pq.Empty()) {
		pair<int, int> front = pq.Top(); pq.Pop();
		int u = front.second, w = front.first;
		if (taken[u] == 0) {
			mst_cost += w;
			process(u); // take u, process all edges incident to u
		}
	}
	cout << "Prim_mst cost : " << mst_cost << '\n';
	cout << "Time taken : " << (double)(clock() - tStart) / (CLOCKS_PER_SEC) << "\n";
}



int main() {
	FastIO;
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)AdjList[i].clear();
	for (int i = 0; i < n; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		AdjList[u].push_back({cost, v});
		AdjList[v].push_back({cost, u});
	}
	Prims_MST();
	return 0;
}