#include <bits/stdc++.h>

using namespace std;

const int MX = 300005;

int Tc, N, K;
int A[MX], T[MX];
multiset<int> Inc, Dec;
vector<int> adj[MX];

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("I", "r", stdin);
//     freopen("O", "w", stdout);
// #endif

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int i, j;
    for (cin >> Tc; Tc--; ) {
        cin >> N >> K;
        Inc.clear(), Dec.clear();
        int ink = 0, dek = 0;
        for (i = 1; i <= N; i++) adj[i].clear();
        for (i = 1; i <= K; i++) {
            cin >> A[i];
            adj[A[i]].push_back(i);
        }
        for (i = 1; i <= K; i++) cin >> T[i];
        for (i = 1; i <= K; i++) Dec.insert(T[i] + A[i] - 1);
        for (i = 1; i <= N; i++) {
            for (int u : adj[i]) {
                Dec.erase(Dec.find(T[u] + A[u] - 1));
                Inc.insert(T[u] - ink);
            }
            int mn = 1010000000;
            if (!Dec.empty()) mn = min(mn, *Dec.begin() + dek);
            if (!Inc.empty()) mn = min(mn, *Inc.begin() + ink);
            dek--, ink++;
            cout << mn << ' ';
        }
        cout << '\n';
    }

    return 0;

}

