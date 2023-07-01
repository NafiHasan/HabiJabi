#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    w(t){
        int n,cnt=0,ind=0;
        cin>>n;
        int ara[n];
        for (int i=0; i<n; i++)cin >>ara[i];
        int mx=*max_element(ara,ara+n);
        for(int i=0; i<n; i++){
            if (ara[i]<mx)cnt++;
            if (ara[i]==mx && i>0 && i<n-1 ){
                if (ara[i]>ara[i+1] || ara[i]>ara[i-1]) ind = i + 1;
            }
            else if (i==0 && ara[i]==mx && ara[i+1]<ara[i])ind=i+1;
            else if (i==n-1 && ara[i]==mx && ara[i-1]<ara[i])ind=i+1;
        }
        if (cnt>0)cout <<ind<<endl;
        else cout <<"-1\n";
    }
    return 0;
}