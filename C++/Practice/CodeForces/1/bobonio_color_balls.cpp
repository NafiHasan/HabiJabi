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
        ll r,g,b,w;
        cin>>r>>g>>b>>w;
        ll mn=min({r,g,b});
        r-=mn;g-=mn,b-=mn;w+=3*mn;
        int odd=0;
        if(r%2==1)odd++;
        if (g%2==1)odd++;
        if(b%2==1)odd++;
        if(w%2==1)odd++;
        if (odd<=1)cout<< "Yes\n";
        else if (odd>1 && mn>0){
            r++,g++,b++,w-=3;odd=0;
            if (r % 2 == 1)
                odd++;
            if (g % 2 == 1)
                odd++;
            if (b % 2 == 1)
                odd++;
            if (w % 2 == 1)
                odd++;
            if(odd<=1)cout <<"Yes\n";
            else if(odd>1)cout <<"No\n";
        }
        else cout <<"No\n";
    }   
    return 0;
}