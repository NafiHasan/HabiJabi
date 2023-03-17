#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"

int f_calls=0;

int fact (int n){
    f_calls++;
    if (n==0) return 1;
    return n*fact(n-1);
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >>n;
    fact(n);
    return 0;
}