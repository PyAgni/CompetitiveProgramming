#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int t;
	cin>>t;
	while(t--){
		// set<int> st;
		int n,sum=0;
		cin>>n;
		int arr[n];
		int odd=0,even=0;
		for(int i=0;i<n;i++) {
			cin>>arr[i];
			if(arr[i]&1) odd++;
			else even++;
			// st.insert(arr[i]);
			sum+=arr[i];
		}
		if(sum&1){
			cout<<"YES\n";
			// continue;
		}
		else{
			if(!odd){
				cout<<"NO\n";
		}
		if(odd){
			if(even){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";
			}
		}
		// set<int>::iterator=st.begin();

		// for(int i=0;i<st.end();i++){
		// 	if(sum+())
		// }

	}

}
}