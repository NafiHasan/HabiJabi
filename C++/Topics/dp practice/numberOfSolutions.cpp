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
    
    int coins[]={1,2,5,10,50,100};
    int x;
    cin >>x;
    int cnt[x+1];
    memset(cnt,0,sizeof(cnt));
    cnt[0]=1;
    for (int i=1; i<=x; i++){
        for (auto c:coins ){
            if (c<=i){
                cnt[i]+=cnt[i-c];
            }
        }
    }
    cout <<cnt[x]<<en;
    return 0;
}