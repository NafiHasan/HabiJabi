#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

bool pchk(int n){
    if (n&(n-1)==0)return true;
    else return false;
}

int step(int n){
    int cnt = 1;
    while (1)
    {
        if (n == 1)
            return cnt;
        else if (pchk(n)==true){
            cnt+=(log2(n));
            return cnt;
        }
        else if (n % 2 == 0)
        {
            cnt++;
            n /= 2;
        }
        else
        {
            n *= 3;
            n++;
            cnt++;
        }
    }
    return cnt;
}
int ara[1000000];
int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int l,r;
    while (scanf("%d %d",&l,&r)!=EOF)
    {
        int best=0;
        if (l<=r){
        for (int i=l; i<=r; i++){
            if (ara[i]!=0)best=max(best,ara[i]);
            else {
                best=max(best,step(i));
                ara[i]=step(i);
            }
        }
        cout << l << " " << r << " " << best << en;
        }
        else {
            for (int i = r; i <= l; i++)
            {
                if (ara[i] != 0)
                    best = max(best, ara[i]);
                else
                {
                    best = max(best, step(i));
                    ara[i] = step(i);
                }
            }
            cout << l << " " << r << " " << best << en;
        }
    }
    return 0;
}