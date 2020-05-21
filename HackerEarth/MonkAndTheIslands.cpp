#include<bits/stdc++.h>
using namespace std;

vector<int> ar[10001];
int vis[10001],dist[10001];

void bfs(int node){
	vis[node]++;

	queue<int> q;
	q.push(node);
	dist[node]=0;

	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(int child : ar[curr]){
			if(!vis[child]){
				q.push(child);
				vis[child]++;
				dist[child] = dist[curr] + 1;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			ar[i].clear(),vis[i]=0;
		while(m--){
			int a,b;
			cin>>a>>b;
			ar[a].push_back(b);
			ar[b].push_back(a);
		}

		bfs(1);
		for(int i=1;i<=n;i++)
			cout<<dist[i]<<" ";
		cout<<endl;
	}
}