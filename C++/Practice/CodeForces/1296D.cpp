#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n,a,b,k,cnt=0;
    cin >>n>>a>>b>>k;
    int ara[n];
    vector<int>v;
    for (int i=0; i<n; i++){
        cin >> ara[i];
        if (ara[i]<=a)cnt++;
        else if (ara[i]%(a+b)<=a && ara[i]%(a+b)!=0)cnt++;
        else if (ara[i]%(a+b)>a){
            int aa=ara[i]%(a+b);
            aa-=a;
            int p;
            if (aa%a==0)p=aa/a;
            else p=aa/a+1;
            v.push_back(p);
        }
        else if (ara[i]%(a+b) ==0){
            int p=b/a;
            if (b%a!=0)p++;
            v.push_back(p);
        }
    }   
    sort (v.begin(),v.end());
    //for (int i=0; i<v.size(); i++)cout <<v[i]<<" ";
    for (int i=0; i<v.size(); i++){
        if (v[i]<=k && k>0){
            cnt++;
            k-=v[i];
        }
    }
    cout <<cnt<<en;
    return 0;
}