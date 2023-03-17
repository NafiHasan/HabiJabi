#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int r,c;
    cin >> r>> c;
    char a[r][c];
    int last=0,start=0;
    for(int i=0 ; i<r ; i++){
        for (int j=0; j<c; j++){
            cin >>a[i][j];
            if(a[i][j] == '#')last=i;
            if(!start && a[i][j]=='#')start=i;
        }
    }
    int ans=4;
    for(int i=start; i<last; i++){
        int j=0;
        while(a[i][j] == '.') j++;
        if(a[i+1][j-1] == '#' || a[i+1][j]=='.'){
            ans += 2;
            //cout << i << " " << j << en;
        }
        while(a[i][j] == '#') j++;
        if (a[i + 1][j] == '#' || a[i + 1][j-1] == '.') {
            ans += 2;
            //cout <<i<<" "<<j<<en;
        }
    }
    cout << ans<< en;
    return 0;
}