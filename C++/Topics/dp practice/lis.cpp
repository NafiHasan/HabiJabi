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
    
    int n ;
    cin >>n;
    int ara[n];
    for (int i=0; i<n ; i++){
        cin >> ara[i];
    }   
    int best[n];
    best[0]=1;
    for(int i=1; i<n; i++){
        best[i]=1;
        for (int j=0; j<=i; j++){
            if (ara[j]<ara[i]) best[i]=max(best[i],best[j]+1);
        }
    }
    cout << *max_element(best,best+n)<<en;
    return 0;
}