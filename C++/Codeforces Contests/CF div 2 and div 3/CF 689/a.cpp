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
        int n,k;
        cin>>n>>k;
        char c='a';
        int cnt=0;
        for (int i=1; i<=n; i++){
            for (int j=0; j<k; j++){
                cout << c;
                cnt++;
                if (cnt==n){
                    i=n+1;
                    break;
                }
            }
            c++;
            if (c>'c')c='a';
        }
        cout <<en;
    }
    return 0;
}