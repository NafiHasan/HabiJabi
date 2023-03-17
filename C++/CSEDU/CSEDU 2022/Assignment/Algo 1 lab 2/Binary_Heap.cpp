#include <bits/stdc++.h>
using namespace std;

class Priority_Queue {
private:
	pair<int, int> HP[2005];
	int sz = -1;
	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return ((2 * i) + 1);
	}
	int right(int i) {
		return ((2 * i) + 2);
	}
	void up(int i) {
		while (i > 0 && HP[parent(i)].first < HP[i].first) {
			swap(HP[parent(i)], HP[i]);
			i = parent(i);
		}
	}
	void down(int i) {
		int maxInd = i;
		int l = left(i);
		if (l <= sz && HP[l].first < HP[maxInd].first)maxInd = l;
		int r = right(i);
		if (r <= sz && HP[r].first < HP[maxInd].first)maxInd = r;
		if (i != maxInd) {
			swap(HP[i], HP[maxInd]);
			down(maxInd);
		}
	}
public:
	void Push(pair<int, int> val) {
		sz = sz + 1;
		HP[sz] = val;
		up(sz);
	}
	void Pop() {
		pair<int, int> ans = HP[0];
		HP[0] = HP[sz];
		sz--;
		down(0);
	}
	bool Empty() {
		return (sz == -1);
	}
	pair<int, int> Top() {
		return HP[0];
	}
};
