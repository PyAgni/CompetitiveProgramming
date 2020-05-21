#include<bits/stdc++.h>
using namespace std;

vector<int> ar1[1000001],ar2[1000001];
int vis1[1000001],vis2[1000001];
int cc[1000001],curr_cc;

bool dfs(int node){
	vis1[node]++;
	// vis2[node]++;
	cc[node]=curr_cc;

	for(int child: ar1[node]){
		if(!vis1[child]){
			dfs(child);
		}
	}
}

int main(){

	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;


		for(int i=1;i<=n;i++)
			ar1[i].clear(),vis1[i]=0;

		vector<pair<int , int> > vpr;


		while(k--){
			int a,b;
			string r;
			cin>>a>>r>>b;

			if(r=="=")
				ar1[a].push_back(b),ar1[b].push_back(a);
			else
				vpr.push_back(make_pair(a,b));
		}
		curr_cc=0;
		for(int i=1;i<=n;i++){
			if(!vis1[i]){
				curr_cc++;
				dfs(i);
			}
		}

		bool f=true;
		for(int i=0;i<vpr.size();i++){
			if(cc[vpr[i].first] == cc[vpr[i].second])
				{
					f=false;
					break;
				}
		}

		if(f)
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}

}