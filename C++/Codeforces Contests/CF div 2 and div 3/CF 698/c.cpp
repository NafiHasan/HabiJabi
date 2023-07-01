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
        ll a[2*(int)n];
        for (ll i=0; i<2*n; i++)cin >>a[i];
        int ss=(int)2*n;
        sort (a,a+ss);
        vector<ll>v;
        bool ans=true;
        for (ll i=2*n-1; i>0; i-=2LL){
            if (a[i]!=a[i-1] || a[i]%2LL){
                ans=false;
                break;
            }
            else v.push_back(a[i]);
        }
        if (v.size() == n && n>1){
            ll cnt=0;
            vector<ll>v2;
            for (ll i=1,j=2; i<n , j<2*n; j+=2,i++){
                if (2*n !=j && ((v[0] - v[i] - cnt) % (2*n-j)) !=0LL){
                    ans=false;
                    break;
                }
                else if (2*n!=j)
                    v2.push_back(((v[0] - v[i] - cnt) / (2 * n - j)));
                cnt+=(2*n-j)*v2[v2.size()-1];
            }
            if (ans){
                cnt=0;
                for (ll i=0,j=2*n; i<v2.size(); i++){
                    cnt += j * v2[i];
                }
            }
            if (ans && (cnt >= v[0] || (v[0] - cnt) % n))
                ans = false;
            if (ans){
                v2.push_back((v[0] - cnt)/n);
                cnt=0;
                // for(int i=0; i< v2.size(); i++)cout << v2[i]<<" ";
                // cout << en;
                for(ll i=0; i<(ll)v2.size(); i++){
                    if (i!=v2.size()-1)cnt += 2*v2[i];
                    else cnt+=v2[i];
                }
                //cout <<cnt << en;
                vector<ll>final;
                final.push_back(-cnt/2LL);
                ll num=-cnt/2;
                //cout <<num<<en;
                for(int i=0; i<v2.size(); i++){
                    num+=v2[i];
                    final.push_back(num);
                }
                for (int i=v2.size()-2; i>=0; i--){
                    num+=v2[i];
                    final.push_back(num);
                }
                //cout <<final.size()<<en;
                if(final.size()!=(int)2*n){
                    ans=false;
                    //cout << "v";
                }
                //for (int i=0; i<final.size(); i++)cout << final[i]<< " ";
                if(ans){
                    sort(final.begin(), final.end());
                    for (ll i = 0; i < n; i++)
                    {
                        if (abs(final[i]) != final[2 * n - i - 1] || final[i]==final[i+1])
                        {
                            ans = false;
                            break;
                        }
                    }
                }
            }
        }
        else if (n==1){
            if (a[1]-a[0] % 2LL == 1LL || a[1]!=a[0])ans=false;
        }
        if (ans)cout <<"YES\n";
        else cout <<"NO\n";
    }   
    return 0;
}