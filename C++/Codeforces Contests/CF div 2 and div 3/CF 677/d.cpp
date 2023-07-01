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
        int n,ok=0;
        cin >>n;
        int ara[n];
        for (int i=0; i<n; i++){
            cin >> ara[i];
            if (ara[i]!=ara[i-1] && i)ok=1;
        }
        if (ok==0)cout <<"NO\n";
        else {
            cout <<"YES\n";
            int cnt=0;
            int i=0, j=n-1,ind=n;
            while(cnt<n-1 && i<n){
                if (i==j && i<n-1){
                    i=ind;
                    j=n-1;
                }
                if (ara[i]!=ara[j] && cnt<n-1){
                    cout <<i+1<<" "<<j+1<<endl;
                    cnt++;
                    j--;
                }
                else if (ara[i]==ara[j]){
                    for (int k=i+1; k<n; k++){
                        if (ara[k]!=ara[j]){
                            cout <<k+1<<" "<<j+1<<endl;
                            k=n;
                            cnt++;
                        }
                    }
                    j--;
                }
            }
        }
    }   
    return 0;
}