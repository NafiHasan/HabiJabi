#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int a, b;
        cin >>a>>b;
        cout <<(a^b)<<en;
    }
}