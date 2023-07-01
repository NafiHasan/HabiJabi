#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"
int val[105],a[105];

void rec(int a[], int lo, int hi, int cur){
    if (lo==hi){
        val[lo]=cur;
        return;
    }
    if (lo>hi)return ;
    int ind,mx=0;
    for (int i=lo; i<=hi; i++){
        if (mx<a[i]){
            mx=a[i];
            ind=i;
            //cout <<mx<<en;
        }
    }
    val[ind]=cur;
    rec(a,ind+1,hi,cur+1);
    rec(a,lo,ind-1,cur+1);
    return ;
}

int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        for (int i=0; i<n; i++)cin >>a[i];
        rec(a,0,n-1,0);
        for (int i=0; i<n; i++){
            cout <<val[i]<<" ";
        }
        cout <<en;
    }
    return 0;
}