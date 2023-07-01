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
        vector<pair<int,pair<int,int>>>vp(n);
        for(int i=0; i<n ;i++){
            int x,y;
            cin >>x>>y;
            if (x>y)swap(x,y);
            vp[i]={x,{y,i}};
        }
        vector<int>find(n),ans(n,-1);
        sort (vp.begin(), vp.end());
        for (int i=0; i<n; i++){
            find[i]=vp[i].first;
        }
        for (int i=0; i<n; i++){
            int hi=upper_bound(find.begin(), find.end(), vp[i].first)-find.begin();
            int lo=lower_bound(find.begin(), find.end(), 0)-find.begin();
            //cout <<lo<<" "<<hi<<en;
            if (lo>hi)ans[vp[i].second.second]=-1;
            else if (vp[lo].second.first<vp[i].second.first && lo<=hi &&vp[lo].first<vp[i].first)ans[vp[i].second.second]=vp[lo].second.second;
        }
        for (int i=0; i<n; i++){
            if (ans[i]!=-1)cout <<ans[i]+1<<" ";
            else cout <<"-1 ";
        }
        cout <<en;
    }   
    return 0;
}