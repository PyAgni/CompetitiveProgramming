#include<bits/stdc++.h>

using namespace std;
vector<int> ar[10001];
int vis[10001],dist[10001];

void dfs(int node, int distance){
	vis[node]++;
	dist[node]=distance;
	for(int child : ar[node]){
		if(!vis[child])
			dfs(child,distance+1);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}

	int max_i,maxx=-1;

	dfs(1,0);
	for(int i=1;i<=n;i++)
		{
			// cout<<dist[i]<<" ";
			if(dist[i]>maxx)
				maxx=dist[i],max_i=i;

		}
	memset(vis,0,sizeof(vis));
	memset(dist,0,sizeof(dist));

	dfs(max_i,0);

	for(int i=1;i<=n;i++)
		{
			// cout<<dist[i]<<" ";
			if(dist[i]>maxx)
				maxx=dist[i];
		}
	
	cout<<maxx;

}