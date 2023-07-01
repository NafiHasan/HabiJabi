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
        vector<pair<int,int>>vt(n);
        map<pair<int,int>,int>m;
        map<pair<int,int>,int>sum;
        for(int i=0 ; i<n; i++){
            int a,b;
            cin >> a>>b;
            vt[i]={min(a,b),max(a,b)};
            m[vt[i]]=i;
            sum[vt[i]]=a+b;
        }
        sort(vt.begin(),  vt.end());
        int ans[n];
        memset(ans,-1, sizeof(ans));
        for (int i=1; i<n; i++){
            int lo=0, hi=i, mid;
            while(lo<=hi){
                mid=(lo+hi)/2;
                
            }
        }
        for (int i=0; i<n; i++)cout <<ans[i]<<" ";
        cout <<en;
    }   
    return 0;
}