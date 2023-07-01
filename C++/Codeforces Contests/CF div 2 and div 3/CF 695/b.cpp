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
        for (int i=0, j=9; i<n; i++){
            cout <<j%10;
            if (i==0)j--;
            else j++;
        }
        cout <<en;
    }   
    return 0;
}