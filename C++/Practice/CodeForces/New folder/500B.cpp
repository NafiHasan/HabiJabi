#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"
const int inf=1e9;

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >> n ;
    int a[n];
    for(int i = 0; i < n ; i++ )cin >>a[i];
    int mat[n][n];
    for(int i=0; i<n; i++){
        string s;
        cin >>s;
        for(int j=0; j<n; j++){
            if(s[j]=='1') mat[i][j] = 1;
            else mat[i][j] = inf;
        }
    }
    for(int k=0; k<n ; k++)
        for (int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if (mat[i][k]+mat[k][j] == 2 && i!=j) mat[i][j] = 1;
    vector<int>ind,val;
    for(int i=0; i<n; i++){
        val.clear();
        ind.clear();
        val.push_back(a[i]);
        ind.push_back(i);
        for (int j=0; j<n; j++){
            if (mat[i][j]==1){
                val.push_back(a[j]);
                ind.push_back(j);
            }
        }
        sort (val.begin(), val.end());
        sort (ind.begin(), ind.end());
        for (int k = 0; k < ind.size(); k++) a[ind[k]] = val[k];
    }
    for(int i=0; i<n; i++) cout << a[i]<<" ";
    cout << "\n";
    return 0;
}