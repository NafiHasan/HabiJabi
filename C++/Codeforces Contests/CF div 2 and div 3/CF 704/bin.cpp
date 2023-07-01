#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    vector<int>a={3,7,10};
    int ind=0;
    int lo=0, hi=2,mid;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if (a[mid]==8)break;
        else if (a[mid]<8)lo=mid+1;
        else hi=mid-1;
    }
    if (a[mid]>)
    cout << mid << " " << a[mid] << en;   
    return 0;
}