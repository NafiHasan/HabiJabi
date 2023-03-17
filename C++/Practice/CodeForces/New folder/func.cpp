#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

void print(int n){
    cout <<n<<en;
    if (n>=1)print(n-1);
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    print(10);
    return 0;
}