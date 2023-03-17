#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

double area(double a , double b, double c){
    double s=(a+b+c)/2.0;
    return (double)sqrt(s*(s-a)*(s-b)*(s-c));
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        double ara[n];
        for (int i=0 ; i <n ; i++) cin >>ara[i];
        sort (ara,ara+n);
        double ans=DBL_MAX;
        bool found =false;
        for(int i=0; i<n; i++){
            for(int j=i+1, k=j+1; j<n-1 && k<n ; j++,k=max(k,j+1)){
                while(k<n-1  && ara[i]+ara[j] > ara[k+1]) k++;
                if (ara[i] + ara[j] > ara[k] && k<n){
                    ans = min(ans, area(ara[i], ara[j], ara[k]));
                    found = 1;
                    //cout <<ara[i]<<" "<<ara[j]<<" "<<ara[k]<<en;
                }
                //if (ara[i]+ara[j] > ara[j+1])ans=min(ans,area(ara[i],ara[j],ara[j+1]));
            }
        }
        if(found) cout <<fixed<<setprecision(10)<<ans<<en;
        else cout << "-1\n";
    }   
    return 0;
}