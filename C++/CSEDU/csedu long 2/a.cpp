#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define rep(i,a,n) for (int i=a; i<n; i++)
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    int n,cnt=1,best=1;
    cin >>n;
    int ara[n];
    for (int i=0; i<n; i++){
        cin >>ara[i];
        if (i && ara[i]>ara[i-1]){
            cnt++;
            best=max(best,cnt);
        }
        else if (i && ara[i]<=ara[i-1]) cnt=1;
    }   
    cout <<best<<endl;
    return 0;
}