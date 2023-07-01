#define CLR(a) memset(a,0,sizeof(a))
/***
* str is 1 based
Each node in the palindromic tree denotes a STRING
Node 1 denotes an imaginary string of size -1
Node 2 denotes a string of size 0
They are the two roots
There can be maximum of (string_length + 2) nodes in total
It's a directed tree. If we reverse the
direction of the suffix links, we get a dag. In
this DAG, if node v is reachable from node u
iff, u is a substring of v.
* if ( tree[A].next[x] == B )
then, B = xAx
* if ( tree[A].suffixLink == B )
Then B is the longest possible palindrome which is a proper suffix of A
(node 1 is an exception)
* occ[i] contains the number of occurrences of the corresponding palindrome
* st[i] denotes starting index of the first occurrence of the corresponding palindrome
* st[] or occ[] or both can be ignored if not needed
* If memory limit is compact, a map has to be used instead of
ed[MAXN][MAXC]. Swapping row and column of the matrix will
save more memory.
Example :
map <int,int> ed[MAXC];
ed[c][u] = v means, there is an edge from node u to
node v that is labeled character c.
***/
namespace pt {
const int MAXN = 100010; /// maximum possible string size
const int MAXC = 26; /// Size of the character set
int n; /// length of str
char str[MAXN];
int len[MAXN], link[MAXN], ed[MAXN][MAXC], occ[MAXN], st[MAXN];
int nc, suff, pos;
/// nc -> node count
/// suff -> Index of the node denoting the longest palindromic proper suffix of the current prefix
void init() {
	str[0] = -1;
	nc = 2; suff = 2;
	len[1] = -1, link[1] = 1;
	len[2] = 0, link[2] = 1;
	CLR(ed[1]), CLR(ed[2]);
	occ[1] = occ[2] = 0;
}
inline int scale(char c) { return c - 'a'; }
inline int nextLink(int cur) {
	while (str[pos - 1 - len[cur]] != str[pos]) cur = link[cur];
	return cur;
}
inline bool addLetter(int p) {
	pos = p;
	int let = scale(str[pos]);
	int cur = nextLink(suff);
	if (ed[cur][let]) {
		suff = ed[cur][let];
		occ[suff]++;
		return false;
	}
	suff = ++nc;
	CLR(ed[nc]);
	len[nc] = len[cur] + 2;
	ed[cur][let] = nc;
	occ[nc] = 1;
	if (len[nc] == 1) {
		st[nc] = pos;
		link[nc] = 2;
		return true;
	}
	link[nc] = ed[nextLink(link[cur])][let];
	st[nc] = pos - len[nc] + 1;
	return true;
}
void build(int _n) {
	n = _n;
	init();
	for (int i = 1; i <= n; i++) addLetter(i);
	for (int i = nc; i >= 3; i--) occ[link[i]] += occ[i];
	occ[2] = occ[1] = 0;
}
void printTree() {
	puts(str);
	cout << "Node\tStart\tLength\tOcc\n";
	for (int i = 3; i <= nc; i++) {
		cout << i << "\t" << st[i] << "\t" << len[i] << "\t" << occ[i] << "\n";
	}
}
}
int main() {
	scanf("%s", pt::str + 1);
	pt::build(strlen(pt::str + 1));
	return 0;
}