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
        int n,m;
        cin >>n>>m;
        vector<pair<int,int>>vp(m);
        map<int,int>col;
        map<int,int>ro;
        int cnt=0;
        for (int i=0; i<m; i++){
            int x,y;
            cin >>x>>y;
            if (x==y)cnt++;
            ro[y-1]=1;
            col[x-1]=1;
            vp.push_back(make_pair(y,x));
        }
        int ans=0, cnt1=0,cnt2=0;
        for (int i=0; i<n; i++){
            if (col[i]==1 && ro[i]==1){
                cnt2++;
                //cout <<i<<en;
            }
            else if (col[i]==1 || ro[i]==1)cnt1++;
        }
        //cout <<cnt1<<" "<<cnt2<<" "<<cnt<<en;
        cnt2-=cnt;
        if (cnt2%2==0 && cnt2)ans+=3*(cnt2/2);
        else if (cnt2%2==1 && cnt1>0){
            ans += 3*(cnt2/2);
            cnt1=max(0,cnt1-2);
            ans+=2;
        }
        else if (cnt2%2==1 && cnt1==0){
            
        }
        ans+=(cnt1/2);
        //ans+=(cnt1%2)+(cnt2%2);
        cout <<ans<<en;
    }   
    return 0;
}