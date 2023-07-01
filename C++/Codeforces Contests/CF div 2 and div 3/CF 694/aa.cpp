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
        int n,x;
        cin >>n>>x;
        int a[n];
        ll sum=0, mx=0;
        for (int i=0; i<n; i++){
            cin >>a[i];
            sum+=(ll)a[i];
            mx+=(ll)(a[i]/x);
            if (a[i]%x!=0)mx++;
        }
        ll mn=sum/(ll)x;
        if (sum%(ll)x!=0)mn++;
        cout <<mn<<" "<<mx<<en;
    }   
    return 0;
}