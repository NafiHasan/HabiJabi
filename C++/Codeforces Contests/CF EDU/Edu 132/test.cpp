




class segtree{
private:
	long long tree[300005 * 4], a[300005];

public:
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

	long long query(int node, int lo, int hi, int i, int j){
		if(i > hi || j < lo) return 0;
		if(lo >= i && hi <= j) return tree[node];

		int left = node * 2 , right = left + 1;
		int mid = (lo + hi) / 2;
		return query (left, lo, mid, i, j) + query (right, mid + 1, hi, i, j);
	}

	void update(int node, int lo, int hi, int i, long long new_value){
		if(i < lo || i > hi) return;
		if(lo == hi) {
			tree[node] = new_value;
			return;
		}
		int left = node * 2, right = left + 1;
		int mid = (lo + hi) / 2;
		update(left, lo, mid, i, new_value);
		update(right, mid + 1, hi, i, new_value);
		tree[node] = tree[left] + tree[right];
	}

};



const int N = 300005;

long long a[N], tree[N * 4];

void clear(int n){
	for (int i=0; i <= n; i++) a[i] = 0;
	for (int i=0; i <= 4 * n; i++) tree[i]= 0;
}

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

long long query(int node, int lo, int hi, int i, int j){
	if(i > hi || j < lo) return 0;
	if(lo >= i && hi <= j) return tree[node];

	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2;
	return query (left, lo, mid, i, j) + query (right, mid + 1, hi, i, j);
}

void update(int node, int lo, int hi, int i, long long new_value){
	if(i < lo || i > hi) return;
	if(lo == hi) {
		tree[node] = new_value;
		return;
	}
	int left = node * 2, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, new_value);
	update(right, mid + 1, hi, i, new_value);
	tree[node] = tree[left] + tree[right];
}
