#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int t;
	cin>>t;
	while(t--){
		long long int n,k;
		cin>>n>>k;
		long long int a[n],sum=0;
		for(int i=0;i<n;i++)
			{
				cin>>a[i];
				sum+=a[i];
			}
		cout<<sum%k<<endl;

		


}
}