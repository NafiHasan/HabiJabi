#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//Don't forget to clear the global variables
// make sure to set the maximum size according to the problem

const int N = 1e5 + 10;

map<int, int> ind;
vector<int> par(N), rnk(N, 0), siz(N, 1), id(N), ans(N, -1);

void makeset() {
    for (int i = 1; i < N; i++)par[i] = i;
}

int mx = 0;

int get(int a) {
    // path compressed, change if needed
    return (par[a] == a ? a : (par[a] = get(par[a])));
}

void union_set(int a, int b) {
    a = get(a);  // find the topmost parent
    b = get(b);

    if (a == b)return; // are in same set

    // if (rnk[a] == rnk[b])rnk[a]++;

    if (rnk[a] > rnk[b]) {
        par[b] = a;
        ans[b] = max(ans[b], ans[a]);
        ans[a] = max(ans[b], ans[a]);
    } else if (rnk[a] == rnk[b]) {
        if (a > b)par[b] = a;
        else par[a] = b;
        ans[b] = max(ans[b], ans[a]);
        ans[a] = max(ans[b], ans[a]);

    } else {
        par[a] = b;
        ans[b] = max(ans[b], ans[a]);
        ans[a] = max(ans[b], ans[a]);

    }
}

int main() {
    FastIO;
    makeset();
    int n, q; cin >> n >> q;
    for (int i = 0, j = n; i < n; i++, j--) {
        cin >> id[i];
        ind[id[i]] = i;
        rnk[id[i]] = j;
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            union_set(a, b);
        } else if (t == 2) {
            int x;
            cin >> x;
            rnk[x]++;
        } else {
            int y;
            cin >> y;
            y = get(y);
            cout << y << '\n';
        }
    }
    return 0;
}