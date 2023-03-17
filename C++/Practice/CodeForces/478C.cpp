#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    string s;
    s = "fsfsef";
    long long lo = 0, hi = 1e15, mid;
    while(lo <= hi){
        mid = (lo + hi)/2;
        bool pos = 0;
        long long tmp[] = {a[0], a[1], a[2]};
        long long f = mid, s = mid, t = mid;
        long long cut = min(f, tmp[2]);
        tmp[2] -= cut;
        f -= cut;
        cut = min(s, tmp[2]);
        tmp[2] -= cut;
        s -= cut;
        cut = min(s, tmp[1]);
        s -= cut;
        tmp[1] -= cut;
        cut = min(t, tmp[1]);
        t -= cut;
        tmp[1] -= cut;
        cut = min(t, tmp[0]);
        tmp[0] -= cut;
        t -= cut;
        if(s ==0 && f == 0 && t == 0){
            pos = 1;
        }
        if(pos){
            ans = max(ans, mid);
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    cout << ans << '\n';
}