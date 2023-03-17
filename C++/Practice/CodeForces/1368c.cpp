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
    
    int n;
    cin >>n;
    int ans=n*3+4;
    cout <<ans<<en;
    cout << n<<" 0\n"<<n+1<<" 0\n";   
    cout <<"0 "<<n+1<<en<<"1 "<<n+1<<en;   
    for(int i=1; i<=n; i++){
        for (int j= n-i,k=1; k<=3; k++,j++)cout <<j<<" "<< i<< en;
    }
    return 0;
}