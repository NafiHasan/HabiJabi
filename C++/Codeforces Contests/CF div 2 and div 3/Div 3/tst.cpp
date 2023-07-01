#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
    fast_io();
    int cnt=0;
    cout << 1<<"\n"<< 40000 <<en;
    int num=20002;
    for (int i=20001; i<=40000; i++){
        cout << i << " " << i << " ";
        cnt++;
    }
    // cout << en<<cnt<<en;

    return 0;
}