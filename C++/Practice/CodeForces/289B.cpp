#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n,m, d;
    cin >> n >> m >> d;
    int a[n][m];
    vector<int>cnt;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
            cnt.push_back(a[i][j]);
        }
    }
    int md=a[0][0]%d;
    bool ans= 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++){
            if (a[i][j] % d != md)
            {
                ans=0;
                break;
            }
        }
    }
    if (ans){
        sort (cnt.begin(), cnt.end());
        int tar=cnt.size()/2;
        tar=cnt[tar];
        int all=0;
        for (int i=0; i<cnt.size(); i++)all+=abs(tar-cnt[i]);
        cout << all/d << en;
    }
    else cout << -1 << en;
    return 0;
}