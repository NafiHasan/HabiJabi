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
        int n;
        cin >>n;
        int a[n];
        for (int i=0; i<n; i++)cin >>a[i];
        int cnt=0, val[n];
        memset(val,0,sizeof(val));
        for (int i=1; i<n-1; i++){
            if (a[i]>a[i-1] && a[i]>a[i+1]){
                cnt++;
                val[i]=1;
            }
            else if (a[i]<a[i-1] && a[i] < a[i+1]){
                cnt++;
                val[i]=1;
            }
        }
        int mx=0,best=0;
        for (int i=1; i<n-1; i++){
            if (val[i]!=0)mx++;
            else mx=0;
            best=max(mx,best);
        }
        //cout <<best<<en;
        if (best<=2)cnt-=best;
        else if(best>2)cnt-=3;
        cout <<cnt<<en;
    }
    return 0;
}