#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    w(t){
        int r,c;
        cin >>r>>c;
        int ara[r][c];
        for (int i=0; i<r; i++){
            for (int j = 0; j < c; j++)
                cin >> ara[i][j];
        }
        int arr[c][r];
        int ord[r];
        for (int i=0; i<c; i++){
            for (int j = 0; j < r; j++){
                cin >> arr[i][j];
                if (i==0)ord[j]=arr[i][j];
            }
        }
        
    }   
    return 0;
}