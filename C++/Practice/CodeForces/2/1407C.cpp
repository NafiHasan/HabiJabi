#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    int n;
    cin >>n;
    vector<int>v(n,0);
    cout <<"? 1 2"<<endl;
    int i=1;
    while(1){
        int x;
        cin >>x;
        cout <<"? "<<i+1<<" "<<i<<endl;
        int y;
        cin >>y;
        if (x<y && v[i]==0)v[i]=y;
        else if (x>y && v[i-1]==0) v[i-1]=x;
        i++;
    }
    return 0;
}