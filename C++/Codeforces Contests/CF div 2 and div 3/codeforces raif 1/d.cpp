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
    
    int n,no=1,tar=0;
    cin >>n;
    int ara[n];
    int mat[n][n];
    int last=n-1,down=n-1;
    map<int, int> r;
    map<int, int> c;
    for (int i=0,j=0; i<n; i++){
        cin >>ara[i];
        if (c[j]==2 || r[j]==2){
            no=0;
            break;
        }
        if (ara[i]==1){
            mat[j][j]++;
            c[j]++;
            r[j]++;
            j++;
            tar++;
        }
        else if (ara[i]==2){
            mat[j][j]++;
            mat[j][last]++;
            r[j]=2;
            c[j]++;
            last--;
            j++;
        }
        else if (ara[i]==3){
            mat[j][j]++;
            mat[j][last]++;
            mat[down][j]++;
            r[j]=2;
            c[j]=2;
            down--;
            j++;
        }
    }   
    j--;
    if (no==0 )cout <<
    for (int i=0; i<n; i++)m[mat[]]
    return 0;
}