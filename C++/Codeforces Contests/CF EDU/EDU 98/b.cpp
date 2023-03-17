#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    
    w(t){
        int n;
        cin >>n;
        int ara[n];
        for (int i=0; i<n; i++)cin >>ara[i];
        int found=0;
        int mn=*min_element(ara,ara+n);
        int mx=*max_element(ara,ara+n);
        ll cnt=0;
        for (int i =0; i<n; i++){
            if (ara[i]==mn && found==0)found=1;
            else if (ara[i]!=mx && ara[i]!=mn) cnt+=(ll)(mx-ara[i]);
            else if (ara[i]==mn && found==1)cnt+=(ll)(mx-ara[i]);
        }
        //cout<<cnt<<en;
        if (mn==0 && cnt==0)cout <<"0\n";
        else if (cnt>mn){
            cout <<cnt-(ll)mn<<en;
        }
        else {
            mn-=(int)cnt;
            int fac=mn/(n-1);
            if (mn%(n-1)!=0)fac++;
            cout <<fac*(n-1)-mn<<en;
        }
    }   
    return 0;
}