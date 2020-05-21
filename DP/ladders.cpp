/* N steps
Step size - 1,2 or 3
Find total ways to reach Nth step!

*/

#include<bits/stdc++.h>
using namespace std;


int steps(int n){
	if(n==1||n==2)
		return n;
	if(n==3)
		return 4;
	return steps(n-1)+steps(n-2)+steps(n-3);
}

int stepsMemo(int n,int *dp){
	if(n==1||n==2)
		return n;
	if(n==3)
		return 4;
	if(dp[n])
		return dp[n];
	else
	{
		dp[n] = stepsMemo(n-1,dp)+stepsMemo(n-2,dp)+stepsMemo(n-3,dp);
		return dp[n];
	}
}

long long int stepsBottomUp(long long int n){
	long long int dp[n+1];
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;

	if(n<4)
		return dp[n];

	for(long long int i=4;i<=n;i++)
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	return dp[n];
}

int main(){
	int *dp = new int[100000];
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	// cout<<steps(35)<<endl;
	cout<<stepsMemo(50,dp)<<endl;
	cout<<stepsBottomUp(100)<<endl;
}
