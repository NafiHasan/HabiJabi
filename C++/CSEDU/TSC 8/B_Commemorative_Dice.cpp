#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int a[6],b[6];
    for (int i=0; i<6; i++)cin >>a[i];
    for (int i=0; i<6; i++)cin >>b[i];
    sort (a,a+6);
    sort (b,b+6);
    int cnt=0;
    for (int i=0; i<6; i++){
        for (int j=0; j<6; j++){
            if (a[j]>b[i])cnt++;
        }
    }
    // if ()
    cout <<cnt/(__gcd(cnt,36)) <<"/" << 36/__gcd(36,cnt)<<en;
    return 0;
}