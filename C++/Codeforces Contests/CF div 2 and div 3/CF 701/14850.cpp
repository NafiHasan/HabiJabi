#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        ll a,b;
        cin >>a>>b;
        if (a<b)cout <<"1\n";
        else {
            ll cnt=0;
            bool inc=false;
            if (b==1){
                b++;
                cnt++;
                inc=true;
            }
            ll tmpa=a;
            while(tmpa){
                tmpa/=b;
                cnt++;
            }
            //cout <<cnt<<en;
            ll ans=cnt;
            for (ll i=b+1; i<=ans; i++){
                ll tmp=a;
                cnt=i-b;
                if (inc)cnt++;
                while(tmp){
                    tmp/=i;
                    cnt++;
                }       
                ans=min(ans,cnt);
                //cout <<i<<" "<<ans<<en; 
            }
            cout <<ans<<en;
        }
    }   
    return 0;
}