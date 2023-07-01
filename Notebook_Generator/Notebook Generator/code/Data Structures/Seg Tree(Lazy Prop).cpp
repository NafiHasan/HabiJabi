int n, q, arra[100005];
struct idk {
	int sum, prop;
} tree[300005];
void init( int node, int b, int e ) {
	if ( b == e ) {
		tree[node].sum = arra[b];
		return;
	}
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;
	init(left, b, mid);
	init(right, mid + 1, e);
	tree[node].sum = tree[left].sum + tree[right].sum;
	return;
}
void update( int node, int b, int e, int i, int j, int val ) {
	if ( b > j || e < i ) return;
	if ( b >= i && e <= j ) {
		tree[node].sum += (e - b + 1) * val;
		tree[node].prop += val;
		return;
	}
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;
	update( left, b, mid, i, j, val );
	update( right, mid + 1, e, i, j, val );
	tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
	return;
}
int query( int node, int b, int e, int i, int j, int carry ) {
	if ( b > j || e < i ) return 0;
	if ( b >= i && e <= j ) return tree[node].sum + (e - b + 1) * carry;
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;
	int p1 = query(left, b, mid, i, j, carry + tree[node].prop );
	int p2 = query(right, mid + 1, e, i, j, carry + tree[node].prop );
	return p1 + p2;
}