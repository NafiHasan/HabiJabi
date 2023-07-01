int bit[1000], arra[1000];
int n;
void update( int idx, int val ) {
	for ( int i = idx; i <= n; i += i & (-i) ) bit[i] += val;
	return;
}
int query( int idx ) {
	int sum = 0;
	for ( int i = idx; i > 0; i -= i & (-i) ) sum += bit[i];
	return sum;
}