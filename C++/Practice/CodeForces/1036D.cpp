#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m;
    ll sum1=0, sum2=0;
    cin >> n;
    ll a[n];
    for(int i=0; i< n; i++) {
        cin >> a[i];
        sum1+=a[i];
    }
    cin >> m; 
    ll b[m];
    for(int i =0; i<m; i++){
        cin >> b[i];
        sum2+=b[i];
    }
    vector<ll>v;
    int i,j;
    for(i=0, j=0; i<n && j<m; ){
        if(a[i]==b[j]){
            v.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j] && i<n-1){
            a[i + 1] += a[i];
            if (a[i]==b[j])v.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j] && j<m-1){
            b[j + 1] += b[j];
            if (a[i]==b[j])v.push_back(a[i]);
            j++;
        }
        else break;
        if (a[i] != b[j] && ((i == n - 1) && (j == m - 1))){
            v.clear();
            break;
        }
    }   
    if (v.size() && sum1==sum2)cout << v.size() << "\n";
    else cout <<"-1\n";
    return 0;
}