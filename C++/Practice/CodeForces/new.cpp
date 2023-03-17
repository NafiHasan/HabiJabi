#include <bits/stdc++.h>
using namespace std;
bool vis[1000 + 6];
vector<int>adj[1000 + 5];
int cnt;
vector<int>dd;
void dfs(int x) {
    vis[x] = true;
    dd.push_back(x);
    cnt++;
    for (int v : adj[x]) {
        if (!vis[v])dfs(v);
    }
}
using namespace std;
int main() {

    int n;
    int m;
    scanf( "%d %d", &n, &m);
    int arr[n + 5];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        arr[a]++;
        arr[b]++;
    }
    memset(vis, false, sizeof(vis));
    bool yes = true;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt++;
            dd.clear();
            dfs(i);
            int k = dd.size();
            for (int j = 0; j < dd.size(); j++) {
                if (arr[dd[j]] != k - 1) {
                    yes = false;
                }
            }
        }
    }
    if (yes && cnt <= 2) {
        printf("YES\n");
    } else printf("NO\n");
}