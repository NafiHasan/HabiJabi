#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    
    w(t){
        int n;
        cin >>n;
        int ara[n][n];
        memset(ara,0,sizeof(ara));
        if (n%2==1){
            ara[0][0]=1;
            ara[0][n-1]=1;
            for (int i=1; i<n; i++) {
                ara[i][i-1] = 1;
                ara[i][i] = 1;
            }
        }
        else {
            for (int i=0; i<n-1; i+=2){
                ara[i][i]=1;
                ara[i][i+1]=1;
                ara[i+1][i]=1;
                ara[i+1][i+1]=1;
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cout << ara[i][j] << " ";
            }
            cout <<endl;
        }
    }   
    return 0;
}