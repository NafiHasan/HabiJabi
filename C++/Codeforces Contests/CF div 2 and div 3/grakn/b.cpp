#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define rep(i,a,n) for (int i=a; i<n; i++)
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"

// int bin (int lo, int hi, int dif, int k){
//     int mid;
//     while(lo<=hi){
//         mid=lo+(hi-lo)/2;
//         if ()
//     }
// }

int main ()
{
    w(t){
        int n,k,dif=1;
        cin >>n>>k;
        int ara[n];
        for (int i=0; i<n;i++){
            cin >>ara[i];
            if (i>0 && ara[i]!=ara[i-1])dif++;
        }
        int ans = (dif / k) + 1;
        if (k==1 && dif >1)cout <<"-1\n";
        else if (k>=dif)cout <<"1\n";
        else if (dif%k==0) cout <<dif/k<<endl;
        
        else cout <<ans<<endl;
    }   
    return 0;
}