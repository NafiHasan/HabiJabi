#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >> n;
    char a[n][n];
    int cnt=0;
    for(int i=0; i<n; i++){
        for (int j = 0; j < n; j++){
            if(i%2==0){
                if(j%2==0){
                    a[i][j]='C';
                    cnt++;
                }
                else a[i][j]='.';
            }
            else {
                if(j%2==1){
                    a[i][j]='C';
                    cnt++;
                }
                else a[i][j]='.';
            }
        }
    }
    cout << cnt << "\n";
    for (int i=0; i<n; i++) {
        for (int j = 0; j < n; j++)
            cout <<a[i][j];
        cout << "\n";
    }
    return 0;
}