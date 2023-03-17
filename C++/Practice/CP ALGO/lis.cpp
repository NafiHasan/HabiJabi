#include <bits/stdc++.h> 
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n; cin >> n;
    vector <int> a(n);
    for(int i=0; i<n ; i++) cin >> a[i];
    vector <int> d(n,1);
    for(int i=0; i<n; i++){
        for(int j=0; j < i; j++){
            if(a[j] < a[i]) d[i]=max(d[i], d[j]+1);
        }
    }
    cout << *max_element(d.begin(), d.end()) << "\n";
    return 0;
}