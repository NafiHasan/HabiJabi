#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int>v[n + 1];
        int a;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            v[a].push_back(i);
        }
        int ans[n];
        memset(ans, 0, sizeof(ans));
        vector<int>p;
        // int color = 1;
        for (int i = 1; i <= n; i++) {
            if (v[i].size() >= k) {
                int l = 1;
                for (int j = 0; j < k; j++) {
                    ans[v[i][j]] = l;
                    l++;
                }
            } else {
                for (int j = 0; j < v[i].size(); j++) {
                    p.push_back(v[i][j]);
                    if (p.size() == k) {
                        int color = 1;
                        for (int l = 0; l < p.size(); l++) {
                            ans[p[l]] = color;
                            color++;
                        }
                        p.clear();
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }

}