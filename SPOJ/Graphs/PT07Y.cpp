#include<bits/stdc++.h>
using namespace std;

vector<int> ar[10001];
int vis[10001];

void dfs(int node){
	vis[node]=1;
	for(int child : ar[node]){
		if(!vis[child])
			dfs(child);
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}

	int cc=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0)
			dfs(i),cc++;
	}

	if(cc==1 && m==n-1)
		cout<<"YES";
	else
		cout<<"NO";
}
