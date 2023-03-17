#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    int a[n]; 
    vector<int>zero;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(!a[i])zero.push_back(i);
    }
    int cnt0=0, l=0, best=0, start=-1 , end=-1;
    for(int i=0, j=0; i<n ;i++){
        if (!a[i])
            cnt0++;
        if(cnt0 <=k && (i-l+1) > best){
            best = i-l+1;
            start=l;
            end=i;
        }
        else if(cnt0>k){
            l=zero[j++]+1;
            //cout << l <<en;
            cnt0--;
        }
    }   
    cout <<best<<en;
    for(int i=0; i<n; i++){
        if(i>=start && i<=end)cout <<"1 ";
        else cout << a[i] << " ";
    }
    return 0;
}