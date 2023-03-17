#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
void solve()
{
    int n;
    cin >> n;
    vector<int> vc(n);
    int p = log2(n);
    int table1[p + 1][n];
    int table2[p + 1][n];
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
        table1[0][i] = vc[i];
        table2[0][i] = vc[i];
    }
    for (int i = 1; i < p + 1; i++)
    {
        for (int j = 0; j < n - (int)pow(2, i - 1); j++)
        {
            table1[i][j] = min(table1[i - 1][j], table1[i - 1][j + (int)pow(2, i - 1)]);
            table2[i][j] = max(table2[i - 1][j], table2[i - 1][j + (int)pow(2, i - 1)]);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int k = log2(r - l + 1);
        int mmx = max(table2[k][l], table2[k][r - (int)pow(2, k) + 1]);
        int mmn = min(table1[k][l], table1[k][r - (int)pow(2, k) + 1]);
        int r1 = l - 1;
        int k1 = log2(l);
        int l2 = r + 1;
        int k2 = log2(n - r - 1);
        int mx1 = 0, mx2 = 0;
        if (r1 >= 0)
            mx1 = max(table2[k1][0], table2[k1][r1 - (int)pow(2, k1) + 1]);
        if (l2 < n)
            mx2 = max(table2[k2][l2], table2[k2][n - (int)pow(2, k2)]);
        float rmx = max((float)(mmx - mmn)/2, (float)max(mx1, mx2));
        cout << rmx + mmn <<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}