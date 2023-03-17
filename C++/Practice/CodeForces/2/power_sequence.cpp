#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >>n;
    ll ara[n],  sum=0;
    for(int i=0; i<n; i++){
        cin >> ara[i];
        sum+=ara[i];
    }   
    sort (ara,ara+n);
    double d=1.0/(double)(n-1);
    ll lim=(ll)pow((double)ara[n-1],d);
    if (n>40)lim=1;
    ll cost1=0,cost2=0,cost3=0;
    for (int i=0; i<n; i++){
        cost1+=abs(ara[i]-pow(lim,i));
    }
    lim--;
    for (int i = 0; i < n; i++)
    {
        cost2 += abs(ara[i] - pow(lim, i));
    }
    ll ans=min(cost1,cost2);
    if (n<40){
        lim += 2;
        for (int i = 0; i < n; i++)
        {
            cost3 += abs(ara[i] - pow(lim, i));
        }
        ans=min(ans,cost3);
    }
    cout << ans<<en;
    return 0;
}