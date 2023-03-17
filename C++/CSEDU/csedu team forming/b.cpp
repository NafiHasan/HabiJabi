#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    
    w(t){
        int n,mn,mx;
        cin >>n>>mn>>mx;
        vector<pair<int,int>>v;
        for (int i=0; i<n; i++){
            int x,y;
            cin >>x>>y;
            v.push_back(make_pair(x,y));
        }
        int ans=mn%2;
        for (int i=0; i<n; i++){
            int x=v[i].first,y=v[i].second;
            if ((x * ans) % 2 == y % 2 )
                ans = 0;
            else 
                ans = 1;
        }
        int ans2=ans;
        if (mn<mx){
            ans2=(mn+1)%2;
            for (int i = 0; i < n; i++)
            {
                int x = v[i].first, y = v[i].second;
                if ((x * ans2) % 2 == y % 2)
                    ans2 = 0;
                else 
                    ans2 = 1;
            }
        }
        int odd = 0, even = 0;
        if (mn % 2 == 1)
        {
            int tot = mx - mn + 1;
            even = tot / 2;
            odd = tot - even;
        }
        else if (mn % 2 == 0)
        {
            int tot = (mx - mn + 1);
            odd = tot / 2;
            even = tot - odd;
        }
        if(ans==ans2 && ans%2==0){
            cout <<(mx-mn+1)<<" 0"<<endl;
        }
        else if (ans==ans2 && ans%2==1)cout <<"0 "<<(mx-mn+1)<<endl;
        else if (ans!=ans2){
            if (mn%2 != ans) cout <<odd<<" "<<even<<endl;
            else cout <<even<<" "<<odd<<endl;
        }
    }   
    return 0;
}