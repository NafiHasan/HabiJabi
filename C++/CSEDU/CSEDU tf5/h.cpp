#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"
const ll p=10e9+7;

int main ()
{
    // ios::sync_with_stdio(false); 
    //cin.tie(NULL);
    
    w(t){
        int n;
        cin >> n;
        vector <int>v;
        vector <int>vf;
        for (int i=0; i<n; i++){
            int x;
            cin >>x;
            v.push_back(x);
        }
        map<int,int>m; 
        int ara[1005];
        for (int i=0; i<1005; i++)ara[i]=1;
        vector<int>si;
        int lim = 1000001;
        bool prime[lim];
        memset(prime, true, sizeof(prime));
        for (int i = 2; i * i <= lim; i++)
        {
            if (prime[i] == true)
            {
                for (int j = i * i; j <= lim; j += i)
                    prime[j] = false;
            }
        }
        for (int i = 2; i <= lim; i++)
        {
            if (prime[i] == true)
                si.push_back(i);
        }
        //for (int i=0; i<si.size(); i++)cout <<si[i]<<" ";
        cout <<si.size()<<en;
        ll cnt = 0,fin = 0;
        sort (v.begin(),v.end());
        vf.push_back(v[0]);
        if (v[0]==1)fin++;
        for (int i=1; i<v.size(); i++){
            if (v[i] != v[i - 1] || v[i] == 1)
            {
                vf.push_back(v[i]);
                m[v[i]]++;
            }
            if (v[i]==1)fin++;
        }
        ll sz=(ll)vf.size();
        for (int i=0; i<si.size(); i++){
            cnt=0;
            for (int j = 0; j < vf.size(); j++)
            {
                if (vf[j] % si[i] == 0 && vf[j] != si[i])
                    cnt = 1;
            }
            if (cnt == 0 && m[si[i]] > 0)
                fin++;
        }
        if (sz!=fin) fin++;
        if (fin>0){
            ll ans = 1;
            for (ll i = 1; i <= fin; i++) {
                ans *= 2;
                ans %= p;
            }
            ans%=p;
            ans -= (ll)2;
            cout << ans << en;
        }
        else cout <<"0\n";
    }   
    return 0;
}