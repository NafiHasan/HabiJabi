#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    map<int,int>m;
    for (int i=0; i<n; i++){
        cin >> a[i];
        m[a[i]]++;
    }
    for(int i=1 ; ; i++){
        if (m[i] ==0 ){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}