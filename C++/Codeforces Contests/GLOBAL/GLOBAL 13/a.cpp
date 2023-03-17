#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    // ios::sync_with_stdio(false);  cin.tie(NULL);
    int n,q;
    cin >>n>>q;
    int a[n], cnt0=0,cnt1=0;
    for (int i=0; i<n; i++){
        cin >>a[i];
        if (a[i])cnt1++;
        else cnt0++;
    }   
    for (int i=0; i<q; i++){
        int x,y;
        cin >>x>>y;
        if (x==1){
            if (a[y-1]){
                cnt1--;
                cnt0++;
                a[y-1]=0;
            }
            else {
                cnt0--;
                cnt1++;
                a[y-1]=1;
            }
        }
        else {
            if (y<=cnt1)cout <<1<<en;
            else cout <<0<<en;
        }
    }
    return 0;
}