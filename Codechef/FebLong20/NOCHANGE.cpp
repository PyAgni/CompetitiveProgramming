	#include<bits/stdc++.h>
	using namespace std;



	int main(){

		int t;
		cin>>t;
		while(t--){
			long long int p,n;
			cin>>n>>p;
			long long int d[n],sum=0;
			for(int i=0;i<n;i++)
				{
					cin>>d[i];
					sum+=d[i];
				}

			// sort(d,d+n);
			int ctr=0,idx;
			for(int i=0;i<n;i++){
				if(p%d[i]==0)
				{
					ctr++;
				}
				else{
					idx=i;
					// break;
				}
			}
			// cout<<ctr<<"12222\n";
			
			if(ctr==n){
				if(sum>p){
					bool f=true;
					int idx1=-1;
					for(int i=0;i<n;i++){
						if(sum-d[i]>p)
						{
							f=false;
							idx1=i;
							// break;
						}
					}
					if(f){
						cout<<"YES ";
						for(int i=0;i<n;i++)
							cout<<"1 ";
						cout<<"\n";
						continue;
					}
					else{
						cout<<"NO\n";
						continue;
					}
				}
				else{
					cout<<"NO\n";
					continue;
				}
			}

			long long int ans[n];
			vector<long long int> v;
			memset(ans,0,sizeof(ans));
			// long long int 
			for(int i=0;i<n;i++){
				if(i!=idx){
					v.push_back(0);
				}
				else{
					long long int temp = p/d[idx] + 1;
					v.push_back(temp);
				}
			}
			cout<<"YES ";
			for (int i = 0; i < n; i++)
			{
				cout<<v[i]<<" ";
			}
			cout<<"\n";


		}
			
	}
