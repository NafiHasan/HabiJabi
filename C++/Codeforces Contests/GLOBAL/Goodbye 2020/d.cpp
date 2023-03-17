#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        vector<ll>a(n),ans;
        ll sum=0, pre[n];
        for (int i=0; i<n; i++){
            cin >> a[i];
            sum+=a[i];
        }
        vector<pair<int, pair<int, int>>> vp;
        for(int i=0; i<n-1; i++){
            int u,v;
            cin>>u>>v;
            vp.push_back({a[u]+a[v],{u,v}});
        }
        sort(vp.rbegin(), vp.rend());
        for (int i=0; i<n-1; i++){
            if (i == 0)
                pre[i] = vp[i].first;
            else
                pre[i] = pre[i - 1] + vp[i].first;
        }
        map<ll,ll>m;
        ans.push_back(sum);
        for(int i=1; i<n-1; i++){
            ll x=0;
            for (int )

        }
        for (int i=0; i<ans.size(); i++)cout <<ans[i]<<" ";
        cout <<en;
    }   
    return 0;
}