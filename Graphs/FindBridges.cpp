#include<bits/stdc++.h>
using namespace std;

vector<int > ar[100001];
int vis[100001],in[100001],low[100001];
int timer=1;

void dfs(int node,int parent=-1){
	vis[node]++;
	in[node]=low[node]=timer++;
	// timer++;

	for(int child : ar[node]){
		if(child == parent) continue;

		if(vis[child])
			low[node]=min(in[child],low[node]);
		else{
			dfs(child,node);
			low[node] = min(low[node],low[child]);
			if(low[child]>in[node]){
							//Bridge found b/w node-child
				cout<<"Bridge b/w"<<child<<"->"<<node<<endl;
			}
		}
	}
}

int main(){

/*
5 5
1 2
2 3
3 4
4 5
3 5
*/

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}

	dfs(1);
}