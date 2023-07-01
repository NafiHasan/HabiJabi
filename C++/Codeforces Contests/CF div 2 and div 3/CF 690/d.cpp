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
        ll n;
        cin >>n;
        ll ara[n];
        ll sum=0;
        for (int i=0; i<n; i++){
            cin >> ara[i];
            sum+=ara[i];
        }
        vector<ll>v;
        for (ll i=1; i*i<=sum; i++){
            ll a,b;
            if (sum%i==0){
                a=i;b=sum/i;
                if (a==b)v.push_back(a);
                else {
                    v.push_back(a);
                    v.push_back(b);
                }
            }
        }
        //for (int i=0; i<v.size(); i++)cout <<v[i]<<" ";
        sort (v.rbegin(), v.rend());
        //cout <<v.size()<<en<<en;
        ll ans=LLONG_MAX;
        for (ll i=0; i<v.size(); i++){
            if (sum%v[i]==0){
                bool flag = true;
                ll ele=sum/v[i];
                //cout <<ele<<en;
                ll all=0;
                for (int j=0; j<n; j++){
                    all+=ara[j];
                    //cout <<all<<en;
                    if (all==ele)all=0;
                    else if (all>ele){
                        flag =false;
                        //cout <<all<<" "<<ele<<en;
                        break;
                    }
                }
                if (flag){
                    ans=min(ans,n-v[i]);
                }
            }
        }
        cout <<ans<<en;
    }
    return 0;
}