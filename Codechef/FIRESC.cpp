#include<bits/stdc++.h>
using namespace std;

vector<int> ar[100001];
int vis[100001],cc_size;

void dfs(int node){
	vis[node]++;
	cc_size++;
	for(int child : ar[node]){
		if(!vis[child])
			dfs(child);
	}

}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			// cc_size=0;
			ar[i].clear();
		}
		while(m--){
			int a,b;
			cin>>a>>b;
			ar[a].push_back(b);
			ar[b].push_back(a);
		}
		int cc=0;
		long long int n_ways=1;
		for(int i=1;i<=n;i++){
			
			if(!vis[i])
				{
					cc_size=0;
					dfs(i);
					cc++;
					n_ways=((n_ways*cc_size)%1000000007);
				}
			
		}

		cout<<cc<<" "<<n_ways<<"\n";


	}
}