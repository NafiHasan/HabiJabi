#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    w(t){
        int n;
        cin >> n;
        vector<pair<int,int>>vp;
        map<pair<int,int>,int>m;
        map<int,int>p;
        vector<pair<int,int>>mp;
        int mn=INT_MAX, ind=0;
        for(int i=0; i<n; i++){
            int a, b;
            cin >>a>>b;
            vp.push_back({min(a, b), max(a, b)});
            m[{min(a,b),max(a,b)}]=i;
            p[min(a,b)]=max(a,b);
            if(mn > (a+b))mn=a+b;
        }
        for (int i=0; i<n; i++){
            if (vp[i].first+vp[i].second ==mn){
                mp.push_back({vp[i].first, vp[i].second});
            }
        }
        int ans[n];
        // sort(vp.begin(), vp.end());
        memset (ans,-1, sizeof(ans));
        for(int i=0; i<n; i++){
            int ff = vp[i].first, ss = vp[i].second;
            for(int j=0; j<mp.size(); j++){
                int f = mp[j].first, s = mp[j].second;
                if(f<ff && s<ss){
                    ans[i]=m[{f,s}]+1;
                    break;
                }
            }
        }
        for(int i=0; i<n; i++)cout << ans[i]<< " ";
        cout <<en;
    }   
    return 0;
}