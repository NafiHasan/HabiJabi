#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

int main ()
{
    //ios::sync_with_stdio(false);  cin.tie(NULL);
    int n,m;
    cin >>n>>m;
    string s,t;
    cin >>s>>t;
    map<char,int>has,mx,mn;
    vector<int>a[500];
    for (int i=0; i<m; i++)has[t[i]]++;
    for (int i=0; i<n; i++){
        if (has[s[i]])
            a[s[i] - 97].push_back(i);
    }
    int start=a[t[0]-97][0],end=a[t[m-1]-97][a[t[m-1]-97].size()-1];
    //cout << start << " " << end<< en;
    for (int i=1; i<m-1; i++){
        //for (int j=0; j<a[t[i]-97].size(); j++)cout << a[t[i]-97][j]<<" ";
        //cout <<a[t[i+1]-97][a[t[i+1]-97].size()-1] <<"\n";
        int ind1= lower_bound(a[t[i]-97].begin() , a[t[i]-97].end(), a[t[i-1]-97][0]+1) - a[t[i]-97].begin();
        int lo=0,hi=a[t[i]-97].size()-1,ind2;
        int val=a[t[i+1]-97][a[t[i+1]-97].size()-1]-1;
        //cout <<lo << " "<< hi <<" " << val<<" val \n";
        while(lo<=hi){
            ind2=(lo+hi)/2;
            if (a[t[i]-97][ind2]==val)break;
            else if (a[t[i]-97][ind2]<val)lo=ind2+1;
            else hi=ind2-1;
        }
        while (a[t[i]-97][ind2]>val)ind2--;
        mn[t[i]] =a[t[i]-97][ind1];
        mx[t[i]] =a[t[i]-97][ind2];
        // cout << t[i] << " " << mn[t[i]] << en;
        // cout << t[i] << " " << mx[t[i]] << en;
        // cout << ind2 << en;
    }
    if (m==2) cout <<end-start<<en;
    else {
        int ans=0;
        ans=max(mx[t[1]]-start,ans);
        ans=max(end-mn[t[m-2]],ans);
        for (int i=1; i<m-1; i++){
            if (i==1) ans=max(ans, mx[t[i+1]]-mn[t[i]]);
            else if (i==m-2) ans=max(ans, mx[t[i]]-mn[t[i-1]]);
            else {
                ans=max(ans,mx[t[i+1]]-mn[t[i]]);
                ans=max(ans,mx[t[i]]-mn[t[i-1]]);
            }
        }
        cout <<ans<<en;
    }
    return 0;
}