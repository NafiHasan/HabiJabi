#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    w(t){
        int n;
        cin >>n;
        char g[n][n];
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cin >>g[i][j];
            }
        }
        if (g[0][1]==g[1][0] && g[0][1]!=g[n-1][n-2] && g[n-1][n-2]== g[n-2][n-1])cout <<"0\n";
        else if (g[0][1]==g[1][0] && g[n-2][n-1]!=g[n-1][n-2]){
            if(g[0][1]==g[n-2][n-1])cout <<"1\n"<<n-1<<" "<<n<<endl;
            else cout <<"1\n"<<n<<" "<<n-1<<endl;
        }
        else if (g[0][1]!=g[1][0] && g[n-2][n-1]==g[n-1][n-2]){
            if (g[0][1]==g[n-1][n-2])cout <<"1\n1 2\n";
            else cout <<"1\n2 1\n";
        }
        else if (g[0][1]==g[1][0] && g[n-1][n-2]==g[n-2][n-1] && g[0][1]==g[n-1][n-2])
            cout <<"2\n1 2\n2 1\n";
        else {
            cout <<"2\n";
            if (g[0][1]=='1')cout <<"1 2\n";
            else if (g[1][0]=='1')cout <<"2 1\n";
            if (g[n-1][n-2]=='0')cout <<n<<" "<<n-1<<endl;
            else if (g[n-2][n-1]=='0')cout <<n-1<<" "<<n<<endl;
        }
    }
    return 0;
}