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
        int l,r;
        cin >>l>>r;
        int x=r+1;
        int dx=x/2;
        if (x%2==1)dx++;
        if(l%x>=dx )
        {
            cout<<"YES\n";
        }
        else cout <<"NO\n";
    }   
    return 0;
}