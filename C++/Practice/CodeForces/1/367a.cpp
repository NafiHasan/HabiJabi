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
    
    string s;
    cin >>s;
    int lim=s.size();
    int x[lim],y[lim],z[lim];
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(z,0,sizeof(z));
    for (int i=0; i<s.size(); i++){
        if (i > 0)
            x[i] = x[i - 1];
        if (i > 0)
            y[i] = y[i - 1];
        if (i > 0)
            z[i] = z[i - 1];
        if (s[i]=='x') 
            x[i]++;
        else if (s[i]=='y')y[i]++;
        else if (s[i]=='z') z[i]++;
    }
    w(t){
        int l,r;
        cin >>l>>r;
        l--,r--;
        if ((r-l+1)<3)cout <<"YES\n";
        else {
            int cntx,cnty,cntz;
            if (l>0)cntx=x[r]-x[l-1],cnty=y[r]-y[l-1],cntz=z[r]-z[l-1];
            else
                cntx = x[r], cnty = y[r] , cntz = z[r];
            int mx = max({cntx, cnty, cntz}), mn = min({cntx, cnty, cntz});
            if ((mx-mn)>1)cout <<"NO\n";
            else cout <<"YES\n";
        }
    }   
    return 0;
}