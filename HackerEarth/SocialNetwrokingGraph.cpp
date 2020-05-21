#include<bits/stdc++.h>
using namespace std;

#define pb push_back

int vis[1000001],dist[1000001];
vector<int> ar[1000001];


void bfs(int node){
	vis[node]++;
	queue<int> q;
	q.push(node);
	dist[node]=0;

	while(!q.empty()){
		int curr=q.front();
		q.pop();

		for(int child : ar[curr]){
			if(!vis[child]){
				q.push(child);
				dist[child]=dist[curr]+1;
				vis[child]++;
			}

		}
	}
}

int main(){

	int n,e,m;
	cin>>n>>e;

	while(e--){
		int u,v;
		cin>>u>>v;

		ar[u].pb(v);
		ar[v].pb(u);
	}
	
	cin>>m;
	while(m--){
		int s,t;
		cin>>s>>t;

		for(int i=0;i<=n;i++)
			vis[i]=0,level[i]=0;

		bfs(s);

		int ctr=0;
		for(int i=0;i<=n;i++)
		{
			if(dist[i]==t)
				ctr++;
		}

		cout<<ctr<<endl;

	}


}