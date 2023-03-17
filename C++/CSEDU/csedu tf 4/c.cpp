#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    
    int cs=1;
    w(t){
        ll tot,nt,c;
        cin >>tot>>nt>>c;
        ll ara[tot];
        map<ll,ll>m;
        for (int i=0; i<tot; i++){
            cin >>ara[i];
            m[ara[i]]++;
        }
        sort (ara,ara+tot);
        vector<ll>v;
        for (int i=0; i<tot; i++){
            if (i==0 )v.push_back(ara[i]);
            else if (i && ara[i]!=ara[i-1])v.push_back(ara[i]);
        }
        vector<pair<ll,ll>>vp;
        ll total=0;
        for (int i=0; i<v.size(); i++){
            vp.push_back(make_pair(m[v[i]],v[i]));
            total+=(v[i]*v[i])%c;
        }
        sort (vp.begin(),vp.end());
        //for (int i=0; i<vp.size(); i++)cout <<vp[i].first<<" "<<vp[i].second<<en;
        ll sum=0,all=tot,ans=0;
        for (int i=0; i<vp.size(); i++){
            ans=max(ans,total*vp[i].first);
            total-=(vp[i].second*vp[i].second)%c;
        }
        cout <<"Case "<<cs++<<": "<<ans<<en;
    }   
    return 0;
}