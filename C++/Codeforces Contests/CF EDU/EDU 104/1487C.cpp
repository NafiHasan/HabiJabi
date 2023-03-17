#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        int win=n*(n-1)/2;
        int mx=win/n;
        bool ok=true;
        if (win%n)ok=false;
        int a[n+1];
        memset(a,0,sizeof(a));
        vector<pair<int,int>>v;
        for (int i=1; i<n; i++){
            for (int j=i+1; j<=n; j++){
                v.push_back({i,j});
            }
        }
        bool done[n+10];
        memset(done,false,sizeof(done));
        vector<int>ans(win,0);
        for (int i=v.size()-1; i>=0; i--){
            if (!ok && v[i].first+v[i].second==n+1){
                if (!done[v[i].first] && !done[v[i].second]){
                    done[v[i].first]=true;
                    done[v[i].second]=true;
                    //cout <<v[i].first<<" "<<v[i].second<<en;
                    continue;
                }
            }
            if (a[v[i].second] < mx){
                a[v[i].second]++;
                ans[i] = -1;
            }
            else if(a[v[i].first]<mx){
                a[v[i].first]++;
                ans[i]=1;
            }
        }
        // for (int i=0; i<n; i++){
        //     if (ans[i]==0 && v[i]){
        //         if (a[v[i].first]<mx)
        //     }
        // }
        for (int i=0; i<ans.size(); i++)cout <<ans[i]<<" ";
        cout <<en;
    }
    return 0;
}