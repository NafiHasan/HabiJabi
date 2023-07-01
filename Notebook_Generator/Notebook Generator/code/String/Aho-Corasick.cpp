struct vartex {
	int next[30], endmark, link;
	vector<int>dlink;
	vartex() {
		memset(next, -1, sizeof(next));
		endmark = -1;
		link = 0;
	}
};
void addstring(string& s, vector<vartex>&trie) {
	int v = 0;
	for (auto x : s) {
		if (trie[v].next[x - 'a'] == -1) {
			trie[v].next[x - 'a'] = trie.size();
			trie.emplace_back();
		}
		v = trie[v].next[x - 'a'];
	}
	trie[v].endmark = 0;
}
void fail(vector<vartex>&trie) {
	int v = 0;
	trie[v].link = 0;
	queue<int>q;
	q.push(0);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i = 0; i < 26; i++) {
			if (trie[v].next[i] != -1) {
				if (v == 0) {
					trie[trie[v].next[i]].link = 0;
				}
				else {
					int x = trie[v].link;
					while (x != 0 && trie[x].next[i] == -1) {
						x = trie[x].link;
					}
					if (trie[x].next[i] == -1) {
						trie[trie[v].next[i]].link = 0;
					}
					else {
						trie[trie[v].next[i]].link =  trie[x].next[i];
					}
				}
				q.push(trie[v].next[i]);
			}
		}
	}
}
void dictionary_link(vector<vartex>&trie) {
	queue<int>q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < 26; i++) {
			if (trie[u].next[i] != -1) {
				q.push(trie[u].next[i]);
			}
		}
		int k = u;
		while (k != 0) {
			if (trie[k].endmark != -1 && k != u) {
				trie[u].dlink.push_back(k);
			}
			k = trie[k].link;
		}
		debug(u, trie[u].dlink);
	}
}
int search(string& s, vector<vartex>&trie) {
	int v = 0;
	for (auto x : s) {
		v = trie[v].next[x - 'a'];
	}
	return trie[v].endmark;
}