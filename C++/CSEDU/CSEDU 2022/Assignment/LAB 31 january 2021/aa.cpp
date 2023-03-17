#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define dbg(x) cout<<#x<<" = "<<x<<en
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
int fin(int *a){
    cout << a[2][2] <<en;
    a[2][2]=11;
    return 1;
} 

int main()
{
    fast_io();
    int a[4][4];
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++)a[i][j]=2;
    }
    fin(a);
    cout << a[2][2];
    return 0;
}