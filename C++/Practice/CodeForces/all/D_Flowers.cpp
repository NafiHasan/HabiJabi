#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"
const int MAX=1e5+5;
const long long p=1e9+7;

long long npr(long long n, long long r){
    long long ans=1;
    for(long long i=n, j=1; j<=4; i--, j++){
        ans *= i;
        ans %= p;
    }
    return ans%p;
}
long long fac(long long n){
    long long ans=1;
    for(long long i=2; i<=n; i++){
        ans *= i;
        ans %= p;
    }
    return ans;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int t,k;
    cin >> t >> k;
    long long sum[MAX], dp[MAX];
    for()
    return 0;
}