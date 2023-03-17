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
    cin >>n;
    if (n==2){
        cout << "1\n";
        return 0;
    }
    bool prime=true;
    for(int i=2; i*i<=n; i++){
        if(n%i==0)prime=false;
    }
    if(prime){
        cout << "1\n";
        return 0;
    }
    else if (n%2==0){
        cout << "2\n";
        return 0;
    }
    else {
        prime=true;
        for (int i = 2; i * i <= n-2; i++){
            if ((n-2) % i == 0)
                prime = false;
        }
        if(prime)cout <<"2\n";
        else cout << "3\n";
    }
    return 0;
}