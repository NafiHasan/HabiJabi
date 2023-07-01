#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    w(t){
        ll p,q;
        cin >>p>>q;
        if (p>q && p%q!=0){
            cout <<p<<en;
        }
        else if (p<q ){
            cout <<p<<en;
        }
        else {
            ll lim=sqrt(p)+1;
            vector<ll>v;
            v.push_back(1);
            if (q<=lim){
                for (ll i = q+1; i <= lim; i++)
                {
                    if (p % i == 0 && i % q != 0)
                    {
                        v.push_back(i);
                        if ((p / i) % q != 0)
                            v.push_back(p / i);
                    }
                }
            }
            else {
                for (ll i = lim; i <q; i++){
                    if (p % i == 0 && i % q != 0)
                    {
                        v.push_back(i);
                        if ((p / i) % q != 0)
                            v.push_back(p / i);
                    }
                }
            }
            cout <<*max_element(v.begin(),v.end())<<en;
            
        }
    }   
    return 0;
}