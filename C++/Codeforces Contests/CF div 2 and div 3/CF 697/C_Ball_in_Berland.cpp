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
        int a,b,k;
        cin >>a>>b>>k;
        int boy[k], girl[k];
        int bo[a+1],gi[b+1];
        memset(bo,0,sizeof(bo));
        memset(gi,0,sizeof(gi));
        vector<pair<int,int>>v(k);
        map<pair<int,int>,int>m;
        for (int i=0; i<k; i++){
            cin >> boy[i];
            bo[boy[i]]++;
        }
        for (int i=0; i<k; i++){
            cin >> girl[i];
            gi[girl[i]]++;
        }
        ll p=k;
        for (int i=0; i<k; i++){
            v[i]={boy[i],girl[i]};
            if (m[v[i]]>0){
                gi[girl[i]]--;
                bo[boy[i]]--;
                p--;
            }
            m[v[i]]++;
        }
        ll ans=(ll)p*(ll)(p-1)/2LL;
        for (int i=1; i<=a; i++){
            ll x= (ll)bo[i];
            if (x>1) ans-=x*(x-1)/2;
        }
        for (int i = 1; i <= b; i++)
        {
            ll x = (ll)gi[i];
            if (x>1) ans -= x * (x - 1) / 2;
        }
        if (ans>0)cout <<ans<<en;
        else cout <<"0\n";
    }   
    return 0;
}