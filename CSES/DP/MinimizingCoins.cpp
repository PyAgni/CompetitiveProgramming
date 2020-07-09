#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;


ll solve(ll sum,ll *arr,ll n){
	if(sum==0)
		return 1;
	if(sum<0)
		return 0;
	ll ways=0;
	for(int i=0;i<n;i++){
		ways+=solve(sum-arr[i],arr,n);
	}
	return ways;
}

int main(){
	ll n,x;
	cin>>n>>x;
	ll c[n];
	// for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<n;i++)
		c[i]=i+1;

	ll dp[x+1];
	for(int i=1;i<=x;i++) dp[i]=1e9;
		// vector<int> dp(x+1,INT_MAX);
	// for(int i=0;i<n;i++) cout<<dp[i];
	dp[0]=0;

	for(int i=1;i<=x;i++){
		for(int j=0;j<n;j++){
			if(i-c[j]>=0){
				// cout<<dp[i]<<" ";
				dp[i]=(min(dp[i],dp[i-c[j]]+1))%(ll)(1e9+7);
			}
		}
	}

	// cout<<(solve(x,c,n));
	cout<<(dp[x]==1e9? -1:dp[x]);


}