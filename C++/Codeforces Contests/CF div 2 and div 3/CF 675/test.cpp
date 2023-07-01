#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define rep(i,a,n) for (int i=a; i<n; i++)
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"

int fact(int n)
{
    if (n==1)return 2;
    else {
        cout <<n<<" ";
        return n*fact(n-1);
    }
}

int main ()
{
    cout <<fact(5)<<endl;
    return 0;
}