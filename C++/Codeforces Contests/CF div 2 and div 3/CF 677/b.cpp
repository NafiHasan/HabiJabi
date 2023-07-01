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
        int n,sum=0,start=0,cnt=0;
        cin >>n;
        int ara[n];
        for (int i=0;i<n; i++)cin>>ara[i];
        for (int i=0;i<n; i++){
            if (ara[i]==1 && !start)start=1;
            else if (start && ara[i]==0)cnt++;
            else if (start&& ara[i]==1){
                sum+=cnt;
                cnt=0;
            }
        }
        cout <<sum<<endl;
    }
    return 0;
}