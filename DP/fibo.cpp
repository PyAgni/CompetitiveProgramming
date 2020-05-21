#include<bits/stdc++.h>
using namespace std;


int fib(int n){
	if(n==0||n==1)
		return n;
	return fib(n-1)+fib(n-2);
}

int fibMemo(int n ,int *memo){
	if(n==0||n==1)
		return n;
	if(!memo[n])
	{
		int f=fibMemo(n-1,memo)+fibMemo(n-2,memo);
		memo[n]=f;
		return f;
	}
	return memo[n];
}

int fibBottomUp(int n){
	int dp[n+1]={0};
	dp[0]=0,dp[1]=1;
	for(int i=2;i<=n;i++)
		dp[i]=dp[i-1]+dp[i-2];
	return dp[n];
}

int main(){
	int memo[1000000]={0};
	memo[0]=0; 
	memo[1]=1;
	cout<<fib(42)<<endl;
	cout<<fibMemo(42,memo)<<endl;
	cout<<fibBottomUp(42)<<endl;


}