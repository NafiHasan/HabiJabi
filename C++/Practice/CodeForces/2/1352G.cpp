#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        if (n<4)cout<<"-1\n";
        else if (n==4) cout << "3 1 4 2\n";
        else {
            int i;
            if (n%2==0)i=2;
            else i=1;
            for (; i<=n; i+=2)cout <<i<<" ";
            i-=5;
            cout << i << " ";
            i+=2;
            if (i<=n)cout <<i<<" ";
            i-=4;
            for (; i>=1; i-=2)cout <<i<<" ";
            cout <<en;
        }
    }   
    return 0;
}