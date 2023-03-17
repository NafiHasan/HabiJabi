#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define rep(i,a,n) for (int i=a; i<n; i++)
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    w(t){
        int n,cnt=0;
        cin >>n;
        if (n%3==0){
            cout <<(n/3)<<" "<<"0 0\n";
        }
        else if (n%5==0){
            cout <<"0 "<<(n/5)<<" 0\n";
        }
        else if (n%7==0){
            cout <<"0 0 "<<(n/7)<<endl;
        }
        else {
            for (int i=0; i<=(n/3); i++){
                for (int j=0; j<=(n/5); j++){
                    for (int k=0; k<= (n/7); k++){
                        if ((3*i+5*j+7*k)==n){
                            cout <<i<<" "<<j<<" "<<k<<endl;
                            cnt=1;
                            i=n;
                        }
                    }
                }
            }
            if (cnt==0)cout <<"-1\n";
        }
    }
    return 0;
}