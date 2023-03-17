#include <bits/stdc++.h>
using namespace std;
 
#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"
 
 
int main ()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int ara[n];
    for (int i=0; i<n; i++)scanf("%d",&ara[i]);
    map<int,int>m1;
    int start=0,end=0,best=k,bestend=0,beststart=0;
    for (int i=0; m1.size()<=k,i<n; i++){
        if (m1.size()==k && ara[i]!=ara[i-1])break;
        m1[ara[i]]++;
        end=i;
    }
    //cout <<end<<endl;
    if ((end-start+1) >=best && end<n){
        best=(end-start+1);
        bestend=end;
        beststart=start;
    }
    //cout <<end<<endl;
    while(end<n && start<n){
        //cout <<"start= "<<start<<"end= "<<end<<endl;
        end++;
        if (end>=n)break;
        m1[ara[end]]++;
        //cout <<m1[ara[end]]<<endl;
        if (m1[ara[end]]>1){
            while(m1[ara[end]]>1 && end<n){
                if ((end-start+1) >=best && end<n){
                    best=(end-start+1);
                    bestend=end;
                    beststart=start;
                }
                end++;
                if (end<n)m1[ara[end]]++;
            }
            m1[ara[end]]--;
            end--;
        }
        if ((end-k+1)==1){
            m1[ara[start]]--;
            start++;
        }
        while(start<(end-k+1)){
            m1[ara[start]]--;
            start++;
        }
        //cout <<start<<endl;
        if (best==n)break;       
    }
    printf("%d %d\n",beststart+1,bestend+1);
    return 0;
}