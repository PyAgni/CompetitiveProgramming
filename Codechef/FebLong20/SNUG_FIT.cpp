#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];

		sort(a,a+n);
		sort(b,b+n);
		long long int ans=0;
		for(int i=0;i<n;i++){
			ans+=min(a[i],b[i]);
		}
		cout<<ans<<endl;


}
}