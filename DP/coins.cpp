/*

Given coins[]={...,...,...}
make amount with min coins.

*/

#include<bits/stdc++.h>
using namespace std;

int minCoins(int *coins,int amount,int n){
	if(amount==0)
		return 0;

	int ans=INT_MAX;
	for(int i=0;i<=n;i++){
		if(amount-coins[i]>=0){
			int smallerAns = minCoins(coins,amount-coins[i],n);
			if(smallerAns!=INT_MAX)
				ans=min(ans,smallerAns+1);
		}
	}
	return ans;

}
int main(){

	int us_coins[]={1,7,10};
	int amount = 39;
	// cout<<minCoins(coins,amount,3)<<endl;

	int indian_coins[]={1,2,5,10,20};
	int rupees = 13;
	cout<<minCoins(indian_coins,rupees,5)<<endl;


}