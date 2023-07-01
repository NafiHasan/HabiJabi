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
        cin >>n;
        int a[n];
        int sum=0, cnt1=0, cnt2=0;
        for (int i=0; i<n; i++){
            cin >>a[i];
            sum+=a[i];
            if (a[i]==1)cnt1++;
            else cnt2++;
        }
        if (sum%2==1)cout <<"no\n";
        else {
            sum/=2;
            sort (a,a+n);
            int cnt=0;
            bool ans=false;
            if (sum%2==1){
                if (cnt1 >= sum)
                    ans = true;
                else if (cnt1>0){
                    sum--;
                    cnt1--;
                    while(cnt1){
                        if (cnt2*2>=sum){
                            ans = true;
                            break;
                        }
                        else if (cnt1>1){
                            cnt1-=2;
                            sum-=2;
                            if (cnt2*2>=sum)ans=true;
                        }
                        else break;
                    }
                }
            }
            else {
                if (cnt1>=sum)ans=true;
                if (cnt2*2>=sum)ans=true;
                else {
                    sum-=cnt*2;
                    if (cnt1 >=sum)ans=true;
                }
            }
            if (ans)cout <<"yes\n";
            else cout <<"no\n";
        }
    }
    return 0;
}