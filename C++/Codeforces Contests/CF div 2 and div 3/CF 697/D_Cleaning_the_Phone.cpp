#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n;
        ll m;
        cin >>n>>m;
        int a[n],b[n];
        ll ans=0,all=0;
        priority_queue<int>q1,q2;
        for(int i=0; i<n; i++)cin>>a[i];
        for(int i=0; i<n; i++){
            cin >> b[i];
            if (b[i]==1)q1.push(a[i]);
            else q2.push(a[i]);
            ans+=b[i];
        }
        all=ans;
        ll cnt=0;
        while(q1.size() && q2.size() && cnt<m){
            int top11=q1.top(),top12=-1;
            q1.pop();
            if (q1.size()){
                top12 = q1.top();
                q1.pop();
            }
            int top2=q2.top();
            q2.pop();
            if (top11 >=top2){
                cnt+=top11;
                q2.push(top2);
                ans--;
            }
            else if (top12 >= top2){
                cnt+=top12;
                q1.push(top2);
                ans--;
            }
            else if ((ll)top11 + cnt >= m)
            {
                cnt += (top11);
                q2.push(top2);
                ans--;
            }
            else if ((ll)top12 + cnt >= m)
            {
                cnt += (top12);
                q2.push(top2);
                ans--;
            }
            else if (top11 + top12 >top2){
                cnt+=top11+top12;
                q2.push(top2);ans-=2;
            }
            else {
                cnt+=top2;
                q1.push(top12);
                q1.push(top11);
                ans-=2;
            }
        }
        while (cnt<m && q1.size()){
            cnt+=q1.top();
            q1.pop();
            ans--;
        }
        while (cnt<m && q2.size()){
            cnt+=q2.top();
            q2.pop();
            ans-=2;
        }
        if (cnt>=m)cout <<all-ans<<en;
        else cout <<"-1\n";
    }
    return 0;
}