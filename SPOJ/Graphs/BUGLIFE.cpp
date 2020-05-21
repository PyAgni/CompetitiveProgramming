#include<bits/stdc++.h>
using namespace std;

std::vector<int> ar[2001];
int vis[2001],clr[2001];

bool dfs(int node, int color){
	vis[node]=1;
	clr[node]=color;

	for(int child : ar[node]){
		if(!vis[child]){
			if(dfs(child,!color)==false)
				return false;
		}
		else if(clr[child]==clr[node])
				return false;
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long int n,m;
		cin>>n>>m;
		for(int k=1;k<=n;k++)
			ar[k].clear();
		memset(vis,0,sizeof(vis));
		while(m--){
			int a,b;
			cin>>a>>b;
			ar[b].push_back(a);
			ar[a].push_back(b);
		}
		bool f=true;
		for(int z=1;z<=n;z++){

			if(!vis[z]){
				if(dfs(z,0)==false)
					f=false;
			}
		}

		if(!f)
			cout<<"Scenario #"<<i<<":\nSuspicious bugs found!\n";
		else
			cout<<"Scenario #"<<i<<":\nNo suspicious bugs found!\n";

		// for(int k=1;k<=n;k++)
		// 	cout<<clr[k]<<" ";
		
		// memset(clr,0,sizeof(clr));

	}
}