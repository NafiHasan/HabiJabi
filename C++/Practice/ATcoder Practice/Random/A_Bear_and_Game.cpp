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
    cin >> n;
    int cnt=0 , a[n+2];
    a[0]=0;
    bool found =false;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }  
    a[n+1]=90; 
    for(int i=1; i<=n+1; i++){
        if (a[i] - a[i - 1] > 15 && !found)
        {
            cnt += 15;
            found = true;
        }
        else if(!found)
            cnt = a[i];
    }
    cout << cnt << "\n";
    return 0;
}