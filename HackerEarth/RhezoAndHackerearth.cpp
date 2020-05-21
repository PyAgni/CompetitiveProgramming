#include<bits/stdc++.h>
using namespace std;

vector<int > ar[100001];
int vis[100001],in[100001],low[100001],parent[100001];
int timer=1;

set<pair<int,int> > vpr;

void dfs(int node,int p=-1){
	vis[node]++;
	in[node]=low[node]=timer++;

	for(int child : ar[node]){
		if(child == p)
			continue;
		if(vis[child])
			low[node]= min(low[node],in[child]);
		else{
			dfs(child,node);
			low[node]=min(low[node],low[child]);
			if(low[child]>in[node]){
				vpr.insert(make_pair(child,node));
				vpr.insert(make_pair(node,child));
				cout<<"Bridge b/w"<<child<<"->"<<node<<endl;

		}
			}
	}
}

int main(){

	int n,m;
	cin>>n>>m;
	// vector<pair<int,int> > vpr;
	int aa[100001],bb[100001];
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		// vpr.push_back(make_pair(a,b));
		aa[i]=a;
		bb[i]=b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}

	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);

	int q;
	cin>>q;
	while(q--){
		int z;
		cin>>z;
		if(vpr.find(make_pair(aa[z],bb[z]))!=vpr.end())
			cout<<"Unhappy\n";
		else cout<<"Happy\n";
	}

}