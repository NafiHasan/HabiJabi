#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int a,b,c;
    cin >>a>>b>>c;
    int sum=0;
    if (a>=500){
        sum+=a-100;
        if (b<500 || c<500){
            b+=c;
            sum+=b;
            if (b>=500)sum-=100;
        }
        else if (b>=500){
            sum+=b-100;
            sum+=c;
            if (c>=500)sum-=100;
        }
    }
    else if (b >= 500)
    {
        sum += b - 100;
        if (a < 500 || c < 500)
        {
            a += c;
            sum+=a;
            if (a >= 500)
                sum -= 100;
        }
        else if (a >= 500)
        {
            sum += a - 100;
            sum += c;
            if (c >= 500)
                sum -= 100;
        }
    }
    else if (c >= 500)
    {
        sum += c - 100;
        if (b < 500 || a < 500)
        {
            b += a;
            sum+=b;
            if (b >= 500)
                sum -= 100;
        }
        else if (b >= 500)
        {
            sum += b - 100;
            sum += a;
            if (a >= 500)
                sum -= 100;
        }
    }
    else {
        sum = a + b + c;
        if (sum>=500)sum-=100;
    }
    cout <<sum<<en;
    return 0;
}