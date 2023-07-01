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
    
    ll n,k,sum=0;
    cin >>n>>k;
    priority_queue <ll>pq;
    for (int i=0; i<n; i++){
        ll x;
        cin >>x;
        pq.push(x);
    }
    if (n==1){
        ll x1=pq.top();
        pq.pop();
        ll per=x1/k;
        ll ans=(per*(per+1))-x1;
        sum=ans*pow(per,2);
        sum+=(k-ans)*(pow((per+1),2));
    }
    for (int i=1; i<=(k-n); i++){
        ll x=pq.top();
        pq.pop();
        pq.push(x1);
        pq.push(x2);
    }
    while(!pq.empty()){
        ll x=pq.top();
        pq.pop();
        sum+=(x*x);
    }
    cout <<sum<<endl;
    return 0;
}