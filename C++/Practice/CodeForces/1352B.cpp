#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    
    w(t){
        int n,k;
        cin >> n >> k;
        if (n%2==0 && k<=n/2){
            cout<< "yes\n";
            for(int i=1; i<k ; i++)cout<<"2 ";
            cout<< n-(2*k-2)<< en;
        }
        else if (n==k){
            cout <<"yes\n";
            for( int i=1; i<=k ; i++)cout<< "1 ";
            cout <<en;
        }
        else if (n%2==k%2 && n%2==1 && n>k){
            cout<< "yes\n";
            for(int i=0; i<k-1; i++)cout <<"1 ";
            cout <<n-(k-1)<<en;
        }
        else if (n % 2 == k % 2 && k<=n)
        {
            cout << "yes\n";
            for (int i = 1; i < k; i++)
                cout << "1 ";
            cout << n - (k - 1) << en;
        }
        else cout<<"no\n";
    }   
    return 0;
}