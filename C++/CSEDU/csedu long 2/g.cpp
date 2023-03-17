#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    w(t){
        int n,k;
        cin >>n>>k;
        if (n%2==1){
            cout <<"-1\n";
            return 0;
        }
        else if (k%2==1){
            for (int i=0; i<n/2; i++)cout <<"()";
            cout <<endl;
        }
        else if (n%k==0){
            cout <<"-1\n";
            return 0;
        }
    }   
    return 0;
}