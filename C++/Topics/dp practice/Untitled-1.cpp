#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000; //Maximum number of coins will be 1000.
const int MAXS = 1000; //Maximum sum S for which answer needs to be calculated will also be 1000.
int N,S;
int V[MAXN];
int dp[MAXS];
/*This is our recusive function*/
int rec(int s)/*The state of the dp will go within ()*/
{
	//Base Cases
	for(int i=0; i<N; i++)
	if(V[i]==s)return 1;
	/*We first check whether dp[s] is already computed or not before. If computed we do not recompute
	again. We simple return the answer stored.
	How do we know whether dp[s] is computed or not? We initialize dp[i] for i=1 to S to -1.
	If the value is -1 we know that we have to compute dp[s], else we can simple return the computed 
	value*/
	if(dp[s]!=-1)return dp[s];
	dp[s]=INT_MAX;
	/*Recursive case*/
	for(int i=0; i<N; i++)
	{
		if(V[i]<=s)
		dp[s]=min(dp[s],1+rec(s-V[i]));
	}
	return dp[s];
}
int main() {
	cin>>N>>S;
	//Accepting the N coins
	for(int i=0; i<N; i++)cin>>V[i];
	for(int i=0 ;i<=S; i++)dp[i]=-1;
	cout<<rec(S)<<endl;
	return 0;
}