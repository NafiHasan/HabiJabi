#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

vector<int> a(100005);
ll s[100005];
vector<ll> v;

void sum(int i, int j, int n){
    if (i == j)
        return;
    int val=(i+j)/2;
    int lo=lower_bound(a.begin(), a.begin()+n, i)-a.begin();
    int hi=upper_bound(a.begin(), a.begin()+n, j)-a.begin();
    int mid=upper_bound(a.begin(), a.begin()+n, val)-a.begin();
    //cout <<lo<<" "<<mid<<" "<<hi<<" "<<s[mid]<<" "<< s[lo] <<" "<<s[hi]<<"\n";
    v.push_back(s[mid] - s[lo]);
    v.push_back(s[hi]-s[lo]);
    v.push_back(s[hi]-s[mid]);
    // if (lo!=mid && a[lo]==a[mid-1])return;
    sum(a[lo], a[mid-1], n);
    sum(a[mid], a[hi-1], n);
}
int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n,q;
        cin>>n>>q;
        v.clear();
        memset(s,0,sizeof(s));
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(),a.begin()+n);
        s[0]=0;
        for (int i = 1; i <= n; i++)s[i]=a[i-1];
        for (int i = 1; i <= n; i++)
            s[i] += s[i - 1];
        sum(a[0], a[n-1], n);
        v.push_back(s[n]);
        sort(v.begin(), v.end());
        //for(int i=0; i<v.size() ; i++)cout <<v[i]<<" ";
        //cout <<en;
        for(int i=0; i<q; i++){
            int x;
            cin >>x;
            bool found=false;
            int lo=0,hi=v.size()-1,mid;
            while(lo<=hi){
                mid=(lo+hi)/2;
                if (v[mid]==x){
                    found = true;
                    break;
                }
                else if (v[mid]>x)hi=mid-1;
                else lo=mid+1;
            }
            if(found)cout <<"Yes\n";
            else cout << "No\n";
        }
    }   
    return 0;
}