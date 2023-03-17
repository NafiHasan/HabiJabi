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
    int a[n];
    for (int i=0; i<n; i++)cin>>a[i];
    sort (a,a+n);
    int point=0, mx=a[n-1];
    bool hid[n];
    memset(hid,false,sizeof(hid));
    for(int i=0; i<n; i++){
        if (a[i]*2<=mx)point=i;
    }   
    int cnt=0;
    for(int i=0, j=(n+1)/2; i<(n+1)/2 && j<n; ){
        if (a[i]*2<=a[j]){
            cnt++;
            i++,j++;
        }
        else j++;
    }
    cout <<(n-cnt)<<en;
    return 0;
}