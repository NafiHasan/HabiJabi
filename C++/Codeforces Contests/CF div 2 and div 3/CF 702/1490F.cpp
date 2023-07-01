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
        cin >> n;
        int a[n];
        map<int,int>m;
        for(int i=0; i<n; i++){
            cin >> a[i];
            m[a[i]]++;
        }
        sort(a,a+n);
        vector<int>v;
        v.push_back(a[0]);
        for(int i=1; i<n; i++){
            if(a[i]!=a[i-1])v.push_back(a[i]);
        }
        int cnt[n+1];
        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<v.size(); i++) cnt[m[v[i]]]++;
        vector<pair<int,int>>fin;
        for(int i=0; i<=n; i++){
            if(cnt[i])fin.push_back({cnt[i],i});
        }
        int ans=INT_MAX;
        for(int i=0; i<fin.size(); i++){
            //cout << fin[i].first << " " << fin[i].second<< en;
            int p=0;
            for(int j=0; j<fin.size(); j++){
                if(i<j) p += (fin[j].second-fin[i].second)*fin[j].first;
                else if (i>j) p+=fin[j].first* fin[j].second;
            }
            ans=min(p,ans);
        }
        cout << ans << en;
    }
    return 0;
}