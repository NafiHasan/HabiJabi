struct node {
    bool f = false;
    char c;
    int p = -1, link = -1, ex = -1;
    int to[26], go[26];
    vector <int> id;
    node() {
        memset(to, -1, sizeof(to));
        memset(go, -1, sizeof(go));
    }
};
int siz = 1;
vector <node> trie(1);
void insert(string &s, int len, int j) {
    int u, v = 0;
    for (int i = 0; i < len; i++) {
        int c = s[i] - 97;
        if (trie[v].to[c] == -1) {
            trie.emplace_back();
            trie[v].to[c] = siz++;
        }
        u = v;
        v = trie[v].to[c];
        trie[v].p = u, trie[v].c = s[i];
    }
    trie[v].f = true;
    trie[v].id.push_back(j);
}
int go(int v, char c);
int get_link(int v) {
    if (trie[v].link == -1) {
        if (v == 0 || trie[v].p == 0) trie[v].link = 0;
        else trie[v].link = go(get_link(trie[v].p), trie[v].c);
    }
    return trie[v].link;
}
int get_exit_link(int v) {
    if (trie[v].ex == -1) {
        int u = get_link(v);
        if (u == 0 || trie[u].f) trie[v].ex = u;
        else  trie[v].ex = get_exit_link(u);
    }
    return trie[v].ex;
}
int go(int v, char c) {
    int x = c - 97;
    if (trie[v].go[x] == -1) {
        if (trie[v].to[x] != -1) trie[v].go[x] = trie[v].to[x];
        else trie[v].go[x] = v ? go(get_link(v), c) : 0;
    }
    return trie[v].go[x];
}
string s, t;
vector <int> a[100005];
int n, k[100005], len, ln[100005];
void get_id(int v, int i) {
    int sz = trie[v].id.size();
    for (int j = 0; j < sz; j++) {
        int p = trie[v].id[j];
        a[p].push_back(i - ln[p]);
    }
}
void fun(int i, int v) {
    if (trie[v].f) get_id(v, i);
    int u = get_exit_link(v);
    while (u > 0) {
        if (trie[u].f) get_id(u, i);
        u = get_exit_link(u);
    }
    if (i < s.size()) fun(i + 1, go(v, s[i]));
}
int query(int i) {
    int s = a[i].size(), ans = -1;
    for (int j = k[i] - 1, p = 0; j < s; j++, p++) {
        int x = a[i][j] + ln[i] - a[i][p];
        ans = (ans == -1) ? x : min(ans, x);
    }
    return ans;
}
int main() {
    cin >> s >> n;
    len = s.length();
    for (int i = 0; i < n; i++) {
        cin >> k[i] >> t;
        ln[i] = t.length();
        insert(t, ln[i], i);
    }
    fun(0, 0);
    for (int i = 0; i < n; i++) cout << query(i) << endl;
}