#include<bits/stdc++.h>
using namespace std;

// recursive

int knapsack(int *weights,int *profits,int weight,int n){
	if(n==0||weight==0)
		return 0;
	
	if(weights[n-1]<=weight)
		return max(profits[n-1]+knapsack(weights,profits,weight-weights[n-1],n-1),knapsack(weights,profits,weight,n-1));

	else if(weights[n-1]>weight)
		return knapsack(weights,profits,weight,n-1);
}

// recursive + memoization
//dp[max_n+1][max_weight+1];

int dp[10001][10001]={-1};
// memset(dp,-1,sizeof(dp));

int knapsackMemo(int *weights,int *profits,int weight,int n){
	if(n==0||weight==0)
		return 0;
	
	if(dp[n][weight]!=-1)
		return dp[n][weight];

	if(weights[n-1]<=weight)
		return dp[n][weight] = max(profits[n-1]+knapsack(weights,profits,weight-weights[n-1],n-1),knapsack(weights,profits,weight,n-1));

	else if(weights[n-1]>weight)
		return dp[n][weight] = knapsack(weights,profits,weight,n-1);
}

//Bottom-Up dp

int knapsackBottomUp(int *weights,int *profits,int W,int n){
	int dp[n+1][W+1];
	// Initialization
	for(int i=0;i<n+1;i++)
		for(int j=0;j<W+1;j++)
			if(i==0||j==0)
				dp[i][j]=0;

	for(int i=1;i<n+1;i++)
		for(int j=1;j<W+1;j++){
			if(weights[i-1]<=j){
				dp[i][j]=max(profits[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
			}
			else
				dp[i][j] = dp[i-1][j];
		}

	return dp[n][W];
}

int main(){
	int max_weight;
	cin>>max_weight;
	int n;
	cin>>n;
	int weight[n],profits[n];
	for(int i=0;i<n;i++) cin>>weight[i];
	for(int i=0;i<n;i++) cin>>profits[i];


	cout<<knapsackBottomUp(weight,profits,max_weight,n);
}