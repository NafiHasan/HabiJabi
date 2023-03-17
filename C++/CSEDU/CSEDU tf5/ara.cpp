#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

const ll p = 1000000007;

int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    
    w(t){
        int n;
        cin >> n;
        vector<int> v;
        vector<int> vf;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        //cutting duplicates*******************************************************
        sort(v.begin(), v.end());
        vf.push_back(v[0]);
        for (int i = 1; i < v.size(); i++){
            if (v[i] != v[i - 1] || v[i] == 1)
                vf.push_back(v[i]);
        }
        int cnt1=0;
        for (int i=0; v[i]<2; i++)if (v[i]==1)cnt1++;

        //sieve**********************************************************************
        int lim = 1000010;
        bool prime[lim];
        memset(prime, true, sizeof(prime));
        prime[0]=false;
        for (int i = 2; i * i <= lim; i++)
        {
            if (prime[i] == true)
            {
                for (int j = i * i; j <= lim; j += i)
                    prime[j] = false;
            }
        }
        //finding primes that dont have any multiples********************
        for (int i=0; i<vf.size(); i++){
            if (vf[i]>1 && prime[vf[i]]==false){
                int lm=sqrt(vf[i])+1;
                for (int j=2; j<=lm; j++){
                    if (vf[i]%j==0){
                        prime[j] = false;
                        prime[vf[i]/j]=false;
                    }
                }
            }
        }
        //final ans*****************************************************************
        ll ans=(ll)cnt1;
        for (int i=0; i<vf.size(); i++){
            if (prime[vf[i]] == true && vf[i] > 1)
                ans++;
            //cout <<vf[i]<<" "<<prime[vf[i]]<<en;
        }
        if (ans==(ll)0){
            cout <<"0\n";
        }
        else {
            if (ans != (ll)vf.size())ans++;
            ll sum = 1;
            for (ll i = 1; i <= ans; i++)
            {
                sum *= (ll)2;
                sum %= p;
            }
            sum %= p;
            sum -= (ll)2;
            cout << sum << en;
        }
    }   
    return 0;
}