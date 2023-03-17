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
    while(1){
        int x;
        cin >>x;
        if (x==0)return 0;
        if (x<4 || x%2==1){
            cout << "Impossible\n";
        }
        else {
            int dif=(x-2)/2;
            cout <<((x*3)/2)<<endl;
            for (int i=1; i<=x; i++){
                for (int j=i+1; j<=x; j+=dif){
                    cout <<i<<" "<<j<<endl;
                }
            }
        }
    }
    return 0;
}