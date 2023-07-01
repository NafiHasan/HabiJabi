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
        int n,cnt=0;
        cin >>n;
        int ara[n];
        for (int i=0; i<n; i++) cin >> ara[i];
        int lo,hi=ara[0];
        lo = *min_element(ara, ara + n);
        if (n>1)hi = *max_element(ara+1, ara + n-1);
        int lo_ind=0,hi_ind=0;
        for (int i = 1; i < n - 1; i++)
        {
            if (ara[i] == hi){
                hi_ind = i;
                break;
            }
        }
        for (int i=0; i<n; i++){
            if (ara[i]==lo){
                lo_ind = i;
                break;
            }
        }
        int start,endd;
        if (lo_ind<=hi_ind){
            start=0;
            endd=hi_ind;
        }
        else {
            start=hi_ind;
            endd=n-1;
        }
        //cout <<"start "<<start<<" " <<endd<<en;
        for (int i=start; i<=endd; i++)ara[i]-=lo;
        int found=0;
        for (int i=0; i<n; i++)cout <<ara[i]<<" ";
        for (int i=0; i<n; i++){
            if (ara[i]==0)found=1;
            else if (found==0 && i && ara[i]>ara[i-1]){
                cnt=1;
                break;
            }
            else if (found==1 && ara[i]<ara[i-1]){
                cnt=1;
                break;
            }
        }
        (cnt==0 ? cout<<"YES\n" : cout <<"NO\n");
    }   
    return 0;
}