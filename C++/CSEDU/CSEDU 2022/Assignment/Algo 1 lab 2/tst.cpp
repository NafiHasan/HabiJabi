#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

class Priority_Queue {
private:
	int last = -1;
	int hp[100005];
	int left(int i) {
		return i * 2 + 1;
	}
	int right(int i) {
		return i * 2 + 2;
	}
	int parent(int i) {
		return (i - 1) / 2;
	}
	void up(int i) {
		while (i > 0 && hp[parent(i)] > hp[i]) {
			swap(hp[parent(i)], hp[i]);
			i = parent(i);
		}
	}
	void down(int i) {
		int minInd = i, l = left(i), r = right(i);
		if (l <= last && hp[l] < hp[minInd])minInd = l;
		if (r <= last && hp[r] < hp[minInd])minInd = r;
		if (i != minInd) {
			swap(hp[i], hp[minInd]);
			down(minInd);
		}
	}
public:
	bool isEmpty() {
		return (last == -1);
	}
	void Push(int val) {
		hp[++last] = val;
		up(last);
	}
	void Pop() {
		swap(hp[0], hp[last--]);
		down(0);
	}
	int Top() {
		return hp[0];
	}
};


int main() {
	FastIO;
	Priority_Queue pq;
	pq.Push(12);
	pq.Push(35);
	pq.Push(45);
	pq.Push(55);
	pq.Push(45);
	pq.Push(5);
	while (!pq.isEmpty()) {
		cout << pq.Top() << '\n';
		pq.Pop();
	}
	return 0;
}