#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;

ll ways(ll n,ll *dp){
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	if(dp[n]!=-1)
		return dp[n];
	return dp[n] = (ways(n-1,dp)+ways(n-2,dp)+ways(n-3,dp)+ways(n-4,dp)+ways(n-5,dp)+ways(n-6,dp))%mod;
}



int main(){
	ll n;
	cin>>n;
	ll dp[n+1];
	memset(dp,-1,sizeof(dp));
	cout<<ways(n,dp)<<endl;
}