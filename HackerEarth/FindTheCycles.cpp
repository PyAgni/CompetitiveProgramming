#include<bits/stdc++.h>
using namespace std;

vector<int> ar[200001];
int vis[200001];

bool dfs(int node, int parent){
	vis[node]++;
	if(ar[node].size()!=2)
		return false;
	for(int child : ar[node]){
		if(!vis[child] && ar[child].size()==2){
			if(dfs(child,node)==true)
				return true;
		}
		else if(child!=parent && ar[child].size()==2)
			return true;
	}
	return false;
}

int main(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	int ctr=0;
	for(int i=1;i<=n;i++){
		
		if(!vis[i] && ar[i].size()==2){
			if(dfs(i,-1))
				ctr++;
		}
	}
	cout<<ctr;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=ar[i].size();j++){
	// 		cout<<ar[i][j]<<"->";
	// 	}
	// 	cout<<"\n";
	// }
	// for(int i=0;i<=n;i++)
	// 	cout<<ar[i].size();
}
