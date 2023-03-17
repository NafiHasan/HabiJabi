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
    
    int n,k;
    cin >>n>>k;
    ll ara[k];
    for (int i=0; i<k; i++)cin >>ara[i];
    if (n==k){
        cout << *min_element(ara,ara+n)<<en;
        return 0;
    }
    sort (ara,ara+k);
    double sum=0,ans;
    for (int i=0; i<k-1; i++){
        if (i<(k-n)){
            sum+=(double)ara[i];
        }
        if (i>=(k-n)){
            sum+=(double)ara[i];
            if ((double)sum / (double)(i - (k - n) + 1) <= (double)ara[i + 1])
            {
                ans = sum / (double)(i - (k - n) + 1);
                printf("%.6lf\n",ans);
                return 0;
            }
            else if ((double)sum / (double)(i-(k-n)+1) > (double)ara[i + 1] && i==k-1){
                ans = sum + (double)ara[i + 1] / (double)(i - (k - n) + 2);
                printf("%.6lf\n", ans);
                return 0;
            }
            // else {
            //     double ans = sum + (double)ara[i + 1] / (double)(i - (k - n) + 2);
            //     printf("%.6lf\n", ans);
            //     return 0;
            // }
        }
    }
    sum+=(double)ara[k-1];
    ans=sum/(double)n;
    printf("%.6lf\n",ans);
    return 0;
}