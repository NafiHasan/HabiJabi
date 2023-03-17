#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    string s;
    cin >> s;
    int n=s.size();
    int cnt[n];
    memset(cnt, 0, sizeof(cnt));
    for (int i=0; i<n-1; i++)if (s[i]==s[i+1]) cnt[i]++;
    int presum[n+1];
    presum[0]=0,presum[1]=cnt[0];
    for (int i=2; i<=n; i++){
        presum[i]=cnt[i-1]+presum[i-1];
    }
    int m;
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        cout << presum[r-1]-presum[l-1] << en;
    }
    return 0;
}