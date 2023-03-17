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
        int n;
        cin >>n;
        int ara[n];
        for (int i=0; i<n; i++)cin>>ara[i];
        sort (ara,ara+n);
        for (int i=(n-1)/2,j=(n-1)/2+1; ;){
            if (i>=0) cout <<ara[i--]<<" ";
            if (j<n)cout <<ara[j++]<<" ";
            if (i<0 && j>=n)break;
        }
        cout <<en;
    }   
    return 0;
}