#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"

const ll B=1e9+7;
ll npr(ll n,ll p){
    ll sum=1;
    for (int i=n; i>(n-p); i--){
        sum*=i;
        sum%=B;
    }
    return sum;
}
ll fact(ll n){
    ll sum=1;
    for (int i=2; i<=n; i++){
        sum*=i;
        sum%=B;
    }
    return sum;
}


bool bin(vector<int>v,int val){
    int left =0,cntsmall=0,cntbig=0;
    int right=v.size();
    while(left<right){
        int middle=(left+right)/2;
        if (v[middle]<=val){
            left = middle + 1;
            cntsmall++;
        }
        else {
            right = middle;
            cntbig++;
        }
    }
    
    if (left>0 && v[left-1]==val)return true;
    else return false;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n,val,pos,big=0,small=0;
    cin >>n>>val>>pos;
    ll lo=0,hi=n-1,mid;
    while(lo<hi){
        mid=(lo+hi)/2;
        if (mid<=val){
            small++;
            lo=mid+1;
            if (val==mid)break;
        }
        else {
            big++;
            hi=mid;
        }
    }
    ll num = npr((n-val),big);
    num%=B;
    num*=(npr((n-1),small)%B);
    num %= B;
    num*=(fact(n-small-big-1)%B);
    num%=B;
    cout <<num<<endl;
    return 0;
}